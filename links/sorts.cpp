#include "sorts.h"

void swap(int& a, int& b, int line)
{
	int tmp = a; ass(line)
	a = b; ass(line)
	b = tmp; ass(line)
}

// Функция сортировки методом Простой вставки
void insertionSort(int arr[], int n)
{
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
void selectionSort(int arr[], int n)
{
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

void quickSort(int* arr, int R, int L)
{
	if (R - L < 1)
	{
		return;
	}

	int x = L, y = L;
	int mid = arr[(R + L) / 2];
	//int mid = arr[(std::rand() % (R - L)) + L];

	for (int i = L; i < R; i++)
	{
		if (arr[i] < mid)
		{
			swap(arr[i], arr[x], 130);

			if (x != y)
			{
				swap(arr[i], arr[y], 130);
			}

			y++;
			x++;
		}
		else if (arr[i] == mid)
		{
			swap(arr[i], arr[y], 130);
			y++;
		}
	}

	quickSort(arr, x, L);
	quickSort(arr, R, y);
}

// Функция сортировки методом шейкера
void shakerSort(int* a, int n)
{
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
					swap(a[i - 1], a[i], 9);
					sorted = false; ass(10)
				}
			}
		if (comp(11) sorted) // Выход, если не было перестановок
			break;
		sorted = true; ass(12)

			left++; ass(13)
			for (int i = left; comp(14) i <= right; i++) // Проход слева направо
			{
				if (comp(15) a[i - 1] > a[i])
				{
					swap(a[i - 1], a[i], 16);
					sorted = false; ass(17)
				}
			}
		right--; ass(18)
	}
}

void merge(int array[], int L, int mid, int R)
{
	int const left_arr_s = mid - L + 1; ass(1)
	int const right_arr_s = R - mid; ass(2)
	int* left_arr = new int[left_arr_s]; ass(3)
	int* right_arr = new int[right_arr_s]; ass(4)

	for (int i = 0; comp(5) i < left_arr_s; i++)
	{
		left_arr[i] = array[L + i]; ass(6)
	}
	for (int j = 0; comp(7) j < right_arr_s; j++)
	{
		right_arr[j] = array[mid + 1 + j]; ass(8)
	}

	int left_arr_idx = 0; ass(9)
	int right_arr_idx = 0; ass(10)
	int merged_arr_idx = L; ass(11)

	while (comp(12) left_arr_idx < left_arr_s and comp(12) right_arr_idx < right_arr_s)
	{
		if (comp(13) left_arr[left_arr_idx] <= right_arr[right_arr_idx])
		{
			array[merged_arr_idx] = left_arr[left_arr_idx]; ass(14)
			left_arr_idx++; ass(15)
		}
		else
		{
			array[merged_arr_idx] = right_arr[right_arr_idx]; ass(16)
			right_arr_idx++; ass(17)
		}
		merged_arr_idx++; ass(18)
	}
	while (comp(19) left_arr_idx < left_arr_s)
	{
		array[merged_arr_idx] = left_arr[left_arr_idx]; ass(20)
		left_arr_idx++; ass(21)
		merged_arr_idx++; ass(22)
	}

	while (comp(23) right_arr_idx < right_arr_s)
	{
		array[merged_arr_idx] = right_arr[right_arr_idx]; ass(24)
		right_arr_idx++; ass(25)
		merged_arr_idx++; ass(26)
	}
	delete[] left_arr; ass(27)
	delete[] right_arr; ass(28)
}

void MergeSort(int array[], int R, int L)
{
	if (comp(101) L >= R)
		return;
	int mid = L + (R - L) / 2; ass(102)
	MergeSort(array, mid, L);
	MergeSort(array, R, mid + 1);
	merge(array, L, mid, R);
}
