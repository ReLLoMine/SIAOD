#pragma once
#include "misc.h"

template<typename T>
class bin_search_tree
{
private:
	struct node
	{
		T val;
		std::string key;
		node* left;
		node* right;

		node(std::string key, T val)
		{
			this->val = val;
			this->key = key;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	node* root;

	void _insert(node *root, std::string key, T val)
	{
		node* tmp;

		if (root->key > key)
		{
			if (!root->left)
				root->left = new node(key, val);
			else
				_insert(root->left, key, val);
		}
		else if (root->key < key)
		{
			if (!root->right)
				root->right = new node(key, val);
			else
				_insert(root->right, key, val);
		}
	}

	node* _find(node *root, std::string key)
	{
		if (!root)
			return new node("\0", T());
		if (key == root->key)
			return root;
		if (root->key > key)
			return _find(root->left, key);
		if (root->key < key)
			return _find(root->right, key);
		return new node("\0", T());

	}

	void _max_depth(node* root, size_t *max_depth, size_t depth=0)
	{
		if (not root->left and not root->right)
		{
			if (depth > *max_depth)
				*max_depth = depth;
		}
		else
		{
			if(root->left)
				_max_depth(root->left, max_depth, depth + 1);
			if (root->right)
				_max_depth(root->right, max_depth, depth + 1);
		}
	}

	std::vector<node*> _get_level(node* root, size_t level=0, size_t cur_level=0)
	{
		std::vector <node*> data;

		if (cur_level == level)
		{
			data.push_back(root);
			return data;
		}

		std::vector <node*> tmp;
		if (root->left)
		{
			tmp = _get_level(root->left, level, cur_level + 1);
			for (auto val : tmp)
				data.push_back(val);
		}

		if (root->right)
		{
			tmp = _get_level(root->right, level, cur_level + 1);
			for (auto val : tmp)
				data.push_back(val);
		}

		return data;
	}

public:
	bin_search_tree()
	{
		this->root = nullptr;
	}

	void insert(std::string key, T val)
	{
		if (!this->root)
			this->root = new node(key, val);
		else
			this->_insert(this->root, key, val);
	}

	T& find(std::string key)
	{
		return this->_find(this->root, key)->val;
	}

	void remove(std::string key)
	{
		node* tmp = this->_find(this->root, key);
		tmp->key = "\0";
		tmp->val = T();
	}

	T& operator[](std::string key)
	{
		return this->find(key);
	}

	size_t max_depth()
	{
		size_t depth = 0;
		if (this->root)
			this->_max_depth(this->root, &depth);
		return depth;
	}

	std::string get_string()
	{
		size_t depth = this->max_depth();
		std::vector<node*> arr;
		std::string str;

		for (size_t i = 0; i < depth; i++)
		{
			str += std::string((depth - i) * 8, ' ');
			arr = this->_get_level(this->root, i);
			for (auto val : arr)
				str += val->key + "        ";
			str += '\n';
		}
		return str;
	}
};