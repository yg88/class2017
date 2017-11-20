#pragma once

struct Canvas
{
	char ** buffer;
	int _width;
	int _height;

	//Canvas(int width, int height);
	void Init(int width, int height);
	void DrawRectangle(int left, int top, int width, int height);
	void Output() const;
	void Release();
};
