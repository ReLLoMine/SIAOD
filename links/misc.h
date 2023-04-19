#pragma once

#include <iostream>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stack>
#include <fstream>
#include <sstream>
#include <locale>
#include <cassert>
#include <iomanip>


#define forinrange(var, end) for(int var = 0; var < end; var++)
#define forinranges(var, start, end) for(int var = start; var < end; var++)
#define forinrangess(var, start, end, step) for(int var = start; var < end; var += step)
#define forinrangessr(var, start, end, step) for(int var = start; var > end; var += step)

#define ll long long
#define self this->
#define LINE "============================================"

#define eps 0.00000001

bool is_eq(double val1, double val2);
bool is_zero(double val);
void yes_no();
void incorrect_input();
int sizef(const char* filen);

template <typename T>
std::string to_stringtm(T num, int precision = 0)
{
	std::ostringstream strs;
	strs << std::fixed << std::setprecision(precision) << num;
	return strs.str();
}

class MyRandom
{
private:
	ll int m, b, c;
	ll int prev = 0;
public:
	MyRandom(ll int m, ll int b, ll int c)
	{
		self m = m;
		self b = b;
		self c = c;
		self get();
	}

	ll int get()
	{
		self prev = (self m * self prev + self b) % self c;
		return self prev;
	}
};

class IO
{
private:
public:

	std::string getline(std::string prompt = "")
	{
		std::cout << prompt;
		std::string res;
		char buf;

		std::cin.get(buf);

		if (buf != '\n')
			res += buf;

		while (std::cin.get(buf))
		{
			if (buf != '\n')
				res += buf;
			else
				break;
		}
		return res;
	}

	template<typename T>
	T input(std::string prompt = "", bool wait = false);

	template<typename T>
	void output(T val, std::string end = "\n");

	template<typename T>
	T finput(std::ifstream& ifs);

	template<typename T>
	void foutput(T val, std::ofstream& ofs, std::string end = "\n");
};

template<typename T>
T IO::input(std::string prompt, bool wait)
{
	T in;
	bool succes = false;

	while (not succes)
	{
		std::cout << prompt;
		std::cin >> in;

		if (std::cin.fail())
		{
			std::cout << "Wrong type! <" << typeid(T).name() << "> expected." << std::endl;
			std::cin.clear();
			std::string shit;
			std::cin >> shit;
			succes = not wait;
		}
		else
			succes = true;
	}

	return in;
}

template<typename T>
void IO::output(T val, std::string end)
{
	std::cout << val << end;
}

template<typename T>
T IO::finput(std::ifstream& ifs)
{
	T in;

	ifs >> in;

	if (ifs.fail())
	{
		std::cout << "File reading error. Wrong type! <" << typeid(T).name() << "> expected." << std::endl;
		ifs.clear();
		std::string shit;
		ifs >> shit;
	}

	return in;
}

template<typename T>
void IO::foutput(T val, std::ofstream& ofs, std::string end)
{
	ofs << val << end;
}

template <typename T>
class Matrix
{
private:
	std::vector<std::vector<T>> matrix;
	bool empty = true;

public:
	Matrix() {};

	Matrix(std::vector<std::vector<T>> matrix)
	{
		self matrix = matrix;
		self empty = matrix.empty();
	}

	Matrix(std::initializer_list<std::vector<T>> list)
	{
		for (auto row : list)
		{
			self push_back(row);
		}
	}

	void push_back(std::vector<T> item)
	{
		if (not self empty and (self matrix[0].size() != item.size()))
			item.resize(self matrix[0].size());

		empty = false;
		self matrix.push_back(item);
	}

	T get(int row, int col)
	{
		return self matrix[row - 1][col - 1];
	}

	// ROWS COUNT
	size_t rows()
	{
		return self matrix.size();
	}

	// COLS COUNT
	size_t cols()
	{
		if (self matrix.size())
			return self matrix[0].size();
		else
			return 0;
	}

	std::string to_string(bool format = true, int precision = 0)
	{
		std::string res;

		for (auto row : self matrix)
		{
			int count = 0;
			if (format)
				res += "| ";

			for (auto item : row)
			{
				count++;
				res += to_stringtm(item, precision);

				if (count != row.size())
					res += ' ';
			}

			if (format)
				res += " |";
			res += '\n';
		}
		return res;
	}

	std::vector<T>& operator[] (int index)
	{
		return self matrix[index];
	}

	Matrix transposed()
	{
		Matrix res;

		for (int i = 0; i < self rows(); i++)
			res.matrix.push_back(std::vector<T>());

		for (auto row : self matrix)
		{
			int count = 0;

			for (auto item : row)
			{
				res[count].push_back(item);
				count++;
			}
		}

		return res;
	}

	Matrix operator* (Matrix& obj)
	{
		Matrix res;

		if (self cols() == obj.rows())
		{
			forinrange(i, self rows())
			{
				std::vector<T> row;

				forinrange(j, obj.cols())
				{
					T num = 0;

					forinrange(k, self cols())
					{
						num += self get(i + 1, k + 1) * obj.get(k + 1, j + 1);
					}

					row.push_back(num);
				}

				res.matrix.push_back(row);
			}

			return res;
		}
		else
		{
			throw std::exception("Cols of left matrix must be equal of rows of right matrix.");
		}
	}
};

