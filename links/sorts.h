#pragma once
#include <iostream>
#include <random>
#include "utils.h"

void swap(int& a, int& b, int line);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int* arr, int R, int L = 0);
void shakerSort(int* a, int n);
void merge(int* array, int L, int mid, int R);
void MergeSort(int* array, int R, int L = 0);