#include "Rectangle.h"
#include "Canvas.h"

int Rectangle::s_object_count = 0;

Rectangle::Rectangle(int left, int top, int width, int height) :
	_left{left}, _top{top}, _width{width}, _height{height},
	_id{s_object_count++}
{
}

Rectangle::Rectangle(const Rectangle& source) :
	_left{source._left},
	_top{source._top},
	_width {source._width},
	_height {source._height}
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::Draw(Canvas& canvas)
{
	canvas.DrawRectangle(_left, _top, _width, _height);
}
