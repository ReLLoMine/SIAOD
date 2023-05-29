#include "structs.h"

// DATE =============================

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

Date::Date(usint day, usint month, usint year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::operator int() const
{
	return day + month * 30 + year * 365;
}

Date::operator std::string() const
{
	std::stringstream s;
	s << std::setw(2) << std::setfill('0') << this->day << '.' << std::setw(2) << std::setfill('0') << this->month << '.' << this->year;
	return s.str();
}

bool Date::operator<(const Date& first)
{
	return (int)*this < (int)first;
}

bool Date::operator<=(const Date& first)
{
	return !(*this > first);
}

bool Date::operator>(const Date& first)
{
	return (int)*this > (int)first;
}

bool Date::operator>=(const Date& first)
{
	return !(*this < first);
}

std::ostream& operator<<(std::ostream& os, const Date& first)
{
	os << (std::string)first;
	return os;
}

std::istream& operator>>(std::istream& is, Date& first)
{
	std::string str;

	std::getline(is, str, '.');
	first.day = std::stoi(str);

	std::getline(is, str, '.');
	first.month = std::stoi(str);

	is >> str;
	first.year = std::stoi(str);

	return is;
}

// GOODS ==========================

Goods::Goods()
{
	this->code = "000000";
	this->refund = false;
}

Goods::Goods(std::string code, Date sale_date, bool refund, Date refund_date)
{
	this->code = code;
	this->sale_date = sale_date;
	this->refund = refund;
	this->refund_date = refund_date;
}

Goods::operator std::string() const
{
	return code;
}

bool Goods::operator<(const Goods& first)
{
	if (refund != first.refund)
		return refund < first.refund;
	else
		return code < first.code;
}

bool Goods::operator<=(const Goods& first)
{
	return !(*this > first);
}

bool Goods::operator>(const Goods& first)
{
	if (refund != first.refund)
		return refund > first.refund;
	else
		return code > first.code;
}

bool Goods::operator>=(const Goods& first)
{
	return !(*this < first);
}

std::ostream& operator<<(std::ostream& os, const Goods& first)
{
	os << first.code << " " << first.sale_date;
	if (first.refund)
		os << "\t Refund date: " << first.refund_date;
	return os;
}

std::istream& operator>>(std::istream& is, Goods& first)
{
	is >> first.code >> first.sale_date >> first.refund;
	if (first.refund)
		is >> first.refund_date;
	return is;
}

// FUNCTIONS =======

Goods get_random_goods()
{
	std::string code = "";
	const std::string alph = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (usint i = 0; i < 6; i++)
		code += alph[rand() % 36];
		
	return Goods(code, get_random_date(), rand() % 2, get_random_date());
}

Date get_random_date()
{
	return Date(1 + rand() % 31, 1 + rand() % 12, 1970 + rand() % 55);
}

void move_refund(dll::list<Goods> &list)
{
	if (list.first == list.last)
		return;

	dll::Node<Goods>* nodePtr = list.first->next;

	while (nodePtr)
	{
		dll::Node<Goods>* nextNodePtr = nodePtr->next;
		if (nodePtr->val.refund)
		{
			if(nodePtr->next)
				nodePtr->next->prev = nodePtr->prev;
			if(nodePtr->prev)
				nodePtr->prev->next = nodePtr->next;

			nodePtr->next = list.first;
			nodePtr->prev = nullptr;
			list.first = nodePtr;
		}
		nodePtr = nextNodePtr;
	}
}

void delete_by_date(dll::list<Goods> &list, const Date date)
{
	dll::Node<Goods>* nodePtr = list.first;

	while (nodePtr)
	{
		dll::Node<Goods>* nextNodePtr = nodePtr->next;
		if (nodePtr->val.sale_date < date)
		{
			list.remove(nodePtr);
		}
		nodePtr = nextNodePtr;
	}
}