// MemoryDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void swap(int a, int b)
{
	int t;
	t = a;
	a = b;
	b = t;

	std::cout << a << " " << b;
}

void swap2(int * pa, int * pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

void swap3(int *pa, int * pb)
{
	int * t = pa;
	pa = pb;
	pb = t;
}

void swap4(int & x, int & y)
{
	int t = x;
	x = y;
	y = t;
}

void Print(const int &a)
{
	std::cout << a << std::endl;
	// a = 5;
}

int main()
{
	int a = 3, b = 4;
	// swap3(&a, &b);
	swap4(a, b);
	Print(a);
	std::cout << a << " " << b;

    return 0;
}

