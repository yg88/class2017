#include "Canvas.h"
#include <iostream>
#include <vector>

#include "Rectangle.h"
#include "Line.h"

using namespace std;

void UpdateWindow(Canvas &canvas, vector<GraphicsObject*> &objects)
{
	canvas.Clear();

//  	for (int i = 0; i < objects.size(); ++i)
//  	{
// 		if (i <= 2)
// 		{
// 			reinterpret_cast<Rectangle*>(objects[i])->Draw(canvas);
// 		}
// 		else
// 		{
// 			reinterpret_cast<Line*>(objects[i])->Draw(canvas);
// 		}
//  	}
// 	for (auto iter = rectangles.begin(); iter != rectangles.end(); ++iter)
// 	{
// 		iter->Draw(canvas);
// 	}
	for (auto& object : objects)
	{
// 		Line* line = dynamic_cast<Line*>(object);
// 		if (line != nullptr)
// 		{
// 			line->Draw(canvas);
// 		}
// 		
// 		Rectangle * rectangle = dynamic_cast<Rectangle*>(object);
// 		if (rectangle != nullptr)
// 		{
// 			rectangle->Draw(canvas);
// 		}
		object->Draw(canvas);
	}

	canvas.Output();
}

int main()
{
	Canvas canvas(80, 25);
	vector<GraphicsObject*> objects;

	objects.push_back(new Rectangle(5, 5, 10, 10));
	objects.push_back(new Rectangle(8, 10, 20, 10));
	objects.push_back(new Rectangle(50, 0, 8, 9));

	objects.push_back(new Line(8, 0, 8, 10));
	objects.push_back(new Line(0, 3, 70, 3));

	UpdateWindow(canvas, objects);

// 	for (;;)
// 	{
// 		cout << "Please input left, top, width, height: ";
// 		int left, top, width, height;
// 		cin >> left >> top >> width >> height;
// 		Rectangle rectangle(left, top, width, height);
// 		rectangles.push_back(rectangle);
// 
// 		UpdateWindow(canvas, rectangles);
// 	}
	for (auto object : objects)
	{
		delete object;
	}

	return 0;
}

