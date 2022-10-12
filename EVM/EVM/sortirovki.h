#pragma once

template <class T>

void bubble(T* a, int n) {
	T help;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1]) {
				flag = 1;
				help = a[i];
				a[i] = a[i + 1];
				a[i + 1] = help;
			}
	}
}

template <class T>

void bubble(T* a, int n, bool(*comp)(const T&, const T&)) {
	T help;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < n - 1; i++) {
			if (comp(a[i], a[i + 1])) {
				flag = 1;
				help = a[i];
				a[i] = a[i + 1];
				a[i + 1] = help;
			}
		}
	}
}


template<class T>

void Shell(T* a, int n, bool(*comp)(const T&, const T&))
{
	int j, gap, k;
	int step[5] = { 6, 4, 3, 2, 1 };
	for (k = 0; k < 5; k++)
	{
		gap = step[k];
		for (int i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && comp(a[j], a[j + gap]); j--)
			{
				T tmp = a[j];
				a[j] = a[j + gap];
				a[j + gap] = tmp;
			}
		}
	}
}


template <class T>

void Insert(T* a, int n, bool(*comp)(const T&, const T&))
{

	int j;
	for (int i = 1; i < n; i++)
	{
		T k = a[i];
		for (j = i - 1; j >= 0 && comp(a[j], k); j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = k;
	}
}


template <class T>

void Choose(T* a, int n, bool(*comp)(const T&, const T&))
{
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (comp(a[j], a[k]))
			{
				k = j;
			}
		}
		if (k != i)
		{
			T tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
	}
}


template <class T>

void bhor(T* a, int n, bool(*comp)(const T&, const T&)) {
	myqsort(a, 0, n - 1, comp);
}

template <class T>

void myqsort(T* a, int left, int right, bool(*comp)(const T&, const T&)) {
	int i = left; int j = right;
	T x, y;
	do {
		while (x > a[i]) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			T tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		bhor(a, j, comp);
}
