#pragma once

#include <format>
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
#include <ctime>
#include <chrono>
#include <typeinfo>
#include "date.h"
#include <bitset>


using std::chrono::time_point;
using std::chrono::seconds;
using std::chrono::milliseconds;

#define forinrange(var, end) for(int var = 0; var < end; var++)
#define forinranges(var, start, end) for(int var = start; var < end; var++)
#define forinrangess(var, start, end, step) for(int var = start; var < end; var += step)
#define forinrangessr(var, start, end, step) for(int var = start; var > end; var += step)

#define ll long long
#define self this->
#define LINE "============================================"

#define eps 0.00000001

#include "matrix.h"

std::string int_4bits(int num);
std::string int_8bits(int num);
std::string int_16bits(int num);
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

class FIO
{
private:
	std::ifstream _in;
	std::ofstream _out;
	std::string _in_path;
	std::string _out_path;
	std::string _mode;
	bool _was_error = false;
	bool _send_err = false;
public:

	FIO(std::string in, std::string out, std::string mode="")
	{
		this->_mode = mode;
		this->_in_path = in;
		this->_out_path = out;

		this->open();
	}

	~FIO()
	{
		this->close();
	}

	std::string getline(std::string prompt = "")
	{
		this->_out << prompt;
		std::string res;
		char buf;

		this->_in.get(buf);

		if (buf != '\n')
			res += buf;

		while (this->_in.get(buf))
		{
			if (buf != '\n')
				res += buf;
			else
				break;
		}
		return res;
	}

	void set_in(std::string in)
	{
		this->_in_path = in;
	}

	void set_out(std::string out)
	{
		this->_out_path = out;
	}

	void write(const char* data, unsigned long long size)
	{
		_out.write(data, size);
	}

	bool read(char* data, unsigned long long size)
	{
		return (bool) _in.read(data, size);
	}

	void move(size_t pos)
	{
		this->_in.seekg(pos, std::ios::beg);
	}

	bool is_open()
	{
		return _in.is_open() and _out.is_open();
	}

	bool is_inf_open()
	{
		return _in.is_open();
	}

	bool is_outf_open()
	{
		return _out.is_open();
	}

	bool open()
	{
		if (this->_mode == "bin")
		{
			if(this->_in_path.size())
				this->_in.open(this->_in_path, std::ios::binary);
			if (this->_out_path.size())
				this->_out.open(this->_out_path, std::ios::binary);
		}
		else
		{
			if (this->_in_path.size())
				this->_in.open(this->_in_path);
			if (this->_out_path.size())
				this->_out.open(this->_out_path);
		}

		return this->is_open();
	}

	bool open_inf()
	{
		if (this->_mode == "bin")
			if (this->_in_path.size())
				this->_in.open(this->_in_path, std::ios::binary);
		else
			if (this->_in_path.size())
				this->_in.open(this->_in_path);

		return this->is_inf_open();
	}

	bool open_outf()
	{
		if (this->_mode == "bin")
			if (this->_out_path.size())
				this->_out.open(this->_out_path, std::ios::binary);
		else
			if (this->_out_path.size())
				this->_out.open(this->_out_path);

		return this->is_outf_open();
	}

	void close()
	{
		_in.close();
		_out.close();
	}
	
	void close_inf()
	{
		_in.close();
	}

	void close_outf()
	{
		_out.close();
	}

	bool was_error()
	{
		return this->_was_error;
	}

	void clear_error()
	{
		this->_was_error = false;
	}

	bool is_end()
	{
		return this->_in.eof();
	}

	template<typename T>
	T input(std::string prompt = "", bool wait = false);

	template<typename T>
	void output(T val, std::string end = "\n");
};

template<typename T>
T FIO::input(std::string prompt, bool wait)
{
	T in;
	bool succes = false;

	while (not succes)
	{
		this->_out << prompt;
		this->_in >> in;

		if (this->_in.fail())
		{	
			if(_send_err)
				this->_out << "Wrong type! <" << typeid(T).name() << "> expected." << std::endl;
			this->_in.clear();
			std::string shit;
			this->_in >> shit;
			succes = not wait;
			_was_error = true;
		}
		else
		{
			succes = true;
			_was_error = false;
		}
	}

	return in;
}

template<typename T>
void FIO::output(T val, std::string end)
{
	this->_out << val << end << std::flush;
}

