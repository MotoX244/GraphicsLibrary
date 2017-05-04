#include "Line_Circle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Line_Circle::Line_Circle(Line& line, Circle& circle)
	: _Line(line)
	, _Circle(circle)
{
}


bool Line_Circle::Contains(const Object* object) const
{
	return object == &_Line || object == &_Circle;
}


bool Line_Circle::IsCollision()
{
	return false;
}


void Line_Circle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
