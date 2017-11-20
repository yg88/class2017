// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	std::cout << "Please input two numbers:\n";
	int a, b;
	std::cin >> a >> b;
	std::cout << "Sum of " << a << " and " << b << " is " << a + b << std::endl;

    return 0;
}

