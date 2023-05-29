#pragma once
#include "misc.h"

using namespace std::chrono;

#define measure(function) {\
auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();\
function;\
std::cout << "Elapsed: " << duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start  << " microseconds" << std::endl;\
}

#define SIZE 1000

extern long long int counter[SIZE];
extern long long int sum;

	// n - номер строки
#define comp(n) ++counter[n] &&
#define ass(n) ++counter[n]

#define clear_arr for (auto &i : counter) i = 0; sum = 0

#define show_result for (auto i : counter)\
	{sum += i;}\
std::cout << "Compares/Assignments: " << sum << std::endl;\
for (int i = 0; i < SIZE; i++)\
	if (counter[i])\
		std::cout << i << ": " << counter[i] << std::endl
