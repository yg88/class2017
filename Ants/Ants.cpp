// Ants.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
const unsigned int BAR_LENGTH = 78;

struct Ant
{
	unsigned int position;
	int direction; // -1 for left, +1 for right
};

void DrawRectangle(unsigned int row_count, unsigned int column_count)
{
	for (unsigned int row = 0; row < row_count; ++row)
	{
		for (unsigned int column = 0; column < column_count; ++column)
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}
}

void Wait()
{
	for (unsigned int j = 0; j < 2000000; ++j)
	{
		double y = sin(cos(sin(j * 0.8)));
	}
}

void Test1()
{
	for (int i = 0; i < 75; ++i)
	{
		cout << "*";
		Wait();
		cout << "\b ";
	}
}

void DrawBar(const vector<int>& bar)
{
	vector<char> symbols = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', };
	cout << '\r';

	for (auto element : bar)
	{
		if (element >= 0 && element < symbols.size())
		{
			cout << symbols[element];
		}
	}
}

int FindAnotherAnt(unsigned int ant_index, const vector<Ant>& ants)
{
	for (int i = 0; i < ants.size(); ++i)
	{
		if (ants[i].position == ants[ant_index].position && i != ant_index)
			return i;
	}

	return -1;
}

bool NeedTurnAround(unsigned int ant_index,
	const vector<int>& bar,
	const vector<Ant>& ants)
{
	int another_ant = FindAnotherAnt(ant_index, ants);
	if (another_ant != -1 &&
		(ants[another_ant].direction != ants[ant_index].direction))
	{
		return true;
	}

	int next_position = ants[ant_index].position + ants[ant_index].direction;
	if (next_position < 0 || next_position >= bar.size())
		return false;

	if (bar[next_position] != 0)
	{
		if ((ants[bar[next_position] - 1].direction != ants[ant_index].direction) ||
			((ants[bar[next_position] - 1].direction == ants[ant_index].direction) &&
				NeedTurnAround(bar[next_position] - 1, bar, ants)))
		{
			return true;
		}
	}

	return false;
}

void UpdateAnts(vector<Ant>& ants, const vector<int>& bar)
{
	vector<Ant> ants_snapshot{ ants };

	for (unsigned int i = 0; i < ants.size(); ++i)
	{
		if (NeedTurnAround(i, bar, ants_snapshot))
		{
			ants[i].direction *= -1;
			ants[i].position += ants[i].direction;
		}
		else
		{
			ants[i].position += ants[i].direction;
		}
	}
}

void ResetBar(vector<int>& bar)
{
	for (auto& element : bar)
	{
		element = 0;
	}
}

void UpdateBar(vector<int>& bar, const vector<Ant>& ants)
{
	ResetBar(bar);

	for (unsigned int i = 0; i < ants.size(); ++i)
	{
		if (ants[i].position >= 0 && ants[i].position < BAR_LENGTH)
		{
			bar[ants[i].position] = i + 1;
		}
	}
}

void InitAnts(vector<Ant>& ants)
{
	Ant ant;
	ant.position = 0;
	ant.direction = 1;
	ants.push_back(ant);

// 	ant.position = 1;
// 	ant.direction = 1;
// 	ants.push_back(ant);

	ant.position = 12;
	ant.direction = 1;
	ants.push_back(ant);

	ant.position = BAR_LENGTH - 1;
	ant.direction = -1;
	ants.push_back(ant);

// 	ant.position = 51;
// 	ant.direction = 1;
// 	ants.push_back(ant);
}

const unsigned int ANT_COUNT = 3;

int main()
{
	std::vector<int> bar(BAR_LENGTH, 0);
	vector<Ant> ants;

	InitAnts(ants);

	for (int j = 0; j < bar.size(); ++j)
	{
		UpdateBar(bar, ants);
		DrawBar(bar);
		Wait();
		UpdateAnts(ants, bar);
	}

	cout << "\n";

    return 0;
}

