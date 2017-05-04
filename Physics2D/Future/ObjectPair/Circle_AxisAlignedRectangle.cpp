#include "Circle_AxisAlignedRectangle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Circle_AxisAlignedRectangle::Circle_AxisAlignedRectangle(Circle& circle, AxisAlignedRectangle& rectangle)
	: _Circle(circle)
	, _Rectangle(rectangle)
{
}


bool Circle_AxisAlignedRectangle::Contains(const Object* object) const
{
	return object == &_Circle || object == &_Rectangle;
}


bool Circle_AxisAlignedRectangle::IsCollision()
{
	return false;
}


void Circle_AxisAlignedRectangle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
