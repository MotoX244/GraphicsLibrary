#include "Circle.h"

using namespace Physics2D;


Circle::Circle(const Vector& position, float radius, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(position, velocity, acceleration, mass, drag, restitution, identifier)
	, _Radius(radius)
{
}


ObjectType Circle::Type() const
{
	return ObjectType::Circle;
}


float Circle::Radius() const
{
	return _Radius;
}


void Circle::SetRadius(float radius)
{
	_Radius = radius;
}


void Circle::AdjustRadius(float amount)
{
	_Radius += amount;
}
