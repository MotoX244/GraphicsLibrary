#include <cmath>
#include "Line.h"

using namespace std;
using namespace Graphics2D;


Line::Line(const Point& center, float length, float rotation, const Color& color)
	: _Center(center)
	, _Length(length)
	, _Rotation(rotation)
	, _Color(color)
{
	CalculatePoints();
}


Line::Line(const Point& point1, const Point& point2, const Color& color)
	: _Point1(point1)
	, _Point2(point2)
	, _Color(color)
{
	CalculateLine();
}


const Point& Line::Point1() const
{
	return _Point1;
}


const Point& Line::Point2() const
{
	return _Point2;
}


const Point& Line::Center() const
{
	return _Center;
}


float Line::Length() const
{
	return _Length;
}


float Line::Rotation() const
{
	return _Rotation;
}


const Color& Line::GetColor() const
{
	return _Color;
}


void Line::SetPoints(const Point& point1, const Point& point2)
{
	_Point1 = point1;
	_Point2 = point2;
	CalculateLine();
}


void Line::SetCenter(const Point& center)
{
	_Center = center;
	CalculatePoints();
}


void Line::SetLength(float length)
{
	_Length = length;
	CalculatePoints();
}


void Line::SetRotation(float rotation)
{
	_Rotation = rotation;
	CalculatePoints();
}


void Line::CalculateLine()
{
	constexpr float RadiansToDegrees = 57.295779513082320876798154814105f;
	_Rotation = atan2(_Point1.Y - _Point2.Y, _Point1.X - _Point2.X) * RadiansToDegrees;
	_Length = sqrt(pow((_Point2.X - _Point1.X), 2) + pow((_Point2.Y - _Point1.Y), 2));
	_Center = (_Point1 + _Point2) / 2;
}


void Line::CalculatePoints()
{
	constexpr float degreesToRadians = 0.01745329251994329576923690768489f;
	float radians = _Rotation * degreesToRadians;
	float halfLength = _Length / 2;
	_Point1 = Point(halfLength * cos(radians), halfLength * sin(radians));
	_Point2 = -_Point1;
	_Point1 += _Center;
	_Point2 += _Center;
}
