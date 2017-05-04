#include "Rectangle_AxisAlignedRectangle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Rectangle_AxisAlignedRectangle::Rectangle_AxisAlignedRectangle(Rectangle& rectangle1, AxisAlignedRectangle& rectangle2)
	: _Rectangle1(rectangle1)
	, _Rectangle2(rectangle2)
{
}


bool Rectangle_AxisAlignedRectangle::Contains(const Object* object) const
{
	return object == &_Rectangle1 || object == &_Rectangle2;
}


bool Rectangle_AxisAlignedRectangle::IsCollision()
{
	return false;
}


void Rectangle_AxisAlignedRectangle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
