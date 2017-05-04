#include "Line_AxisAlignedRectangle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Line_AxisAlignedRectangle::Line_AxisAlignedRectangle(Line& line, AxisAlignedRectangle& rectangle)
	: _Line(line)
	, _Rectangle(rectangle)
{
}


bool Line_AxisAlignedRectangle::Contains(const Object* object) const
{
	return object == &_Line || object == &_Rectangle;
}


bool Line_AxisAlignedRectangle::IsCollision()
{
	return false;
}


void Line_AxisAlignedRectangle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
