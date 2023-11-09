#pragma once

#include "misc.h"

struct node
{
	char val;
	node* left;
	node* right;

	node(char userData)
	{
		this->val = userData;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class exp_tree
{
private:
	node *root;

	int _recurr_calc(node* root)
	{
		char c = root->val;
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			int leftValue = _recurr_calc(root->left);
			int rightValue = _recurr_calc(root->right);
			switch (c) {
			case '+':
				return leftValue + rightValue;
			case '-':
				return leftValue - rightValue;
			case '*':
				return leftValue * rightValue;
			default:
				return 0;
			}
		}
		else
		{
			return c - '0';
		}
	}

	std::string _recurr_str(node* root)
	{
		std::string c(1, root->val);
		if (c == "+" || c == "-" || c == "*" || c == "/")
		{
			return c + this->_recurr_str(root->left) + this->_recurr_str(root->right);
		}
		else
		{
			return c;
		}
	}

public:
	exp_tree(std::string exp, std::string form="prefix")
	{
		if (form == "prefix")
			for (size_t i = 0; i < exp.size() / 2; i++)
				std::swap(exp[i], exp[exp.size() - i - 1]);

		std::stack<node*> stack;
		for (char c : exp)
		{
			if (c == '+' || c == '-' || c == '*' || c == '/')
			{
				node* x = stack.top();
				stack.pop();
				node* y = stack.top();
				stack.pop();
				node* a = new node(c);

				if (form == "prefix")
				{
					a->left = x;
					a->right = y;
				}
				else
				{
					a->left = y;
					a->right = x;
				}

				stack.push(a);
			}
			else {
				stack.push(new node(c));
			}
		}
		this->root = stack.top();
	}

	std::string get_prefix_form()
	{
		return this->_recurr_str(this->root);
	}

	int calc()
	{
		return this->_recurr_calc(this->root);
	}
};
