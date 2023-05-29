#include "recursion.h"

int recur_max(const std::vector<int>& arr, size_t left, size_t right)
{
	ass(1);
	if (right - left < 2)
		return std::max(arr[left], arr[right]);
	size_t mid = (left + right) / 2;
	return std::max(recur_max(arr, left, mid), recur_max(arr, mid + 1, right));
}

int lin_max(const std::vector<int>& arr)
{
	int maxVal = arr[0];
	for (auto pos : arr)
	{
		if (pos > maxVal)
			maxVal = pos;
	}
	return maxVal;
}