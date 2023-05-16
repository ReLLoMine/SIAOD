#include "structs.h"


Goods::Goods(std::string code, int sale_date, bool refund, int refund_date)
{
	this->code = code;
	this->sale_date = sale_date;
	this->refund = refund;
	this->refund_date = refund_date;
}

Goods::operator std::string()
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
	return os;
}

Goods get_random_goods()
{
	srand(time(0));
	return Goods("ABC", rand() % 32, rand() % 2, rand() % 32);
}