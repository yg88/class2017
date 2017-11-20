// MemoryAllocation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

void Output(int * weights, int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << weights[i] << std::endl;
	}
	weights = nullptr;
}

void Test()
{
	int * weights = nullptr;

	std::cout << "Please input the number of students in your class:";
	int student_count;
	std::cin >> student_count;

	weights = new int[student_count];

	for (int i = 0; i < student_count; ++i)
	{
		std::cout << "Please input: ";
		std::cin >> weights[i];
	}

	Output(weights, student_count);
	//...
	delete[]weights;

	weights = nullptr;
}

void Test2()
{
	int * weights = nullptr;

	int student_count = 0;
	int capacity = 2;
	weights = new int[capacity];

	for (;;)
	{
		std::cout << "Please input: ";
		int weight;
		std::cin >> weight;

		if (weight == -1)
			break;

		++student_count;
		if (student_count > capacity)
		{
			int * temp = new int[capacity * 2];
			for (int i = 0; i < capacity; ++i)
			{
				temp[i] = weights[i];
			}
			delete weights;
			weights = temp;
			capacity *= 2;
		}

		weights[student_count - 1] = weight;
	}

	Output(weights, student_count);
	//...
	delete[]weights;

	weights = nullptr;
}

int main()
{
	std::vector<int> weights;

	for (;;)
	{
		std::cout << "Please input: ";
		int w;
		std::cin >> w;
		if (w == -1)
			break;

		weights.push_back(w);
	}

    return 0;
}

