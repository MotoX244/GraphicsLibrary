#include <cmath>
#include <algorithm>
#include "Circle_Circle.h"
#include "../Object/Circle.h"

using namespace std;
using namespace Physics2D;


Circle_Circle::Circle_Circle(Circle& circle1, Circle& circle2)
	: _Circle1(circle1)
	, _Circle2(circle2)
{
}


Object& Circle_Circle::Object1()
{
	return _Circle1;
}


Object& Circle_Circle::Object2()
{
	return _Circle2;
}


bool Circle_Circle::Contains(const Object* object) const
{
	return object == &_Circle1 || object == &_Circle2;
}


void Circle_Circle::FindCollision()
{
	Vector velocity = _Circle2.Velocity() - _Circle1.Velocity();
	Vector circle1 = _Circle1.Position() - _Circle2.Position();
	float angle = atan(velocity.Y / velocity.X);
	circle1.RotateRadians(-angle);

	float distance = abs(circle1.Y);
	float distanceMax = _Circle1.Radius() + _Circle2.Radius();
	if ( distance >= distanceMax )
	{
		_TimeOfCollision = numeric_limits<float>::infinity();
		return;
	}

	if ( velocity.X >= 0 )
	{
		if ( circle1.X > velocity.Length() )
		{
			if ( sqrt(pow(circle1.X - velocity.Length(), 2) + pow(circle1.Y, 2)) > distanceMax )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}

		if ( circle1.X < 0 )
		{
			if ( sqrt(pow(circle1.X, 2) + pow(circle1.Y, 2)) > distanceMax )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}
	}
	else
	{
		if ( circle1.X < -velocity.Length() )
		{
			if ( sqrt(pow(circle1.X + velocity.Length(), 2) + pow(circle1.Y, 2)) > distanceMax )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}

		if ( circle1.X > 0 )
		{
			if ( sqrt(pow(circle1.X, 2) + pow(circle1.Y, 2)) > distanceMax )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}
	}

	float offset = sqrt(pow(distanceMax, 2) - pow(distance, 2));
	_CollisionNormal = Vector(offset, distance);
	_CollisionNormal.RotateRadians(angle);
	_CollisionNormal.Normalize();
	_TimeOfCollision = (abs(circle1.X) - offset) / velocity.Length();
}
