#include <iostream>
#include "../Graphics/Point.h"
#include "../Graphics/Line.h"
#include "../Graphics/Bitmap.h"
#include "../Graphics/Window.h"

using namespace std;
using namespace Graphics;


int main()
{
	try
	{
		Window window(0, 0, 1000, 1100);
		Canvas canvas(window.ClientHeight(), window.ClientWidth());

		Point point(100, 200, Color(255, 0, 0, 255));
		Line line(200, 300, 400, 500, Color(0, 255, 0, 255));
		Bitmap bitmap(600, 700, 100, 200, Color(0, 0, 255, 255));

		canvas.Draw(point);
		canvas.Draw(line);
		canvas.Draw(bitmap);
		window.Draw(canvas);

		cin.get();
	}
	catch ( exception& e )
	{
		cout << e.what() << endl;
		cin.get();
	}

    return 0;
}
