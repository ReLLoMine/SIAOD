#include "map.h"

uint64_t hash(std::string val)
{
	uint64_t sum = (uint64_t) 'S';
	for (size_t i = 0; i < val.size(); i++)
		sum += (int)val[i];

	uint64_t val1 = (uint64_t) 'C';
	for (size_t i = 0; i < val.size(); i++)
		val1 += (uint64_t)val[i] << ((i * 5) % 64);

	uint64_t val2 = ~(val1 << 32) + (val1 >> 32);
	val2 %= ~(val1) >> 32;
	return ((val1 / val2) << 16) + ((val2 / val1) << 32) + (val2 % (val1 << 16)) + sum;
}