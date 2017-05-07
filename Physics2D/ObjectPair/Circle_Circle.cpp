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

/*
  X     Y
 1.0,  0.0 = 0
 1.0,  0.5 = 26
 1.0,  1.0 = 45
 0.5,  1.0 = 63
 0.0,  1.0 = 90 / Exception
-0.5,  1.0 = -63
-1.0,  1.0 = -45
-1.0,  0.5 = -26
-1.0,  0.0 = 0
-1.0, -0.5 = 26
-1.0, -1.0 = 45
-0.5, -1.0 = 63
 0.0, -1.0 = 90 / Exception
 0.5, -1.0 = -63
 1.0, -1.0 = -45
 1.0, -0.5 = -26
*/

void Circle_Circle::FindCollision(float seconds)
{
	// Combine velocities so only circle 2 is moving
	Vector velocity = (_Circle2.Velocity() - _Circle1.Velocity()) * seconds;

	// Move both circles so circle 2 is at (0, 0)
	Vector circle1 = _Circle1.Position() - _Circle2.Position();

	// Rotate both circles so circle 2 is moving along the X axis
	float angle = 90;
	if ( velocity.X != 0 )
	{
		angle = atan(velocity.Y / velocity.X);
	}
	circle1.RotateRadians(-angle);

	// Get the maximum distance allowed between the 2 circles
	float maxSeparation = _Circle1.Radius() + _Circle2.Radius();

	// Get how far circle 1 is from circle 2 in the Y direction
	float separationY = abs(circle1.Y);

	// See if circle 2 could possibly hit circle 1
	if ( separationY >= maxSeparation )
	{
		_TimeOfCollision = numeric_limits<float>::infinity();
		return;
	}

	// Get the absolute distance circle 2 will travel along the X axis
	float velocityLength = velocity.Length();

	// See if circle 2 is traveling to the right
	if ( velocity.X >= 0 )
	{
		// See if circle 1 is to the right of circle 2
		if ( circle1.X > velocityLength )
		{
			// See if circle 2 will miss circle 1
			if ( sqrt(pow(circle1.X - velocityLength, 2) + pow(circle1.Y, 2)) >= maxSeparation )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}

		// See if circle 1 is to the left of circle 2
		if ( circle1.X < 0 )
		{
			// See if circle 2 will miss circle 1
			if ( sqrt(pow(circle1.X, 2) + pow(circle1.Y, 2)) >= maxSeparation )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}
	}
	else // Circle 2 is traveling to the left
	{
		// See if circle 1 is to the left of circle 2
		if ( circle1.X < -velocityLength )
		{
			// See if circle 2 will miss circle 1
			if ( sqrt(pow(circle1.X + velocityLength, 2) + pow(circle1.Y, 2)) >= maxSeparation )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}

		// See if circle 1 is to the right of circle 2
		if ( circle1.X > 0 )
		{
			// See if circle 2 will miss circle 1
			if ( sqrt(pow(circle1.X, 2) + pow(circle1.Y, 2)) >= maxSeparation )
			{
				_TimeOfCollision = numeric_limits<float>::infinity();
				return;
			}
		}
	}

	float offset = sqrt(pow(maxSeparation, 2) - pow(separationY, 2));
	_TimeOfCollision = ((abs(circle1.X) - offset) / velocityLength) * seconds;

	if ( velocity.X >= 0 )
	{
		_CollisionNormal = Vector(offset, circle1.Y);
	}
	else
	{
		_CollisionNormal = Vector(-offset, circle1.Y);
	}

	_CollisionNormal.RotateRadians(angle);
	_CollisionNormal.Normalize();
}
