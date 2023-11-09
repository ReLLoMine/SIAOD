#pragma once
#include "sorts.h"
#include "lists.h"
#include "structs.h"
#include "recursion.h"
#include "map.h"
#include "exp_tree.h"
#include "bin_trees.h"
#include <set>
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

namespace bitwise{

	void bitwise_one()
	{
		unsigned short int num = 0;
		unsigned short int mask = 0;
		unsigned short int bit_n = 0;

		num = 0b10;
		mask = 0b0000000010100000;
		io.output("num = ", "");
		io.output(std::bitset<16>(num).to_string());
		io.output("mask = ", "");
		io.output(std::bitset<16>(mask).to_string());
		num |= mask;
		io.output("bit res = ", "");
		io.output(std::bitset<16>(num).to_string());
		io.output("res = ", "");
		io.output(num);

		num = io.input<unsigned int>("2. Num: ");
		mask = 0b1111100001111111;
		io.output("num = ", "");
		io.output(std::bitset<16>(num).to_string());
		io.output("mask = ", "");
		io.output(std::bitset<16>(mask).to_string());
		num &= mask;
		io.output("bit res = ", "");
		io.output(std::bitset<16>(num).to_string());
		io.output("res = ", "");
		io.output(num);

		num = io.input<unsigned int>("3. Num: ");
		io.output("num = ", "");
		io.output(std::bitset<16>(num).to_string());
		num <<= 4;
		io.output("bit res = ", "");
		io.output(std::bitset<16>(num).to_string());
		io.output("res = ", "");
		io.output(num);

		num = io.input<unsigned int>("4. Num: ");
		io.output("num = ", "");
		io.output(std::bitset<16>(num).to_string());
		num >>= 3;
		io.output("bit res = ", "");
		io.output(std::bitset<16>(num).to_string());
		io.output("res = ", "");
		io.output(num);

		num = io.input<unsigned int>("5. Num: ");
		bit_n = io.input<unsigned int>("Bit's N: ");
		io.output("num = ", "");
		io.output(std::bitset<16>(num).to_string());
		mask = 0b1 << bit_n;
		io.output("mask = ", "");
		io.output(std::bitset<16>(mask).to_string());
		num |= mask;
		io.output("bit res = ", "");
		io.output(std::bitset<16>(num).to_string());
		io.output("res = ", "");
		io.output(num);
	}

	class bitarray
	{
	private:
		unsigned char* arr;
		size_t size;
		size_t bytes;

	public:
		bitarray(size_t size) {
			this->size = size;
			this->bytes = (size_t)std::ceil(size / 8.);
			arr = new unsigned char[this->bytes];
			for (size_t i = 0; i < this->bytes; i++)
				arr[i] = '\0';
		}

		~bitarray() {
			delete[] arr;
		}

		size_t getsize()
		{
			return this->size;
		}

		size_t getbytes()
		{
			return this->bytes;
		}

		void setbit(size_t index)
		{
			arr[(size_t)(index) / 8] |= 0b1 << (index % 8);
		}

		void resetbit(size_t index)
		{
			arr[(size_t)(index) / 8] &= ~(0b1 << (index % 8));
		}

		bool operator[](size_t index)
		{
			return (arr[(size_t)(index) / 8] & 0b1 << (index % 8)) == (0b1 << (index % 8));
		}
	};

	void bitwise_two()
	{
		size_t size = io.input<size_t>("Size (max 8): ");
		unsigned char arr = '\0';
		unsigned short int bit;

		for (size_t i = 0; i < size; i++)
		{
			bit = io.input<unsigned short int>("# ");
			arr |= 0b1 << bit;
		}
		io.output("Array: ", "");
		for (size_t i = 0; i < 8; i++)
		{
			if ((arr & (0b1 << i)) == (0b1 << i))
			{
				io.output(i, " ");
			}
		}
		io.output("");
	}

