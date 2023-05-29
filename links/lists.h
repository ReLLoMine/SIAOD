#pragma once
#include "misc.h"

extern IO io;

namespace sll
{

	template <typename T>
	struct Node
	{
		T val;
		Node* next;
		Node(T _val) : val(_val), next(nullptr) {}
	};

	template <typename T>
	struct list // ���������� ��������� ��������� � ������ list - ������� ������ T - ��� ������
	{
		Node<T>* first; // ���������� ��������� "first" �� ������ ���� � ������� ������.
		Node<T>* last; // ���������� ��������� "last" �� ��������� ���� � ������� ������.

		list() : first(nullptr), last(nullptr) {} // ����������� ������������ ������ list.

		bool is_empty() { return first == nullptr; }; // ���������� ������� � ������ is_empty(), ������� ���������� �������� ���� bool.

		void push_back(T val) // ���������� � ����� ������
		{
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

		void print() // ����� �������� �������� ������
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

		Node<T>* find(T val) // ����� �������� �� ��������
		{
			Node<T>* node_ptr = first;
			while (node_ptr and node_ptr->val != val) node_ptr = node_ptr->next;
			return (node_ptr and node_ptr->val == val) ? node_ptr : nullptr;
		}

		void remove_first() // �������� ��������� ����
		{
			if (is_empty()) return;
			Node<T>* node_ptr = first;
			first = first->next;
			delete node_ptr;
			return;
		}

		void remove_last() // �������� ���������� ����
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

		void remove(T val) // �������� �� �������� ������
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
				io.output("This element doesnn't exist");
				return;
			}
			slow->next = fast->next;
			delete fast;
		}

		void remove_negative() // �������� ������� �������������� �������� �� �������� ������
		{
			if (is_empty()) return;

			Node<T>* fast = first;
			while (fast and fast->val >= 0)
			{
				fast = fast->next;
			}
			if (not fast)
			{
				io.output("There's no negative elements");
				return;
			}
			remove(fast->val);
		}

		void add_2_before_last(T val1, T val2) // �������� ��� �������� ����� ���������
		{
			T last_val;
			bool empty = is_empty();
			if (not empty)
				last_val = last->val;

			remove_last();

			push_back(val1);
			push_back(val2);

			if (not empty)
				push_back(last_val);
		}

		void move_max_to_end() // ����������� ������������ ������� � �����
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
}

namespace dll
{
	template <typename T>
	class Node
	{
	public:
		T val;
		Node* next;
		Node* prev;
		Node(T _val) : val(_val), next(nullptr), prev(nullptr) {}
	};

	template <typename T>
	struct list // ���������� ��������� ��������� � ������ list - ������� ������ T - ��� ������
	{
		Node<T>* first; // ���������� ��������� "first" �� ������ ���� � ������� ������.
		Node<T>* last; // ���������� ��������� "last" �� ��������� ���� � ������� ������.

		list() // ����������� ������������ ������ list.
		{
			first = nullptr;
			last = nullptr;
		}

		bool is_empty() { return first == nullptr and last == nullptr; }; // ���������� ������� � ������ is_empty(), ������� ���������� �������� ���� bool.

		void push_back(T val) // ���������� � ����� ������
		{
			Node<T>* node_ptr = new Node<T>(val);
			if (is_empty())
			{
				first = node_ptr;
				last = node_ptr;
				return;
			}
			node_ptr->prev = last;
			last->next = node_ptr;
			last = node_ptr;
		}

		void push_front(T val) // ���������� � ������ ������
		{
			Node<T>* node_ptr = new Node<T>(val);
			if (is_empty())
			{
				first = node_ptr;
				last = node_ptr;
				return;
			}
			node_ptr->next = first;
			first->prev = node_ptr;
			first = node_ptr;
		}

