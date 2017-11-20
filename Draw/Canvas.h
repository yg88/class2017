#pragma once

class Canvas
{
public:
	Canvas(int width, int height); // constructor
	~Canvas();	// destructor

	void DrawRectangle(int left, int top, int width, int height);
	void Output() const;

private:
	void Init(int width, int height);
	void Release();

	char ** _buffer;
	int _width;
	int _height;
};
