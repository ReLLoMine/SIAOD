#pragma once
#include "misc.h"
#include "lists.h"

class Goods
{
public:
	std::string code;
	int sale_date;
	bool refund;
	int refund_date;

	Goods(std::string code, int sale_date, bool refund, int refund_date=0);
	operator std::string();
	bool operator<(const Goods& first);
	bool operator<=(const Goods& first);
	bool operator>(const Goods& first);
	bool operator>=(const Goods & first);
	friend std::ostream& operator<<(std::ostream& os, const Goods& first);
};

Goods get_random_goods();