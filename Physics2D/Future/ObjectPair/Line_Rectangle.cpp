#include "Line_Rectangle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Line_Rectangle::Line_Rectangle(Line& line, Rectangle& rectangle)
	: _Line(line)
	, _Rectangle(rectangle)
{
}


bool Line_Rectangle::Contains(const Object* object) const
{
	return object == &_Line || object == &_Rectangle;
}


bool Line_Rectangle::IsCollision()
{
	return false;
}


void Line_Rectangle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
