// RecursiveDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

// 1 1 2 3 5 8 13 21 ...
int Fibonacci(int n)
{
	if (n == 0 || n == 1)
		return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void Output(int n)
{
	std::cout << n << " ";
	if (n > 0)
	{
		Output(n - 1);
	}
}

void test()
{
	static int count = 0;
	++count;
	std::cout << count << std::endl;
}

void Hanoi(int n, char source, char dest, char temp)
{
	static int step_count = 0;
	if (n == 1)
	{
		std::cout << ++step_count << "\t: " 
			<< source << " ==> " << dest << std::endl;
	}
	else
	{
		Hanoi(n - 1, source, temp, dest);
		Hanoi(1, source, dest, temp);
		Hanoi(n - 1, temp, dest, source);
	}
}

// 1 
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
int yanghui(int row, int column)
{
	return (column == 1 || row == column) ? 1 :
		yanghui(row - 1, column - 1) + yanghui(row - 1, column);
}

void DrawYangHuiTriangle(int n)
{
	for (int row = 1; row <= n; ++row)
	{
		for (int i = 0; i < n - row; ++i)
		{
			std::cout << "   ";
		}

		for (int column = 1; column <= row; ++column)
		{
			int num = yanghui(row, column);
			if (num < 10)
			{
				std::cout << " " << num << "    ";
			}
			else
			{
				std::cout << std::setw(3) << num << "   ";
			}
		}
		std::cout << std::endl;

		if (row < n)
		{
			for (int i = 0; i < n - row; ++i)
			{
				std::cout << "   ";
			}
			for (int column = 1; column <= row; ++column)
			{
				std::cout << "/ \\   ";
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	// int count = 0;

	// Output(10);
	// Hanoi(10, 'a', 'c', 'b');
	DrawYangHuiTriangle(10);

    return 0;
}

