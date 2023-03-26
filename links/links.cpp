#include <iostream>
#include <ctime>
#include <chrono>
#include <random>

using namespace std::chrono;

#define measure(function) {\
auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();\
function \
std::cout << "Elapsed: " << duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start  << " microseconds" << std::endl;\
}

#define SIZE 1000

long long int counter[SIZE] = { 0 };
long long int sum = 0;

// n - номер строки
#define comp(n) ++counter[n] &&
#define ass(n) ++counter[n];

#define clear_arr for (auto &i : counter) i = 0; sum = 0; 

#define show_result for (auto i : counter)\
	{sum += i;}\
std::cout << "Compares/Assignments: " << sum << std::endl;\
for (int i = 0; i < SIZE; i++)\
	if (counter[i])\
		std::cout << i << ": " << counter[i] << std::endl;\

void swap(int & a, int & b)
{
	int tmp = a; ass(34)
	a = b; ass(35)
	b = tmp; ass(36)
}

void wait()
{
	char c;
	std::cout << "\nEnter q to continue\n";
	std::cin >> c;
}

int my_count(int** matrix, int n, int m)
{
	int cnt = 0, max = 0, max_idx = 0; 

	for (int i = 0;  i < n; i++)
	{
		cnt = 0; 
		for (int j = 1;  j < m; j++)
		{
			if ( matrix[i][j] == matrix[i][j - 1])
			{
				cnt++; 
			}
			else if ( cnt > max)
			{
				max = cnt; 
				max_idx = i; 
				cnt = 0; 
			}
			else
			{
				cnt = 0; 
			}
			
		}

		if ( cnt > max)
		{
			max = cnt; 
			max_idx = i; 
			cnt = 0; 
		}
		
	}
	return max_idx;
}

// Функция сортировки методом Простой вставки
void insertionSort(int arr[], int n) {
	for (int i = 1; comp(82) i < n; i++) { // Цикл по всем элементам массива, начиная с первого
		int key = arr[i]; ass(83) // Сохраняем текущий элемент в переменной key
		int j = i - 1; ass(84) // Начинаем сравнивать с предыдущим элементом
		// Пока предыдущий элемент больше текущего и мы не дошли до начала массива
		while (comp(86) j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j]; ass(87) // Сдвигаем элементы вправо
			j--; ass(88) // Переходим к следующему элементу слева
		}
		arr[j + 1] = key; ass(90) // Вставляем текущий элемент на правильное место
	}
}

// Функция сортировки методом Простого выбора
void selectionSort(int arr[], int n) {
	int minIndex, tmp;
	for (int i = 0; comp(97) i < n - 1; i++) {
		minIndex = i; ass(98) // минимальный элемент находится на i-ой позиции
		for (int j = i + 1; comp(99) j < n; j++) {
			if (comp(100) arr[j] < arr[minIndex])
			{
				minIndex = j; ass(102) // найден новый минимальный элемент
			}
		}
		// меняем местами i-ый и минимальный элементы
		tmp = arr[i]; ass(106)
		arr[i] = arr[minIndex]; ass(107)
		arr[minIndex] = tmp; ass(108)
	}
}

// Функция сортировки методом шейкера
void shakerSort(int* a, int n) {
	int left = 0; ass(1)
	int right = n - 1; ass(2)
	bool sorted = false; ass(3)
	int tmp; ass(4)
	
	while (comp(5) left <= right and not sorted) 
	{
		sorted = true; ass(6)

		for (int i = right; comp(7) i >= left; i--) // Проход справа налево
		{
			if (comp(8) a[i - 1] > a[i])
			{
				tmp = a[i - 1]; ass(9)
				a[i - 1] = a[i]; ass(10)
				a[i] = tmp; ass(11)
				sorted = false; ass(12)
			}
		}
		if (comp(13) sorted) // Выход, если не было перестановок
			break;
		sorted = true; ass(14)

		left++; ass(15)
		for (int i = left; comp(16) i <= right; i++) // Проход слева направо
		{ 
			if (comp(17) a[i - 1] > a[i])
			{
				tmp = a[i - 1]; ass(18)
				a[i - 1] = a[i]; ass(19)
				a[i] = tmp; ass(20)
				sorted = false; ass(21)
			}
		}
		right--; ass(22)
	}
}

int main()
{
	std::srand(3974598235);
	int n;
	char ch;

	std::cin >> n;

	int* arr = new int[n];

	//std::cout << "Rand? M/R/D/A :>";

	//std::cin >> ch;

	//if (ch == 'R')
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		arr[i] = rand() % 101;
	//	}

	//	if (n < 1000)
	//	{
	//		for (int i = 0; i < n; i++)
	//		{
	//			std::cout << arr[i] << " ";
	//		}
	//		std::cout << std::endl;
	//	}
	//}
	//else if (ch == 'A')
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		arr[i] = i;
	//	}
	//}
	//else if (ch == 'D')
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		arr[i] = n - i;
	//	}
	//}
	//else if (ch == 'M')
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		std::cin >> arr[i];
	//	}
	//}

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	measure(insertionSort(arr, n););
	show_result
	clear_arr

	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}

	measure(insertionSort(arr, n););
	show_result
	clear_arr

	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}

	measure(insertionSort(arr, n););
	show_result
	clear_arr


	wait();
}
