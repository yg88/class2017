#pragma once

class Canvas;

class GraphicsObject
{
public:
	GraphicsObject();
	virtual ~GraphicsObject();

	virtual void Draw(Canvas& canvas) = 0;
};

