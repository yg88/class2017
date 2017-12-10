// Draw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Canvas.h"

using namespace std;

Canvas::Canvas(int width, int height)
{
	Init(width, height);
}

Canvas::~Canvas()
{
	Release();
}

void Canvas::Init(int width, int height)
{
	this->_buffer = new char *[height];
	for (int i = 0; i < height; ++i)
	{
		_buffer[i] = new char[width];
	}

	_width = width;
	_height = height;

	Clear();
}

void Canvas::DrawRectangle(
	int left, int top, int width, int height)
{
	for (int i = 0; i < width; ++i)
	{
		_buffer[top][left + i] = 
			(_buffer[top][left + i] == '|' ? '+' : '-');
		_buffer[top + height - 1][left + i] = 
			(_buffer[top + height - 1][left + i] == '|' ? '+' : '-');
	}
	for (int i = 0; i < height; ++i)
	{
		_buffer[top + i][left] =
			(_buffer[top + i][left] == '-'? '+' : '|');
		_buffer[top + i][left + width - 1] =
			(_buffer[top + i][left + width -1] == '-' ? '+' : '|');
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
	{
		for (int row = y1; row <= y2; ++row)
		{
			_buffer[row][x1] = '|';
		}
	}
	else if (y1 == y2)
	{
		for (int column = x1; column <= x2; ++column)
		{
			_buffer[y1][column] = '-';
		}
	}
}

void Canvas::Output() const
{
	for (int row = 0; row < _height; ++row)
	{
		for (int column = 0; column < _width; ++column)
		{
			cout << _buffer[row][column];
		}
		cout << "\n";
	}
}

void Canvas::Clear()
{
	for (int row = 0; row < _height; ++row)
	{
		for (int column = 0; column < _width; ++column)
		{
			_buffer[row][column] = ' ';
		}
	}
}

void Canvas::Release()
{
	if (_buffer == nullptr)
		return;

	for (int i = 0; i < _height; ++i)
	{
		delete[]_buffer[i];
	}

	delete[]_buffer;
	_buffer = nullptr;
}

