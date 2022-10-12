#include "Aeroflot.h"

Aeroflot::Aeroflot()
{
	punkt = "";
	number = 0;
	type = "";
}
Aeroflot::Aeroflot(string a, string c, int b)
{
	punkt = a;
	number = b;
	type = c;
}

bool Aeroflot::operator=(const Aeroflot a)
{
	punkt = a.punkt;
	number = a.number;
	type = a.type;
	return this;
}

bool Aeroflot::operator==(const Aeroflot a)
{
	return punkt.compare(a.punkt) == 0;
}

bool Aeroflot::operator!=(const Aeroflot a)
{
	return punkt.compare(a.punkt) != 0;
}

ostream& operator<<(ostream& os, const Aeroflot& a)
{
	os << a.punkt << " " << a.type << " " << a.number;
	return os;
}

istream& operator>>(istream& is, Aeroflot& a)
{
	is >> a.punkt >> a.type >> a.number;
	return is;
}

bool Aeroflot::operator>(const Aeroflot& a)
{
	return punkt.compare(a.punkt) > 0;
}

bool Aeroflot::compPunkt(const Aeroflot& a, const Aeroflot& b)
{
	return a.punkt.compare(b.punkt) > 0;
}

bool Aeroflot::compType(const Aeroflot& a, const Aeroflot& b)
{
	return a.type.compare(b.type) > 0;
}

bool Aeroflot::compNumber(const Aeroflot& a, const Aeroflot& b)
{
	return a.number > b.number;
}

bool Aeroflot::comp(const Aeroflot& a, const Aeroflot& b)
{
	if (a.punkt.compare(b.punkt) == 0) {
		if (a.type.compare(b.type) == 0) {
			return a.number > b.number;
		}
		else {
			return a.type.compare(b.type) > 0;
		}
	}
	return a.punkt.compare(b.punkt) > 0;
}
