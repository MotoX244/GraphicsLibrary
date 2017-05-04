#include "AxisAlignedLine_AxisAlignedRectangle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


AxisAlignedLine_AxisAlignedRectangle::AxisAlignedLine_AxisAlignedRectangle(AxisAlignedLine& line, AxisAlignedRectangle& rectangle)
	: _Line(line)
	, _Rectangle(rectangle)
{
}


bool AxisAlignedLine_AxisAlignedRectangle::Contains(const Object* object) const
{
	return object == &_Line || object == &_Rectangle;
}


bool AxisAlignedLine_AxisAlignedRectangle::IsCollision()
{
	return false;
}


void AxisAlignedLine_AxisAlignedRectangle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
