#include "Canvas.h"
#include <iostream>
#include <vector>
#include "Rectangle.h"

using namespace std;

int main()
{
	Canvas canvas(80, 25);
	vector<Rectangle> rectangles;

	for (;;)
	{
		cout << "Please input left, top, width, height: ";
		int left, top, width, height;
		cin >> left >> top >> width >> height;
		Rectangle rectangle(left, top, width, height);
		rectangles.push_back(rectangle);

		canvas.Clear();

		for (int i = 0; i < rectangles.size(); ++i)
		{
			rectangles[i].Draw(canvas);
		}

		canvas.Output();
	}

	return 0;
}

