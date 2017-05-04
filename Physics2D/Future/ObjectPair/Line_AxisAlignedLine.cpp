#include "Line_AxisAlignedLine.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Line_AxisAlignedLine::Line_AxisAlignedLine(Line& line1, AxisAlignedLine& line2)
	: _Line1(line1)
	, _Line2(line2)
{
}


bool Line_AxisAlignedLine::Contains(const Object* object) const
{
	return object == &_Line2 || object == &_Line2;
}


bool Line_AxisAlignedLine::IsCollision()
{
	return false;
}


void Line_AxisAlignedLine::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
