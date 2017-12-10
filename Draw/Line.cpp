#include "Line.h"

#include "Canvas.h"

Line::Line(int x1, int y1, int x2, int y2) :
	_x1{ x1 }, _y1{ y1 }, _x2{ x2 }, _y2{ y2 }
{
}

Line::~Line()
{
}

void Line::Draw(Canvas& canvas)
{
	canvas.DrawLine(_x1, _y1, _x2, _y2);
}
