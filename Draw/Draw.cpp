// Draw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Draw.h"

using namespace std;

// Canvas::Canvas(int width, int height)
// {
// 	buffer = new char *[height];
// 	for (int i = 0; i < height; ++i)
// 	{
// 		buffer[i] = new char[width];
// 	}
// 	for (int row = 0; row < height; ++row)
// 	{
// 		for (int column = 0; column < width; ++column)
// 		{
// 			buffer[row][column] = ' ';
// 		}
// 	}
// 	this->_width = width;
// 	this->_height = height;
// }

// #define CANVAS_HEIGHT 25
void Canvas::Init(int width, int height)
{
	this->buffer = new char *[height];
	for (int i = 0; i < height; ++i)
	{
		buffer[i] = new char[width];
	}
	for (int row = 0; row < height; ++row)
	{
		for (int column = 0; column < width; ++column)
		{
			buffer[row][column] = ' ';
		}
	}
	_width = width;
	_height = height;
}

void Canvas::DrawRectangle(
	int left, int top, int width, int height)
{
	for (int i = 0; i < width; ++i)
	{
		buffer[top][left + i] = 
			(buffer[top][left + i] == '|' ? '+' : '-');
		buffer[top + height - 1][left + i] = 
			(buffer[top + height - 1][left + i] == '|' ? '+' : '-');
	}
	for (int i = 0; i < height; ++i)
	{
		buffer[top + i][left] =
			(buffer[top + i][left] == '-'? '+' : '|');
		buffer[top + i][left + width - 1] =
			(buffer[top + i][left + width -1] == '-' ? '+' : '|');
	}
}

void Canvas::Output() const
{
	for (int row = 0; row < _height; ++row)
	{
		for (int column = 0; column < _width; ++column)
		{
			cout << buffer[row][column];
		}
		cout << "\n";
	}
}

void Canvas::Release()
{
	for (int i = 0; i < _height; ++i)
	{
		delete[]buffer[i];
	}

	delete[]buffer;
}

int main()
{
	Canvas canvas;
	canvas.Init(80, 25);

	for (;;)
	{
		cout << "Please input left, top, width, height: ";
		int left, top, width, height;
		cin >> left >> top >> width >> height;

		canvas.DrawRectangle(left, top, width, height);
		canvas.Output();
	}

	canvas.Release();

    return 0;
}


