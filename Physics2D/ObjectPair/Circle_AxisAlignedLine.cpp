#include <cmath>
#include <algorithm>
#include "Circle_AxisAlignedLine.h"
#include "../Object/Circle.h"
#include "../Object/AxisAlignedLine.h"

using namespace std;
using namespace Physics2D;


Circle_AxisAlignedLine::Circle_AxisAlignedLine(Circle& circle, AxisAlignedLine& line)
	: _Circle(circle)
	, _Line(line)
{
}


Object& Circle_AxisAlignedLine::Object1()
{
	return _Circle;
}


Object& Circle_AxisAlignedLine::Object2()
{
	return _Line;
}


bool Circle_AxisAlignedLine::Contains(const Object* object) const
{
	return object == &_Circle || object == &_Line;
}


void Circle_AxisAlignedLine::FindCollision()
{
	Vector velocity = _Line.Velocity() - _Circle.Velocity();
	Vector circle = _Circle.Position() - _Line.Position();

	float angle = atan(velocity.Y / velocity.X);
	if ( _Line.GetDirection() == Direction::Vertical )
	{
		angle += 1.570796326794896f;
	}
	
	circle.RotateRadians(-angle);

	float distance = abs(circle.Y);
	float distanceMax = _Circle.Radius();
	if ( distance >= distanceMax )
	{
		_TimeOfCollision = numeric_limits<float>::infinity();
		return;
	}

	if ( velocity.X >= 0 )
	{
		if ( circle.X > velocity.Length() )
		{
			if ( sqrt(pow(circle.X - velocity.Length(), 2) + pow(circle.Y, 2)) > distanceMax )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}

		if ( circle.X < 0 )
		{
			if ( sqrt(pow(circle.X, 2) + pow(circle.Y, 2)) > distanceMax )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}
	}
	else
	{
		if ( circle.X < -velocity.Length() )
		{
			if ( sqrt(pow(circle.X + velocity.Length(), 2) + pow(circle.Y, 2)) > distanceMax )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}

		if ( circle.X > 0 )
		{
			if ( sqrt(pow(circle.X, 2) + pow(circle.Y, 2)) > distanceMax )
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
	_TimeOfCollision = (abs(circle.X) - offset) / velocity.Length();
}
