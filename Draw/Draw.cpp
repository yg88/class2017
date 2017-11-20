#include "Canvas.h"
#include <iostream>

using namespace std;

int main()
{
	Canvas canvas(80, 25);

	for (;;)
	{
		cout << "Please input left, top, width, height: ";
		int left, top, width, height;
		cin >> left >> top >> width >> height;

		canvas.DrawRectangle(left, top, width, height);
		canvas.Output();
	}

	return 0;
}

