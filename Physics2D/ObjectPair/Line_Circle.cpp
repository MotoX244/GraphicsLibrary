#include <cmath>
#include <algorithm>
#include <iostream>
#include "Line_Circle.h"
#include "../Object/Line.h"
#include "../Object/Circle.h"

using namespace std;
using namespace Physics2D;


Line_Circle::Line_Circle(Line& line, Circle& circle)
	: _Line(line)
	, _Circle(circle)
{
}


Object& Line_Circle::Object1()
{
	return _Line;
}


Object& Line_Circle::Object2()
{
	return _Circle;
}


bool Line_Circle::Contains(const Object* object) const
{
	return object == &_Line || object == &_Circle;
}


void Line_Circle::FindCollision(float seconds)
{
	// Combine velocities so only circle is moving
	Vector velocity = (_Circle.Velocity() - _Line.Velocity()) * seconds;

	// Move both objects so the circle is at (0, 0)
	Vector line = _Line.Position() - _Circle.Position();

	// Rotate both objects so the line is parallel with the X axis
	line.RotateDegrees(-_Line.Rotation());
	velocity.RotateDegrees(-_Line.Rotation());

	// All we care about with the line is its distance from the X axis
	float lineY = line.Y;

	if ( (line.Y > 0 && velocity.Y < 0) || (line.Y < 0 && velocity.Y > 0) )
	{
		_TimeOfCollision = numeric_limits<float>::infinity();
		return;
	}

	float distance = abs(velocity.Y);
	float distanceMax = abs(line.Y) - _Circle.Radius();
	if ( distance <= distanceMax )
	{
		_TimeOfCollision = numeric_limits<float>::infinity();
		return;
	}

	cout << "Collision - Line ( " << _Line.X() << ", " << _Line.Y() << ") (" << _Line.VelocityX() << ", " << _Line.VelocityY() << ") - Circle (" << _Circle.X() << ", " << _Circle.Y() << ") (" << _Circle.VelocityX() << ", " << _Circle.VelocityY() << ")" << endl;

	_CollisionNormal = Vector(0, 1);
	_CollisionNormal.RotateDegrees(_Line.Rotation());
	_TimeOfCollision = (distanceMax / distance) * seconds;
}
