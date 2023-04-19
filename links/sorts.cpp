#include "sorts.h"

void swap(int& a, int& b, int line)
{
	int tmp = a; ass(line)
		a = b; ass(line)
		b = tmp; ass(line)
}

// ������� ���������� ������� ������� �������
void insertionSort(int arr[], int n)
{
	for (int i = 1; comp(82) i < n; i++) { // ���� �� ���� ��������� �������, ������� � �������
		int key = arr[i]; ass(83) // ��������� ������� ������� � ���������� key
			int j = i - 1; ass(84) // �������� ���������� � ���������� ���������
			// ���� ���������� ������� ������ �������� � �� �� ����� �� ������ �������
			while (comp(86) j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j]; ass(87) // �������� �������� ������
					j--; ass(88) // ��������� � ���������� �������� �����
			}
		arr[j + 1] = key; ass(90) // ��������� ������� ������� �� ���������� �����
	}
}

// ������� ���������� ������� �������� ������
void selectionSort(int arr[], int n)
{
	int minIndex, tmp;
	for (int i = 0; comp(97) i < n - 1; i++) {
		minIndex = i; ass(98) // ����������� ������� ��������� �� i-�� �������
			for (int j = i + 1; comp(99) j < n; j++) {
				if (comp(100) arr[j] < arr[minIndex])
				{
					minIndex = j; ass(102) // ������ ����� ����������� �������
				}
			}
		// ������ ������� i-�� � ����������� ��������
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

// ������� ���������� ������� �������
void shakerSort(int* a, int n)
{
	int left = 0; ass(1)
		int right = n - 1; ass(2)
		bool sorted = false; ass(3)
		int tmp; ass(4)

		while (comp(5) left <= right and not sorted)
		{
			sorted = true; ass(6)

				for (int i = right; comp(7) i >= left; i--) // ������ ������ ������
				{
					if (comp(8) a[i - 1] > a[i])
					{
						swap(a[i - 1], a[i], 9);
						sorted = false; ass(10)
					}
				}
			if (comp(11) sorted) // �����, ���� �� ���� ������������
				break;
			sorted = true; ass(12)

				left++; ass(13)
				for (int i = left; comp(14) i <= right; i++) // ������ ����� �������
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

// ������� ���������� ������� �������� ������ (������� ���������� � �������)
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


// ������� ���������� ������� �������� ������ (����������� �������)
void MergeSort(int array[], int R, int L)
{
	if (comp(101) L >= R)
		return;
	int mid = L + (R - L) / 2; ass(102)
		MergeSort(array, mid, L);
	MergeSort(array, R, mid + 1);
	merge(array, L, mid, R);
}

int Split(int N, const char* file_a, const char* file_b, const char* file_in) // 1-7 ������ ���������
{
	// ��������� ���� generated_data.txt ��� ������
	std::ifstream input(file_in);
	// ��������� ���� A.txt ��� ������
	std::ofstream output_a(file_a);
	// ��������� ���� B.txt ��� ������
	std::ofstream output_b(file_b);
	// ������� ������ ��� �������� ��������� ��������
	std::vector<std::string> buf;
	// ������ ���� generated_data.txt ��������� � ���������� � ����� A.txt � B.txt
	std::string line;
	int count = 0;
	while (getline(input, line)) // ������ ���� ��������� � ���������� � ���������� line
	{
		if (count < N) // ���� ���������� ��������� ����� ������ N, �� ��������� ������� buf
		{
			buf.push_back(line);
			if (count == N - 1) // ���� buf ��������, �� ��������� ���������� � ������ � output_a
			{
				sort(buf.begin(), buf.end());
				for (int i = 0; i < buf.size(); i++)
				{
					output_a << buf[i] << '\n';
				}
				buf.clear(); // ������� ����� ����� ������
			}
			count++;
		}
		else // ���� ���������� ��������� ����� ������ ��� ����� ������� ����� N, �� ���������� � buf � � output_b
		{
			buf.push_back(line);
			count++;
			if (count == 2 * N) // ���� buf �������� ������ ���, �� ��������� ���������� � ������ � output_b
			{
				sort(buf.begin(), buf.end());
				for (int i = 0; i < buf.size(); i++)
				{
					output_b << buf[i] << '\n';
				}
				// ���� buf �������� ������ ���, �� ��������� ���������� � ������ � output_b
				count = 0;
				buf.clear();
			}
		}
	}
	// ��������� ��� �������� �����
	input.close();
	output_a.close();
	output_b.close();
	// ��������� ���� generated_data.txt ��� ������
	std::ofstream output(file_in);

	// ��������� ���� A.txt ��� ������
	std::ifstream input_a(file_a);

	// ��������� ���� B.txt ��� ������
	std::ifstream input_b(file_b);

	while (getline(input_a, line))
	{
		output << line << '\n';
	}
	while (getline(input_b, line))
	{
		output << line << '\n';
	}
	return 0;
}


int split(int N, const char* file_a, const char* file_b, const char* file_in)
{
	// ��������� ���� generated_data.txt ��� ������
	std::ifstream input(file_in);
	if (!input) {
		std::cerr << "Cannot open file " << file_in << " for reading\n";
		return 1;
	}

	// ��������� ���� A.txt ��� ������
	std::ofstream output_a(file_a);
	if (!output_a) {
		std::cerr << "Cannot open file " << file_a << " for writing\n";
		return 1;
	}

	// ��������� ���� B.txt ��� ������
	std::ofstream output_b(file_b);
	if (!output_b) {
		std::cerr << "Cannot open file " << file_b << " for writing\n";
		return 1;
	}

	// ������ ���� generated_data.txt ��������� � ���������� � ����� A.txt � B.txt
	std::string line;
	int count = 0;
	while (getline(input, line))
	{
		if (count < N)
			output_a << line << '\n';
		else
			output_b << line << '\n';

		count++;
		if (count == 2 * N)
			count = 0;
	}

	// ��������� ��� �������� �����
	input.close();
	output_a.close();
	output_b.close();

	return 0;
}