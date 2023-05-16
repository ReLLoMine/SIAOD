#include "sorts.h"
#include "lists.h"
#include "structs.h"

extern IO io;

int dual_list()
{
	bool run = true;

	while (run)
	{
		dll::list<int> list;
		srand(time(0));

		char mode = io.input<char>("Mode (R)emove Negative / (A)dd 2 before last / (M)ove max to the end / (Q)uit: ", true);

		if (mode == 'Q') return 0;

		size_t len = io.input<size_t>("Length: ", true);

		char fill_mode = io.input<char>("Fill (M)anual / (R)andom: ", true);

		for (size_t i = 0; i < len; i++)
		{
			if (fill_mode == 'M')
				list.push_back(io.input<int>("", true));
			else
				list.push_back(rand() % 202 - 101);
		}
		io.output("Original list: ", "");
		list.print();
		list.print(true);

		switch (mode)
		{
		case 'R':
			break;
		case 'A':
			break;
		case 'M':
			break;
		default:
			io.output("Wrong Mode: ", "");
			io.output(mode);
			break;
		}

		io.output("List: ", "");
		list.print();
	}
}

int single_list()
{
	bool run = true;

	while (run)
	{
		sll::list<int> list;
		srand(time(0));

		char mode = io.input<char>("Mode (R)emove Negative / (A)dd 2 before last / (M)ove max to the end / (Q)uit: ", true);

		if (mode == 'Q') return 0;

		size_t len = io.input<size_t>("Length: ", true);

		char fill_mode = io.input<char>("Fill (M)anual / (R)andom: ", true);

		for (size_t i = 0; i < len; i++)
		{
			if (fill_mode == 'M')
				list.push_back(io.input<int>("", true));
			else
				list.push_back(rand() % 202 - 101);
		}
		io.output("Original list: ", "");
		list.print();

		switch (mode)
		{
		case 'R':
			list.remove_negative();
			break;
		case 'A':
			list.add_2_before_last(io.input<int>("Node 1: "), io.input<int>("Node 2: "));
			break;
		case 'M':
			list.move_max_to_end();
			break;
		default:
			io.output("Wrong Mode: ", "");
			io.output(mode);
			break;
		}

		io.output("List: ", "");
		list.print();
	}
}

void outer_sorts()
{
	int size = sizef("in.txt");

	Split(size / 4, "a", "b", "in.txt");

	measure(
		for (int n = 1; n < size; n *= 2)
		{
			split(n, "a", "b", "in.txt");
			mergeFilesByN<int>("a", "b", "in.txt", n, size);
		}
	);
	io.input<int>();
}

void sorts()
{
	bool run = true;
	while (run)
	{
		std::srand(3974598235);
		int n;
		char ch;

		n = io.input<int>("Length: ", true);

		int* arr = new int[n];

		ch = io.input<char>("Mode M/R/D/A/Q: ", true);

		if (ch == 'R')
		{
			for (int i = 0; i < n; i++)
			{
				arr[i] = rand();
			}

			if (n < 1000)
			{
				for (int i = 0; i < n; i++)
				{
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}
		}
		else if (ch == 'A')
		{
			for (int i = 0; i < n; i++)
			{
				arr[i] = i;
			}
		}
		else if (ch == 'D')
		{
			for (int i = 0; i < n; i++)
			{
				arr[i] = n - i;
			}
		}
		else if (ch == 'M')
		{
			for (int i = 0; i < n; i++)
			{
				std::cin >> arr[i];
			}
		}
		else if (ch == 'Q')
		{
			run = false;
			continue;
		}
		else
		{
			continue;
		}

		measure(MergeSort(arr, n - 1););
		show_result
			clear_arr

			if (n < 1000)
			{
				for (int i = 0; i < n; i++)
				{
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}
		if (arr)
			delete[] arr;
	}
}

int main()
{
	io.output(get_random_goods());
	io.input<int>();
	//return dual_list();
}