#include "AxisAlignedLine_AxisAlignedLine.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


AxisAlignedLine_AxisAlignedLine::AxisAlignedLine_AxisAlignedLine(AxisAlignedLine& line1, AxisAlignedLine& line2)
	: _Line1(line1)
	, _Line2(line2)
{
}


bool AxisAlignedLine_AxisAlignedLine::Contains(const Object* object) const
{
	return object == &_Line1 || object == &_Line2;
}


bool AxisAlignedLine_AxisAlignedLine::IsCollision()
{
	return false;
}


void AxisAlignedLine_AxisAlignedLine::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
