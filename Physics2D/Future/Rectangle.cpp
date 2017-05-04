#include "Rectangle.h"

using namespace Physics2D;


Rectangle::Rectangle(const Vector& position, const Vector& size, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(position, velocity, acceleration, mass, drag, restitution, identifier)
	, _Size(size)
	, _HalfSize(size / 2)
	, _TopLeft(position - _HalfSize)
	, _BottomRight(position + _HalfSize)
{
}


ObjectType Rectangle::Type()
{
	return ObjectType::Rectangle;
}


float Rectangle::Left() const
{
	return _TopLeft.X;
}


float Rectangle::Top() const
{
	return _TopLeft.Y;
}


float Rectangle::Right() const
{
	return _BottomRight.X;
}


float Rectangle::Bottom() const
{
	return _BottomRight.Y;
}


const Vector& Rectangle::Size() const
{
	return _Size;
}


const Vector& Rectangle::HalfSize() const
{
	return _HalfSize;
}


void Rectangle::SetPosition(const Vector& position)
{
	_Position = position;
	_TopLeft = position - _HalfSize;
	_BottomRight = position + _HalfSize;
}


void Rectangle::SetSize(const Vector& size)
{
	_Size = size;
	_HalfSize = _Size / 2.0f;
}


void Rectangle::AdjustSize(const Vector& amount)
{
	_Size += amount;
	_HalfSize = _Size / 2.0f;
}
