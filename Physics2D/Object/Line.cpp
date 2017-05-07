#include "Line.h"

using namespace Physics2D;


Line::Line(const Vector& position, float rotation, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(position, velocity, acceleration, mass, drag, restitution, identifier)
	, _Rotation(rotation)
{
	NormalizeRotation();
}


ObjectType Line::Type() const
{
	return ObjectType::Line;
}


float Line::Rotation() const
{
	return _Rotation;
}


void Line::SetRotation(float rotation)
{
	_Rotation = rotation;

	NormalizeRotation();
}


void Line::AdjustRotation(float amount)
{
	_Rotation += amount;

	NormalizeRotation();
}


void Line::NormalizeRotation()
{
	while ( _Rotation >= 360.0f )
	{
		_Rotation -= 360.0f;
	}

	while ( _Rotation < 0.0f )
	{
		_Rotation += 360.0f;
	}
}
