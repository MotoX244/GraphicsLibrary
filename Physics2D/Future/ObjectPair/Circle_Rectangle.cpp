#include "Circle_Rectangle.h"
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Physics2D;


Circle_Rectangle::Circle_Rectangle(Circle& circle, Rectangle& rectangle)
	: _Circle(circle)
	, _Rectangle(rectangle)
{
}


bool Circle_Rectangle::Contains(const Object* object) const
{
	return object == &_Circle || object == &_Rectangle;
}


bool Circle_Rectangle::IsCollision()
{
	return IsCollision(_Circle.Position(), _Rectangle.Position());
}


bool Circle_Rectangle::IsCollision(const Vector& /*circlePosition*/, const Vector& /*rectanglePosition*/)
{
	// ooo|ooo
	// ooo|ooo
	// ---X---
	// ooo|ooo
	// ooo|ooo

	//float circleLeft = circlePosition.X - _Circle.Radius();
	//float circleRight = circlePosition.X + _Circle.Radius();
	//float circleTop = circlePosition.Y - _Circle.Radius();
	//float circleBottom = circlePosition.X + _Circle.Radius();

	//float rectangleLeft = rectanglePosition.X;
	//float rectangleRight = rectanglePosition.X + _Rectangle.Size().X;
	//float rectangleTop = rectanglePosition.Y;
	//float rectangleBottom = rectanglePosition.Y + _Rectangle.Size().Y;

	//if ( circleLeft > rectangleRight )
	//{
		return false;
	//}
	//if ( circleRight < rectangleLeft )

	//return true;
}


void Circle_Rectangle::FindTimeOfCollision()
{
	_TimeOfCollision = numeric_limits<float>::infinity();
}
