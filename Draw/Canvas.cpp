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
	for (int row = 0; row < height; ++row)
	{
		for (int column = 0; column < width; ++column)
		{
			_buffer[row][column] = ' ';
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

