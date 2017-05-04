#include "Line.h"

using namespace Physics2D;


Line::Line(const Vector& position, float length, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(position, velocity, acceleration, mass, drag, restitution, identifier)
	, _Length(length)
{
}


ObjectType Line::Type()
{
	return ObjectType::Line;
}


float Line::Length()
{
	return _Length;
}


void Line::SetLength(float length)
{
	_Length = length;
}


void Line::AdjustLength(float amount)
{
	_Length += amount;
}
