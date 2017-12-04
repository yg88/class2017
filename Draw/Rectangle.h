#pragma once

class Canvas;

class Rectangle
{
public:
	Rectangle(int left, int top, int width, int height);
	Rectangle(const Rectangle& source);
	~Rectangle();

	void Draw(Canvas& canvas);

private:
	int _left;
	int _top;
	int _width;
	int _height;

	int _id;
	static int s_object_count;
};

