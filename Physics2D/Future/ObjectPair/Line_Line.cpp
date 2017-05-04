#include "Line_Line.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Line_Line::Line_Line(Line& line1, Line& line2)
	: _Line1(line1)
	, _Line2(line2)
{
}


bool Line_Line::Contains(const Object* object) const
{
	return object == &_Line1 || object == &_Line2;
}


bool Line_Line::IsCollision()
{
	return false;
}


void Line_Line::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