	void bitwise_two_point_one()
	{
		size_t size = io.input<size_t>("Size: ");
		bitarray arr(size);
		unsigned short int bit;

		for (size_t i = 0; i < size; i++)
		{
			arr.setbit(io.input<unsigned short int>());
		}
		io.output("Array: ", "");
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i])
			{
				io.output(i, " ");
			}
		}
	}

	void bitwise_three()
	{
		FIO fio("", "bita");

		srand(time(0));

		size_t len = io.input<size_t>("Enter lenght: ");

		for (size_t i = 0; i < len; i++)
		{
			fio.output((((rand() + rand()) << 16) + (rand() + rand())) % len);
		}

		io.output("File is ready.");

		fio.close();

		fio.set_in("bita");
		fio.set_out("bitb");
		fio.open();

		int var;
		bitarray array(len);
		measure(
			for (; !fio.is_end();)
			{
				var = fio.input<int>();
				if (!fio.was_error())
					array.setbit(var);
				fio.clear_error();
			}
		for (size_t i = 0; i < array.getsize(); i++)
		{
			if (array[i])
				fio.output(i);
		}, "Elapsed time: "
			);
		io.output("Size in RAM (KB): ", "");
		io.output(array.getbytes() / 1024.);
	}

	int run()
	{
		char mode = io.input<char>("Choose: ");

		switch (mode)
		{
		case '1':
			bitwise_one();
			break;
		case '2':
			bitwise_two();
			bitwise_two_point_one();
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
}

namespace file_and_bin_search{

	struct carDriver
	{
		char license_number[15];
		char car_brand[15];
		char name[15];

		carDriver()
		{
			for (size_t i = 0; i < 15; i++)
			{
				license_number[i] = car_brand[i] = name[i] = 0;
			}
		}
	};

	int bin_search_one()
	{
		FIO fio("data", "data");

		if (!fio.is_open())
		{
			io.output("File not found.");
			return 0;
		}

		FIO bin_fio("", "data.bin", "bin");

		if (!bin_fio.is_outf_open())
		{
			io.output("Binary file not found.");
			return 0;
		}

		size_t entries = io.input<size_t>("Enter amount of entries: ");
		std::set<std::string> unique_entries;

		srand(time(0));

		for (size_t i = 0; i < entries; i++)
		{
			carDriver driver;
			strcpy_s(driver.name, ("Driver_" + std::to_string(i)).c_str());
			strcpy_s(driver.car_brand, ("Car_" + std::to_string(i)).c_str());
			std::string license_number;

			do
			{
				for (size_t j = 0; j < 6; j++)
				{
					int num = rand() % 36;
					license_number += (char)(num < 10 ? num + '0' : num - 10 + 'A');
				}
			} while (unique_entries.count(license_number) > 0);

			unique_entries.insert(license_number);

			strcpy_s(driver.license_number, license_number.c_str());

			fio.output(driver.license_number);
			fio.output(driver.car_brand);
			fio.output(driver.name);
		}

		io.output("File generated!");

		for (size_t i = 0; i < entries; i++)
		{
			carDriver driver;
			std::string data;

			data = fio.input<std::string>();
			strcpy_s(driver.license_number, data.c_str());

			data = fio.input<std::string>();
			strcpy_s(driver.car_brand, data.c_str());

			data = fio.input<std::string>();
			strcpy_s(driver.name, data.c_str());

			bin_fio.write(reinterpret_cast<const char*>(&driver), sizeof(driver));
		}

		io.output("Binary file generated!");
		io.output("Entry size: ", "");
		io.output(sizeof(carDriver), " bytes\n");

		fio.close();
		bin_fio.close();

		return 0;
	}

	/*
	Функция ЛинейныйПоиск(массив, цель):
		Для каждого элемента в массиве с индексом i от 0 до длины массива - 1:
			Если элемент[i] равен ключу:
				Вернуть i (или сам элемент)

		Вернуть -1 (или другое значение, чтобы указать, что элемент не найден)
	*/

	int bin_search_two()
	{
		FIO bin_fio("data.bin", "", "bin");

		if (!bin_fio.is_inf_open())
		{
			io.output("File not found.");
			return 0;
		}

		carDriver driver;

		bool was_found = false;
		std::string license_number = io.input<std::string>("Enter license: ");

		measure(
			while (bin_fio.read(reinterpret_cast<char*>(&driver), sizeof(driver)))
			{
				if (driver.license_number == license_number)
				{
					was_found = true;
					break;
				}
			}, "Elapsed time: ");

		if (was_found)
		{
			io.output("Entry found: ");
			io.output("    License number: ", "");
			io.output(driver.license_number);
			io.output("    Car: ", "");
			io.output(driver.car_brand);
			io.output("    Driver name: ", "");
			io.output(driver.name);
		}
		else
			io.output("Entry wasn't found.");

		bin_fio.close();

		return 0;
	}

	struct fileKey
	{
		std::string key;
		size_t offset;
	};

	/*
	Функция ФибоначчиПоиск(массив, цель):
		n = ДлинаМассива(массив)
		FnMinus2 = 0
		FnMinus1 = 1
		Fn = FnMinus1 + FnMinus2

		Пока Fn < n:
			FnMinus2 = FnMinus1
			FnMinus1 = Fn
			Fn = FnMinus1 + FnMinus2

		offset = -1

		Пока Fn > 1:
			i = Минимум(offset + FnMinus2, n - 1)

			Если массив[i] < цель:
				Fn = FnMinus1
				FnMinus1 = FnMinus2
				FnMinus2 = Fn - FnMinus1
				offset = i
			Иначе Если массив[i] > цель:
				Fn = FnMinus2
				FnMinus1 = FnMinus1 - FnMinus2
				FnMinus2 = Fn - FnMinus1
			Иначе:
				Вернуть i // Элемент найден
		Если FnMinus1 == 1 И массив[offset + 1] == цель:
			Вернуть offset + 1
		Вернуть -1 // Элемент не найден
	*/

	int fib(const std::vector<fileKey>&arr, std::string key)
	{
		int size = arr.size();

		int n_prev_prev = 0;
		int n_prev = 1;
		int n = n_prev + n_prev_prev;
		while (n < size)
		{
			n_prev_prev = n_prev;
			n_prev = n;
			n = n_prev + n_prev_prev;
		}
		int offset = -1;
		while (n > 1)
		{
			int i = std::min(offset + n_prev_prev, size - 1);
			if (arr[i].key < key)
			{
				n = n_prev;
				n_prev = n_prev_prev;
				n_prev_prev = n - n_prev;
				offset = i;
			}
			else if (arr[i].key > key)
			{
				n = n_prev_prev;
				n_prev = n_prev - n_prev_prev;
				n_prev_prev = n - n_prev;
			}
			else
			{
				return arr[i].offset;
			}
		}
		if (n_prev == 1 && arr[offset + 1].key == key)
		{
			return arr[offset + 1].offset;
		}
		return -1;
	}

	int bin_search_three()
	{
		FIO bin_fio("data.bin", "", "bin");

		carDriver driver;
		std::vector<fileKey> keyTable;
		size_t offset = 0;

		bool was_found = false;

		std::string license_number = io.input<std::string>("Enter license: ");

		while (bin_fio.read(reinterpret_cast<char*>(&driver), sizeof(driver)))
		{
			fileKey key;
			key.key = driver.license_number;
			key.offset = offset;
			keyTable.push_back(key);
			offset++;
		}

		std::sort(keyTable.begin(), keyTable.end(), [](const fileKey& a, const fileKey& b) {return a.key < b.key; });

		io.output("Table is ready");

		bin_fio.close();

		measure(
			offset = fib(keyTable, license_number);

		if (offset != -1)
			was_found = true;

		if (was_found)
		{
			bin_fio.open();
			bin_fio.move(offset * sizeof(carDriver));
			bin_fio.read(reinterpret_cast<char*>(&driver), sizeof(driver));
		},
			"Elapsed time: ");

		if (was_found)
		{
			io.output("Entry found: ");
			io.output("    License number: ", "");
			io.output(driver.license_number);
			io.output("    Car: ", "");
			io.output(driver.car_brand);
			io.output("    Driver name: ", "");
			io.output(driver.name);
		}
		else
			io.output("Entry wasn't found.");

		bin_fio.close();

		return 0;
	}

	int run()
	{
		char mode = io.input<char>("Choose: ");

		switch (mode)
		{
		case '1':
			bin_search_one();
			break;
		case '2':
			bin_search_two();
			break;
		case '3':
			bin_search_three();
			break;
		default:
			break;
		}

		return 0;
	}
}

namespace hash_table
{
	struct goodSales
	{
		char id[10] = { 0 };
		char name[15] = { 0 };
		size_t price;
		char sale_date[11] = { 0 };
	};

	struct fileKey
	{
		char id[10] = { 0 };
		size_t offset;
	};

	int hash_table_one()
	{
		time_t s = time(0);
		srand(s);

		map<goodSales> data;
		std::set<std::string> ids;

		std::vector<goodSales> entries;

		size_t size = io.input<int>("Enter amount: ");

		goodSales entry;

		for (size_t i = 0; i < size; i++)
		{
			strcpy_s(entry.name, ("Good_" + std::to_string(i)).c_str());
			strcpy_s(entry.sale_date, "11.09.2001");
			entry.price = rand();
			std::string id;

			do
			{
				id = "";
				for (size_t j = 0; j < 6; j++)
				{
					int num = rand() % 36;
					id += (char)(num < 10 ? num + '0' : num - 10 + 'A');
				}
			} while (ids.count(id) > 0);

			strcpy_s(entry.id, id.c_str());

			entries.push_back(entry);

			ids.insert(id);

		}

		measure(
			for (auto& val : entries)
				data.insert(val.id, val);
		, "Table is ready.\nElapsed time: ");

		measure(
			for (auto key : ids)
			{
				io.output(data[key].name);
				data.remove(key);
				break;
			}, "Element is found.\nElapsed time: ");

		return 0;
	}

	int hash_table_two()
	{
		FIO bin_fio("", "hash_data.bin", "bin");
		time_t s = time(0);
		srand(s);

		map<fileKey> data;
		std::set<std::string> ids;
		goodSales entry;

		size_t size = io.input<int>("Enter amount: ");

		for (size_t i = 0; i < size; i++)
		{
			strcpy_s(entry.name, ("Good_" + std::to_string(i)).c_str());
			strcpy_s(entry.sale_date, "11.09.2001");
			entry.price = rand();
			std::string id;

			do
			{
				id = "";
				for (size_t j = 0; j < 6; j++)
				{
					int num = rand() % 36;
					id += (char)(num < 10 ? num + '0' : num - 10 + 'A');
				}
			} while (ids.count(id) > 0);

			strcpy_s(entry.id, id.c_str());

			bin_fio.write(reinterpret_cast<const char*>(&entry), sizeof(entry));

			ids.insert(id);
		}

		io.output("Bin file is ready.");

		bin_fio.close_outf();
		bin_fio.set_out("");
		bin_fio.set_in("hash_data.bin");
		bin_fio.open_inf();

		size_t offset = 0;
		fileKey entry_pair;

		while (bin_fio.read(reinterpret_cast<char*>(&entry), sizeof(entry)))
		{
			entry_pair.offset = offset++;
			strcpy_s(entry_pair.id, entry.id);
			data.insert(entry_pair.id, entry_pair);
		}

		io.output("Table is ready.");

		bin_fio.close_inf();
		bin_fio.open_inf();

		measure(
			for (auto key : ids)
			{
				bin_fio.move(data[key].offset * sizeof(entry));
				bin_fio.read(reinterpret_cast<char*>(&entry), sizeof(entry));
				io.output(entry.id);
				io.output(entry.name);
				break;
			}, "Entry found in bin file.\nElapsed time: "
				);


		bin_fio.close();

		return 0;
	}

	int run()
	{
		char mode = io.input<char>("Choose: ");

		switch (mode)
		{
		case '1':
			hash_table_one();
			break;
		case '2':
			hash_table_two();
			break;
		default:
			break;
		}

		return 0;
	}
}

namespace expess_tree
{
	int run()
	{
		io.output("Enter expression and form: ", "");
		std::string expression = io.input<std::string>();
		std::string form = io.input<std::string>();
		exp_tree tree(expression, form);
		io.output("Result: ", "");
		io.output(tree.calc());
		io.output("Prefix form: ", "");
		io.output(tree.get_prefix_form());
		return 0;
	}
}

namespace binary_trees
{
	struct goodSales
	{
		char id[10] = { 0 };
		char name[15] = { 0 };
		size_t price;
		char sale_date[11] = { 0 };
	};

	class fileKey
	{
	public:
		char id[10] = { 0 };
		size_t offset = 0;

		fileKey() {}

		fileKey(const char* id, size_t offset)
		{
			strcpy_s(this->id, id);
			this->offset = offset;
		}

		bool operator<(const fileKey& other)
		{
			return std::string(this->id) < std::string(other.id);
		}

		bool operator>(const fileKey& other)
		{
			return std::string(this->id) > std::string(other.id);
		}

		std::string to_string()
		{
			return std::string(this->id);
		}
	};


	int run()
	{
		bin_search_tree<fileKey> tree;

		tree.insert("ABCDED", fileKey("ABCDED", 9));
		tree.insert("DABCEJ", fileKey("DABCEJ", 4));
		tree.insert("DEABCK", fileKey("DEABCK", 32123));
		tree.insert("CABDER", fileKey("CABDER", 123));
		tree.insert("CDABES", fileKey("CDABES", 16));

		tree.remove("CABDER");

		io.output(tree["CABDER"].offset);
		return 0;
	}
}