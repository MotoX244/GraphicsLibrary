#include "Circle_Circle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Circle_Circle::Circle_Circle(Circle& circle1, Circle& circle2)
	: _Circle1(circle1)
	, _Circle2(circle2)
{
}


bool Circle_Circle::Contains(const Object* object) const
{
	return object == &_Circle1 || object == &_Circle2;
}


bool Circle_Circle::IsCollision()
{
	return false;
}


void Circle_Circle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
