#include "misc.h"

IO io;

bool is_zero(double val)
{
	return abs(val) < eps;
}

bool is_eq(double val1, double val2)
{
	return abs(val1 - val2) < eps;
}

void yes_no()
{
	std::cout << "1.Yes\n0.No\n>:";
}

void incorrect_input()
{
	std::cout << "Incorrect input\n";
}

int sizef(const char* filen)
{
    std::ifstream file(filen);
    std::string line;
    int count = 0;
    while (getline(file, line)) {
        count++;
    }
    return count;
}