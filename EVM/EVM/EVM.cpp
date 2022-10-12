#include <iostream>
#include "List.h"
#include "MyArray.h"
#include "Aeroflot.h"


using namespace std;

int main()
{
	MyArray<Aeroflot> h;
	ifstream in("Text.txt");
	in >> h;
	cout << h << "\n";
	h.sort(Aeroflot::comp);
	cout << h;

	return 0;
}
