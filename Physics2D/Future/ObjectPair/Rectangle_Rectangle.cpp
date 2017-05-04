#include "Rectangle_Rectangle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Rectangle_Rectangle::Rectangle_Rectangle(Rectangle& rectangle1, Rectangle& rectangle2)
: _Rectangle1(rectangle1)
, _Rectangle2(rectangle2)
{
}


bool Rectangle_Rectangle::Contains(const Object* object) const
{
	return object == &_Rectangle1 || object == &_Rectangle2;
}


bool Rectangle_Rectangle::IsCollision()
{
	return false;
}


void Rectangle_Rectangle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
