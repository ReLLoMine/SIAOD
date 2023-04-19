#include "sorts.h"
#include "lists.h"

extern IO io;

int main()
{
	list<int> list;

	size_t len = io.input<size_t>("Length: ", true);

	for (size_t i = 0; i < len; i++)
	{
		list.push_back(io.input<int>("", true));
	}

	list.move_max_to_end();
	list.print();
	io.input<int>();
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