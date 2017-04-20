#include "Point.h"

using namespace Graphics;


Point::Point()
	: _X(0)
	, _Y(0)
{
}


Point::Point(int x, int y, Color& color)
	: _X(x)
	, _Y(y)
	, _Color(color)
{
}


Point::~Point()
{
}


int Point::X() const
{
	return _X;
}


int Point::Y() const
{
	return _Y;
}


const Color& Point::GetColor() const
{
	return _Color;
}


void Point::SetPosition(int x, int y)
{
	_X = x;
	_Y = y;
}
