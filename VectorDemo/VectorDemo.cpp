// VectorDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include <stdlib.h>

Vector RandomGenerate(size_t count)
{
	Vector v(count);
	for (size_t i = 0; i < count; ++i)
	{
		v[i] = rand();
	}

	return v;
}

int main()
{
	Vector v(1000);

	for (size_t i = 0; i < 1000; ++i)
	{
		v[i] = i;
	}

	// v.reserve(1000);
	// v.resize(1000);

// 	for (size_t i = 0; i < 1000; ++i)
// 	{
// 		std::cout << v.at(i) << "\t";
// 	}

	v[0] = 100;


	Vector v2;
	v2 = v;

	Vector v3{ v }; // Vector v3(v); Vector v3 = v;

// 	for (size_t i = 0; i < 1000; ++i)
// 	{
// 		std::cout << v3[i] << "\t";
// 	}

	Vector v4 = RandomGenerate(1000);

	std::cout << v4 << std::endl << 1000;

    return 0;
}


