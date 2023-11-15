#pragma once
#include "misc.h"


template <typename T>
class b_tree
{
private:

    class node
    {
        std::vector<std::string> keys;
        std::vector<T> vals;
        size_t t;
        std::vector<node*> arr;
        size_t size;
        bool leaf;

    public:
        node();

        node(size_t t, bool leaf)
        {
            this->t = t;
            this->leaf = leaf;

            this->keys = std::vector<std::string>(2 * t - 1);
            this->arr = std::vector<node*>(2 * t);
            this->size = 0;
        }

        size_t find(std::string k) 
        {
            size_t idx = 0;
            while (idx < this->size and this->keys[idx] < k)
                ++idx;
            return idx;
        }

        void deletion(std::string key)
        {
            size_t idx = this->find(key);

            if (idx < this->size and this->keys[idx] == key)
            {
                if (this->leaf)
                    this->removeFromLeaf(idx);
                else
                    this->removeFromNonLeaf(idx);
            }
            else 
            {
                if (this->leaf) 
                {
                    return;
                }

                bool flag = ((idx == this->n) ? true : false);

                if (this->arr[idx]->size < this->t)
                    this->fill(idx);

                if (flag and idx > this->size)
                    this->arr[idx - 1]->deletion(key);
                else
                    this->arr[idx]->deletion(key);
            }
            return;
        }

        void removeFromLeaf(size_t idx)
        {
            for (size_t i = idx + 1; i < this->size; ++i)
                this->keys[i - 1] = this->keys[i];

            this->size--;

            return;
        }

        void removeFromNonLeaf(size_t idx)
        {
            size_t k = this->keys[idx];

            if (this->arr[idx]->size >= this->t)
            {
                size_t pred = this->getPredecessor(idx);
                this->keys[idx] = pred;
                this->arr[idx]->deletion(pred);
            }

            else if (this->arr[idx + 1]->size >= this->t)
            {
                size_t succ = this->getSuccessor(idx);
                this->keys[idx] = succ;
                this->arr[idx + 1]->deletion(succ);
            }
            else
            {
                this->merge(idx);
                this->arr[idx]->deletion(k);
            }
            return;
        }

        size_t getPredecessor(size_t idx)
        {
            node* cur = this->arr[idx];
            while (!cur->leaf)
                cur = cur->arr[cur->size];

            return cur->keys[cur->size - 1];
        }

        size_t getSuccessor(size_t idx)
        {
            node* cur = this->arr[idx + 1];
            while (!cur->leaf)
                cur = cur->arr[0];

            return cur->keys[0];
        }

        void fill(size_t idx)
        {
            if (idx != 0 and this->arr[idx - 1]->size >= this->t)
                this->borrowFromPrev(idx);

            else if (idx != this->size and this->arr[idx + 1]->size >= this->t)
                this->borrowFromNext(idx);

            else
            {
                if (idx != this->size)
                    this->merge(idx);
                else
                    this->merge(idx - 1);
            }
            return;
        }

        void borrowFromPrev(size_t idx)
        {
            node* child = this->arr[idx];
            node* sibling = this->arr[idx - 1];

            for (int i = child->size - 1; i >= 0; --i)
                child->keys[i + 1] = child->keys[i];

            if (!child->leaf)
            {
                for (int i = child->size; i >= 0; --i)
                    child->arr[i + 1] = child->arr[i];
            }

            child->keys[0] = this->keys[idx - 1];

            if (!child->leaf)
                child->arr[0] = sibling->arr[sibling->size];

            this->keys[idx - 1] = sibling->keys[sibling->size - 1];

            child->size += 1;
            sibling->size -= 1;

            return;
        }

        void borrowFromNext(size_t idx)
        {
            node* child = this->arr[idx];
            node* sibling = this->arr[idx + 1];

            child->keys[(child->size)] = this->keys[idx];

            if (!(child->leaf))
                child->arr[(child->size) + 1] = sibling->arr[0];

            this->keys[idx] = sibling->keys[0];

            for (int i = 1; i < sibling->size; ++i)
                sibling->keys[i - 1] = sibling->keys[i];

            if (!sibling->leaf)
            {
                for (int i = 1; i <= sibling->size; ++i)
                    sibling->arr[i - 1] = sibling->arr[i];
            }

            child->size += 1;
            sibling->size -= 1;

            return;
        }

