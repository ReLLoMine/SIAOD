#pragma once
#include "misc.h"
#include "lists.h"

typedef unsigned short int usint;

class Date
{
public:
	usint day;
	usint month;
	usint year;

	Date();
	Date(usint day, usint month, usint year);
	operator std::string() const;
	operator int() const;
	bool operator<(const Date& first);
	bool operator<=(const Date& first);
	bool operator>(const Date& first);
	bool operator>=(const Date& first);
	friend std::ostream& operator<<(std::ostream& os, const Date& first);
	friend std::istream& operator>>(std::istream& is, Date& first);
};

class Goods
{
public:
	std::string code;
	Date sale_date;
	bool refund;
	Date refund_date;

	Goods();
	Goods(std::string code, Date sale_date, bool refund, Date refund_date);
	operator std::string() const;
	bool operator<(const Goods& first);
	bool operator<=(const Goods& first);
	bool operator>(const Goods& first);
	bool operator>=(const Goods & first);
	friend std::ostream& operator<<(std::ostream& os, const Goods& first);
	friend std::istream& operator>>(std::istream& is, Goods& first);
};

Goods get_random_goods();
Date get_random_date();

void move_refund(dll::list<Goods> &list);
void delete_by_date(dll::list<Goods> &list, const Date date);