#pragma once
#include <iostream>
#include <fstream>
#include "sortirovki.h"
using namespace std;
template <class T>

class MyArray {
	T* arr; int n;
	void copy(T* a, int n) {
		for (int i = 0; i < n; i++)
			arr[i] = a[i];
	}
public:

	MyArray() {
		arr = NULL;
		n = 0;
	}
	MyArray(T* a, int s) {
		this->n = s;
		arr = new T[n];
		copy(a, s);
	}
	MyArray(int s) {
		this->n = s;
		arr = new T[n];
	}
	MyArray(const MyArray& a) {
		this->n = a.n;
		arr = new T[n];
		copy(a.arr, a.n);
	}
	~MyArray() {
		delete[] arr;
	}
	MyArray& operator =(const MyArray& s) {
		delete[] arr;
		this->n = s.n;
		arr = new T[n];
		copy(s.arr, s.n);
		return *this;
	}
	T& operator [](int i) {
		if (i < 0 || i >= n)
			throw 1;
		return arr[i];
	}
	void sort(bool(*comp)(const T&, const T&)) {
		Shell(arr, n, comp);
	}
	friend ostream& operator <<(ostream& os, const MyArray& a) {
		for (int i = 0; i < a.n; i++)
			os << a.arr[i] << "\n";
		return os;
	}
	friend istream& operator>>(istream& os, MyArray& a) {
		os >> a.n;
		if (a.arr != NULL)a.~MyArray();
		a.arr = new T[a.n];
		for (int i = 0; i < a.n; i++)
			os >> a.arr[i];
		return os;
	}

};
