#pragma once
#include "misc.h"

extern IO io;

template <typename T>
struct Node
{
	T val;
	Node* next;
	Node(T _val) : val(_val), next(nullptr) {}
};

template <typename T>
struct list
{
	Node<T>* first;
	Node<T>* last;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() { return first == nullptr; };

	void push_back(T val) {
		Node<T>* node_ptr = new Node<T>(val);
		if (is_empty())
		{
			first = node_ptr;
			last = node_ptr;
			return;
		}
		last->next = node_ptr;
		last = node_ptr;
	}

	void print()
	{
		if (is_empty()) return;
		Node<T>* node_ptr = first;
		while (node_ptr)
		{
			io.output(node_ptr->val, " ");
			node_ptr = node_ptr->next;
		}
		io.output("");
	}

	Node<T>* find(T val)
	{
		Node<T>* node_ptr = first;
		while (node_ptr and node_ptr->val != val) node_ptr = node_ptr->next;
		return (node_ptr and node_ptr->val == val) ? node_ptr : nullptr;
	}

	void remove_first()
	{
		if (is_empty()) return;
		Node<T>* node_ptr = first;
		first = first->next;
		delete node_ptr;
		return;
	}

	void remove_last()
	{
		if (is_empty()) return;

		if (first == last)
		{
			delete first;
			first = last = nullptr;
			return;
		}

		Node<T>* node_ptr = first;
		while (node_ptr->next != last) node_ptr = node_ptr->next;
		node_ptr->next = nullptr;
		delete last;
		last = node_ptr;
	}

	void remove(T val)
	{
		if (is_empty()) return;

		if (first->val == val)
		{
			remove_first();
			return;
		}
		else if (last->val == val)
		{
			remove_last();
			return;
		}
		Node<T>* slow = first;
		Node<T>* fast = first->next;
		while (fast and fast->val != val)
		{
			slow = slow->next;
			fast = fast->next;
		}
		if (!fast)
		{
			io.output("This element don't exist");
			return;
		}
		slow->next = fast->next;
		delete fast;
	}

	void remove_negative()
	{
		if (is_empty()) return;

		if (first->val < 0)
		{
			remove_first();
			return;
		}
		Node<T>* slow = first;
		Node<T>* fast = first->next;
		while (fast and fast->val >= 0)
		{
			slow = slow->next;
			fast = fast->next;
		}
		if (!fast)
		{
			io.output("This element don't exist");
			return;
		}
		slow->next = fast->next;
		delete fast;
	}

	void add_2_before_last(T val1, T val2)
	{
		Node<T>* node_prt1 = new Node<T>(val1);
		Node<T>* node_prt2 = new Node<T>(val2);
		node_prt1->next = node_prt2;

		if (is_empty()) 
		{
			first = node_prt1;
			last = node_prt2;
			return;
		}

		Node<T>* very_slow = nullptr;
		Node<T>* slow = first;
		Node<T>* fast = first->next;
		while (fast)
		{
			very_slow = slow;
			slow = slow->next;
			fast = fast->next;
		}
		if (very_slow)
		{
			very_slow->next = node_prt1;
			node_prt2->next = last;
		}
		else
		{
			node_prt2->next = first;
			first = node_prt1;
		}


	}

	void move_max_to_end()
	{
		if (is_empty() or first == last)
			return;

		Node<T>* max_node = first;
		Node<T>* cursor = first;

		while (cursor)
		{
			if (cursor->val > max_node->val)
				max_node = cursor;
			cursor = cursor->next;
		}
		T val = max_node->val;
		remove(val);
		push_back(val);
	}
};