		void print(bool reversed = false, std::string sep=" ") // ����� �������� �������� ������
		{
			if (is_empty()) return;

			if (reversed)
			{
				Node<T>* node_ptr = last;
				while (node_ptr)
				{
					io.output(node_ptr->val, sep);
					node_ptr = node_ptr->prev;
				}
				io.output("");
			}
			else
			{
				Node<T>* node_ptr = first;
				while (node_ptr)
				{
					io.output(node_ptr->val, sep);
					node_ptr = node_ptr->next;
				}
				io.output("");
			}
		}

		Node<T>* find(T val) // ����� �������� �� ��������
		{
			Node<T>* node_ptr = first;
			while (node_ptr and node_ptr->val != val) node_ptr = node_ptr->next;
			return (node_ptr and node_ptr->val == val) ? node_ptr : nullptr;
		}

		Node<T>* find(std::string val) // ����� �������� �� ��������
		{
			Node<T>* node_ptr = first;
			while (node_ptr and (std::string) node_ptr->val != val) node_ptr = node_ptr->next;
			return (node_ptr and (std::string) node_ptr->val == val) ? node_ptr : nullptr;
		}

		void remove_first() // �������� ��������� ����
		{
			if (is_empty()) return;

			Node<T>* node_ptr = first;

			first = first->next;
			if(first)
				first->prev = nullptr;

			delete node_ptr;
			return;
		}

		void remove_last() // �������� ���������� ����
		{
			if (is_empty()) return;

			Node<T>* node_ptr = last;	

			last = last->prev;
			if(last)
				last->next = nullptr;

			delete node_ptr;
			return;
		}

		void remove(T val) // �������� �� �������� ������
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

			Node<T>* cursor = first;

			while (cursor and cursor->val != val)
				cursor = cursor->next;

			if (!cursor)
			{
				io.output("This element doesnn't exist");
				return;
			}

			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;

			delete cursor;
		}

		void remove(std::string val) // �������� �� �������� ������
		{
			if (is_empty()) return;

			if ((std::string) first->val == val)
			{
				remove_first();
				return;
			}
			else if ((std::string) last->val == val)
			{
				remove_last();
				return;
			}

			Node<T>* cursor = first;

			while (cursor and (std::string) cursor->val != val)
				cursor = cursor->next;

			if (!cursor)
			{
				io.output("This element doesnn't exist");
				return;
			}

			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;

			delete cursor;
		}

		void remove(Node<T> *valPtr) // �������� �� �������� ������
		{
			if (is_empty()) return;

			if (first== valPtr)
			{
				remove_first();
				return;
			}
			else if (last == valPtr)
			{
				remove_last();
				return;
			}

			Node<T>* cursor = first;

			while (cursor and cursor != valPtr)
				cursor = cursor->next;

			if (!cursor)
			{
				io.output("This element doesnn't exist");
				return;
			}

			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;

			delete cursor;
		}

		void sort() // ������� ��� �������������� ������������ ������ // insertion_sort()
		{
			if (first == nullptr)
			{
				return; // ���� ������ ����, ������ �� ������
			}
			Node<T>* sorted_list = nullptr; // ������� ����� ������ ��� ��������������� ���������
			Node<T>* current = first;

			while (current != nullptr)
			{
				Node<T>* next = current->next;
				if (sorted_list == nullptr || current->val < sorted_list->val)
				{
					// ���� ��������������� ������ ���� ��� �������� �������� �������� ������ �������� ������� �������� � ��������������� ������,
					// �� ��������� ������� ������� � ������ ���������������� ������
					current->next = sorted_list;
					sorted_list = current;
				}
				else
				{
					// ����� ���� ����� � ��������������� ������, ����� ������� ����� ���������������� �������
					Node<T>* sorted_current = sorted_list;
					while (sorted_current->next != nullptr && current->val >= sorted_current->next->val)
					{
						sorted_current = sorted_current->next;
					}
					// ��������� ������� ������� ����� ��������� ������
					current->next = sorted_current->next;
					sorted_current->next = current;
				}
				current = next;
			}
			// ��������� ��������� �� ������ ������� ������
			first = sorted_list;
		}
	};
}
