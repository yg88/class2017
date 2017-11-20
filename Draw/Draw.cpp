// Draw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Canvas
{
	char ** buffer;
	int width;
	int height;

	Canvas(int width, int height)
	{
		buffer = new char *[height];
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
		this->width = width;
		this->height = height;
	}
};

// #define CANVAS_HEIGHT 25
void InitCanvas(Canvas& canvas, int width, int height)
{
	canvas.buffer = new char *[height];
	for (int i = 0; i < height; ++i)
	{
		canvas.buffer[i] = new char[width];
	}
	for (int row = 0; row < height; ++row)
	{
		for (int column = 0; column < width; ++column)
		{
			canvas.buffer[row][column] = ' ';
		}
	}
	canvas.width = width;
	canvas.height = height;
}

// void InitCanvas(char canvas[CANVAS_HEIGHT][CANVAS_WIDTH], 
// 	int width, 
// 	int height)
// {
// 	for (int row = 0; row < CANVAS_HEIGHT; ++row)
// 	{
// 		for (int column = 0; column < CANVAS_WIDTH; ++column)
// 		{
// 			canvas[row][column] = ' ';
// 		}
// 	}
// }

void DrawRectangle(Canvas& canvas,
	int left, int top, int width, int height)
{
	for (int i = 0; i < width; ++i)
	{
		canvas.buffer[top][left + i] = 
			(canvas.buffer[top][left + i] == '|' ? '+' : '-');
		canvas.buffer[top + height - 1][left + i] = 
			(canvas.buffer[top + height - 1][left + i] == '|' ? '+' : '-');
	}
	for (int i = 0; i < height; ++i)
	{
		canvas.buffer[top + i][left] =
			(canvas.buffer[top + i][left] == '-'? '+' : '|');
		canvas.buffer[top + i][left + width - 1] =
			(canvas.buffer[top + i][left + width -1] == '-' ? '+' : '|');
	}

}

void OutputCanvas(const Canvas& canvas)
{
	for (int row = 0; row < canvas.height; ++row)
	{
		for (int column = 0; column < canvas.width; ++column)
		{
			cout << canvas.buffer[row][column];
		}
		cout << "\n";
	}
}

void ReleaseCanvas(Canvas& canvas)
{
	for (int i = 0; i < canvas.height; ++i)
	{
		delete[]canvas.buffer[i];
	}

	delete[]canvas.buffer;
}

int main()
{
	Canvas canvas(80, 25);
	// InitCanvas(canvas, CANVAS_WIDTH, CANVAS_HEIGHT);
	
	for (;;)
	{
		cout << "Please input left, top, width, height: ";
		int left, top, width, height;
		cin >> left >> top >> width >> height;

		DrawRectangle(canvas, left, top, width, height);
		OutputCanvas(canvas);
	}

	ReleaseCanvas(canvas);

    return 0;
}