        void merge(size_t idx) 
        {
            node* child = this->arr[idx];
            node* sibling = this->arr[idx + 1];

            child->keys[this->t - 1] = this->keys[idx];

            for (int i = 0; i < sibling->size; ++i)
                child->keys[i + this->t] = sibling->keys[i];

            if (!child->leaf)
            {
                for (int i = 0; i <= sibling->size; ++i)
                    child->arr[i + this->t] = sibling->arr[i];
            }

            for (int i = idx + 1; i < this->size; ++i)
                this->keys[i - 1] = this->keys[i];

            for (int i = idx + 2; i <= this->size; ++i)
                this->arr[i - 1] = this->arr[i];

            child->size += sibling->size + 1;
            this->size--;

            delete (sibling);
            return;
        }

        void insertNonFull(std::string key, T val)
        {
            size_t i = this->size - 1;

            if (this->leaf == true)
            {
                while (i >= 0 and this->keys[i] > key)
                {
                    this->keys[i + 1] = this->keys[i];
                    i--;
                }

                this->keys[i + 1] = key;
                this->vals[i + 1] = val;
                this->size = this->size + 1;
            }
            else
            {
                while (i >= 0 and this->keys[i] > key)
                    i--;

                if (this->arr[i + 1]->size == 2 * this->t - 1)
                {
                    this->splitChild(i + 1, this->arr[i + 1]);

                    if (this->keys[i + 1] < key)
                        i++;
                }
                this->arr[i + 1]->insertNonFull(key, val);
            }
        }

        void splitChild(int i, node* y)
        {
            node* z = new node(y->t, y->leaf);
            z->size = this->t - 1;

            for (int j = 0; j < this->t - 1; j++)
                z->keys[j] = y->keys[j + this->t];

            if (y->leaf == false)
            {
                for (int j = 0; j < this->t; j++)
                    z->arr[j] = y->arr[j + this->t];
            }

            y->size = this->t - 1;

            for (int j = this->size; j >= i + 1; j--)
                this->arr[j + 1] = this->arr[j];

            this->arr[i + 1] = z;

            for (int j = this->size - 1; j >= i; j--)
                this->keys[j + 1] = this->keys[j];

            this->keys[i] = y->keys[t - 1];

            this->size = this->size + 1;
        }

        //void traverse() {
        //    size_t i;
        //    for (i = 0; i < this->size; i++)
        //    {
        //        if (this->leaf == false)
        //            this->arr[i]->traverse();
        //        cout << " " << keys[i];
        //    }

        //    if (this->leaf == false)
        //        this->arr[i]->traverse();
        //}

    };

    node* root;
    size_t t;

public:
    b_tree(size_t t)
    {
        this->root = NULL;
        this->t = t;
    }

    //void traverse()
    //{
    //    if (this->root != NULL)
    //        this->root->traverse();
    //}

    void insertion(std::string key, T val)
    {
        if (this->root == NULL)
        {
            this->root = new node(this->t, true);
            this->root->keys[0] = key;
            this->root->vals[0] = val;
            this->root->size = 1;
        }
        else
        {
            if (root->size == 2 * this->t - 1)
            {
                node* s = new node(this->t, false);

                s->arr[0] = this->root;

                s->splitChild(0, this->root);

                int i = 0;
                if (s->keys[0] < key)
                    i++;
                s->arr[i]->insertNonFull(key);

                this->root = s;
            }
            else
                this->root->insertNonFull(key);
        }
    }

    void deletion(std::string key)
    {
        if (!this->root)
        {
            return;
        }

        this->root->deletion(key);

        if (this->root->size == 0)
        {
            node* tmp = this->root;
            if (this->root->leaf)
                this->root = NULL;
            else
                this->root = root->arr[0];

            delete tmp;
        }
        return;
    }
};

