#include <iostream>
#include "../Graphics/Line.h"
#include "../Graphics/Bitmap.h"

using namespace std;
using namespace Graphics;


int main()
{
	Line line;
	Bitmap bitmap;

	cout << "Line Test " << endl;

	line.Draw(bitmap);

	cin.get();

    return 0;
}
