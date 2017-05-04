#include "Circle.h"

using namespace Graphics2D;


Circle::Circle(const Point& center, float radius, const Color& color)
	: _Center(center)
	, _Radius(radius)
	, _Color(color)
{
}


const Point& Circle::Center() const
{
	return _Center;
}


float Circle::Radius() const
{
	return _Radius;
}


const Color& Circle::GetColor() const
{
	return _Color;
}


void Circle::SetCenter(const Point& center)
{
	_Center = center;
}


void Circle::SetRadius(float radius)
{
	_Radius = radius;
}
