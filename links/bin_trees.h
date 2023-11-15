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

	void _insert(node* root, std::string key, T val)
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

	void _find_inorder_successor(node* root, node*& successor, node*& _ancestor, node* ancestor, std::string key)
	{
		if (root->left)
			this->_find_inorder_successor(root->left, successor, _ancestor, root, key);
		if (root->key > key and root->key < successor->key or successor->key <= key)
		{
			successor = root;
			_ancestor = ancestor;
		}
		if (root->right)
			this->_find_inorder_successor(root->right, successor, _ancestor, root, key);
	}

	node* _find_inorder_successor(std::string key, node*& ancestor)
	{
		node* successor = this->root;
		this->_find_inorder_successor(this->root, successor, ancestor, nullptr, key);
		return successor;
	}

	node* _find(node* root, std::string key)
	{
		if (not root)
			return nullptr;
		if (root->key == key)
			return root;
		if (root->key > key)
			return _find(root->left, key);
		if (root->key < key)
			return _find(root->right, key);
		return nullptr;
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

	void _get_all_nodes(node* root, std::vector<node*>& all_nodes)
	{
		if (root->left)
			this->_get_all_nodes(root->left, all_nodes);
		all_nodes.push_back(root);
		if (root->right)
			this->_get_all_nodes(root->right, all_nodes);
	}

	std::vector<node*> _get_all_nodes()
	{
		std::vector <node*> all_nodes;
		this->_get_all_nodes(this->root, all_nodes);
		return all_nodes;
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
		node* pos = this->_find(this->root, key);
		node* parent = nullptr;
		node* prev_parent = nullptr;
		node* successor = nullptr;

		while (pos->left or pos->right)
		{
			successor = this->_find_inorder_successor(pos->key, parent);

			if (pos == successor)
				break;
			else
			{
				std::swap(pos->key, successor->key);
				std::swap(pos->val, successor->val);
				prev_parent = parent;
				pos = successor;
			}
		}
		parent = prev_parent;
		if (pos == successor)
		{
			if (not (pos->left and pos->left) or (pos->left or pos->left))
			{
				if (parent->left->key == pos->key)
					parent->left = pos->left;
				else if (parent->right->key == pos->key)
					parent->right = pos->right;
			}
		}

		if(parent)
			if (parent->left->key == pos->key)
				parent->left = nullptr;
			else if (parent->right->key == pos->key)
				parent->right = nullptr;

		delete pos;
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

	std::string get_graphviz()
	{
		std::vector<node*> nodes;
		this->_get_all_nodes(this->root, nodes);
		std::string str = "digraph Tree {\n";

		for (node* &node : nodes)
		{
			if (node->left)
				str += '\"' + node->key + '\"' + " -> " + '\"' + node->left->key + "\"\n";

			if (node->right)
				str += '\"' + node->key + '\"' + " -> " + '\"' + node->right->key + "\"\n";
		}
		return str + "}";
	}
};