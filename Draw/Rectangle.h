#pragma once
#include "GraphicsObject.h"

class Canvas;

class Rectangle : public GraphicsObject
{
public:
	Rectangle(int left, int top, int width, int height);
	Rectangle(const Rectangle& source);
	~Rectangle();

	virtual void Draw(Canvas& canvas) override;

private:
	int _left;
	int _top;
	int _width;
	int _height;

	int _id;
	static int s_object_count;
};

