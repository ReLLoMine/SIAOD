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

void recur_push_back(sll::list<int>& list, size_t depth)
{
	if (!depth)
		return;
	ass(2);
	list.push_back(io.input<int>());
	recur_push_back(list, --depth);
}

void recur_pop_front(sll::list<int>& list)
{
	if (list.is_empty())
		return;
	ass(3);
	io.output(list.first->val, " ");
	list.remove_first();
	recur_pop_front(list);
}

void recur_queue()
{
	sll::list<int> list;
	size_t lenght = io.input<int>("Length: ");
	recur_push_back(list, lenght);
	io.output("Queue: ");
	recur_pop_front(list);
	io.output("\nPush back calls: ", "");
	io.output(counter[2]);
	io.output("Push back calls: ", "");
	io.output(counter[3]);
}