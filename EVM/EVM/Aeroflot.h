#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Aeroflot
{
private:
	string punkt;
	string type;
	int number;
public:
	Aeroflot();
	Aeroflot(string a, string c, int b);
	bool operator =(const Aeroflot a);
	bool operator ==(const Aeroflot a);
	bool operator !=(const Aeroflot a);
	friend ostream& operator <<(ostream& os, const Aeroflot& a);
	friend istream& operator >>(istream& is, Aeroflot& a);
	bool operator>(const Aeroflot& a);
	static bool compPunkt(const Aeroflot& a, const Aeroflot& b);
	static bool compType(const Aeroflot& a, const Aeroflot& b);
	static bool compNumber(const Aeroflot& a, const Aeroflot& b);
	static bool comp(const Aeroflot& a, const Aeroflot& b);
};
