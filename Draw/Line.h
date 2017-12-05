#pragma once

#include "GraphicsObject.h"

class Canvas;

class Line : public GraphicsObject
{
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();

	virtual void Draw(Canvas& canvas) override;
private:
	int _x1;
	int _x2;
	int _y1;
	int _y2;
};

