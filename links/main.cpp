#include "sorts.h"
#include "misc.h"

int main()
{
	bool run = true;
	IO io;

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
		if(arr)
			delete[] arr;
	}
}
