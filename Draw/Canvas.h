#pragma once

class Canvas
{
public:
	Canvas(int width, int height); // constructor
	~Canvas();	// destructor

	void DrawRectangle(int left, int top, int width, int height);
	void DrawLine(int x1, int y1, int x2, int y2);
	void Output() const;
	void Clear();

private:
	void Init(int width, int height);
	void Release();

	char ** _buffer;
	int _width;
	int _height;
};
