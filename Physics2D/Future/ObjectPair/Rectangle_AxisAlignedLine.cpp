#include "Rectangle_AxisAlignedLine.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Rectangle_AxisAlignedLine::Rectangle_AxisAlignedLine(Rectangle& rectangle, AxisAlignedLine& line)
	: _Rectangle(rectangle)
	, _Line(line)
{
}


bool Rectangle_AxisAlignedLine::Contains(const Object* object) const
{
	return object == &_Rectangle || object == &_Line;
}


bool Rectangle_AxisAlignedLine::IsCollision()
{
	return false;
}


void Rectangle_AxisAlignedLine::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
