#pragma once
#include "sorts.h"
#include "lists.h"
#include "structs.h"
#include "recursion.h"
#include <bitset>

int dual_list()
{
	bool run = true;

	while (run)
	{
		srand(time(0));

		dll::list<Goods> list;

		char fill_mode = io.input<char>("Select filling mode (M)anual/(R)andom/(Q)uit: ", true);

		if (fill_mode == 'Q') return 0;

		size_t len = io.input<size_t>("Length: ", true);

		for (size_t i = 0; i < len; i++)
		{
			if (fill_mode == 'M')
				list.push_back(io.input<Goods>("", true));
			else
				list.push_back(get_random_goods());
		}

		io.output("\nYour list: ");
		list.print(false, "\n");
		io.output("Your reversed list: ");
		list.print(true, "\n");

		char mode = io.input<char>("Select function to apply (S)ort/(M)ove refunded to head/(D)elete by date: ", true);

		switch (mode)
		{
		case 'S':
			list.sort();
			break;
		case 'M':
			move_refund(list);
			break;
		case 'D':
		{
			Date date = io.input<Date>("Delete items sold by: ", true);
			delete_by_date(list, date);
			break;
		}
		default:
			io.output("Wrong Mode: ", "");
			io.output(mode);
			break;
		}

		io.output("\nResult: ");
		list.print(false, "\n");
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
	, "Elapsed: "
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

		measure(MergeSort(arr, n - 1), "Elapsed: ");
		show_result;
		clear_arr;

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

int recursion()
{
	recur_queue();

	srand(time(0));
	std::vector<int> arr;

	char fill_mode = io.input<char>("Select filling mode (M)anual/(R)andom/(Q)uit: ", true);

	if (fill_mode == 'Q') return 0;

	size_t len = io.input<size_t>("Length: ", true);

	for (size_t i = 0; i < len; i++)
	{
		if (fill_mode == 'M')
			arr.push_back(io.input<int>("", true));
		else
			arr.push_back(rand());
	}

	io.output("Max value: ", "");
	measure(io.output(recur_max(arr, 0, arr.size() - 1)), "Recursion: ");

	io.output("Max value: ", "");
	measure(io.output(lin_max(arr)), "Iterational: ");

	io.output("Function calls: ", "");
	io.output(counter[1]);

	io.input<int>();
	return 0;
}

void bitwise_one()
{
	unsigned int num = 0;
	unsigned int mask = 0;
	unsigned int bit_n = 0;

	num = 0b0;
	mask = 0b101 << 5;
	num |= mask;
	io.output("Res: ", "");
	io.output(std::bitset<32>(num).to_string());

	num = io.input<unsigned int>("2. Num: ");
	mask = ~(0b1111 << 7);
	num &= mask;
	io.output("Res: ", "");
	io.output(std::bitset<32>(num).to_string());

	num = io.input<unsigned int>("3. Num: ");
	num <<= 3;
	num &= mask;
	io.output("Res: ", "");
	io.output(std::bitset<32>(num).to_string());

	num = io.input<unsigned int>("4. Num: ");
	num >>= 4;
	num &= mask;
	io.output("Res: ", "");
	io.output(std::bitset<32>(num).to_string());

	num = io.input<unsigned int>("5. Num: ");
	bit_n = io.input<unsigned int>("5. Bit's N: ");
	mask = 0b1 << bit_n;
	num &= mask;
	io.output("Res: ", "");
	io.output(std::bitset<32>(num).to_string());

}

class bitarray
{
private:
	unsigned char *arr;
	int size;

public:
	int getsize()
	{
		return this->size;
	}

	bitarray(int size){
		this->size = size;
		arr = new unsigned char[size / 8];
	}

	void setbit(int index)
	{
		arr[((size - index - 1) / 8)] |= 0b1 << (index % 8);
	}

	void resetbit(int index)
	{
		arr[((size - index - 1) / 8)] &= ~(0b1 << (index % 8));
	}

	bool operator[](int index)
	{
		return (arr[(size - index - 1) / 8] & 0b1 << (index % 8)) == (0b1 << (index % 8));
	}
};

void bitwise_two()
{
	bitarray arr(64);
	
	int val = 0;

	for (size_t i = 0; i < 64; i++)
	{
		arr.setbit(io.input<int>("# "));
	}
	io.output("Array: ", "");
	for (size_t i = 0; i < 64; i++)	
	{
		if (arr[i])
		{
			io.output(i, " ");
		}
	}
}

void bitwise_three()
{
	FIO fio("bita", "bitb");
	int size = fio.input<int>();
	bitarray array(size);
	for (size_t i = 0; i < size; i++)
	{
		array.setbit(fio.input<int>());
	}
	for (size_t i = 0; i < size; i++)
	{
		if (array[i])
			fio.output(i);
	}
}

int bitwise_operations()
{	
	char mode = io.input<char>("Choose: ");

	switch (mode)
	{
	case '1':
		bitwise_one();
		break;
	case '2':
		bitwise_two();
		break;
	case '3':
		bitwise_three();
		break;
	default:
		break;
	}

	io.input<int>();
	return 0;
}