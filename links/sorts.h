#pragma once
#include <iostream>
#include <random>
#include "utils.h"
#include "misc.h"

void swap(int& a, int& b, int line);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int* arr, int R, int L = 0);
void shakerSort(int* a, int n);
void merge(int array[], int L, int mid, int R);
void MergeSort(int array[], int R, int L = 0);
int split(int N, const char* file_a, const char* file_b, const char* file_in);
int Split(int N, const char* file_a, const char* file_b, const char* file_in);

template <typename T>
void mergeFilesByN(const char* file_a, const char* file_b, const char* file_out, int n, int size)
{
	std::ifstream fileA(file_a), fileB(file_b);
	std::ofstream outputFile(file_out);

	T numA, numB;

	// Read n lines from each file
	std::deque<T> bufferA, bufferB;
	for (int k = 0; k < (size / 2) / n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			fileA >> numA;
			bufferA.push_back(numA);
			fileB >> numB;
			bufferB.push_back(numB);
		}

		// Merge the two buffers and write to output file
		while (bufferA.size() and bufferB.size())
		{
			if (bufferA.front() < bufferB.front())
			{
				outputFile << bufferA.front() << std::endl;
				bufferA.pop_front();
			}
			else
			{
				outputFile << bufferB.front() << std::endl;
				bufferB.pop_front();
			}
		}

		while (bufferA.size())
		{
			outputFile << bufferA.front() << std::endl;
			bufferA.pop_front();
		}

		while (bufferB.size())
		{
			outputFile << bufferB.front() << std::endl;
			bufferB.pop_front();
		}

		bufferA.clear();
		bufferB.clear();
	}
}