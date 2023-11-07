#pragma once
#include "misc.h"

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