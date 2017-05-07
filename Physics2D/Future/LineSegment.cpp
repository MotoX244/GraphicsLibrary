#include "Line.h"

using namespace Physics2D;


Line::Line(const Vector& position, float length, Direction direction, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(position, velocity, acceleration, mass, drag, restitution, identifier)
	, _Length(length)
	, _HalfLength(length / 2.0f)
	, _Direction(direction)
	, _Min((direction == Direction::Horizontal ? position.X : position.Y) - _HalfLength)
	, _Max((direction == Direction::Horizontal ? position.X : position.Y) + _HalfLength)
{
}


Line::Line(const Vector& point1, const Vector& point2, Direction direction, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(point1 + ((point2 - point1) / 2), velocity, acceleration, mass, drag, restitution, identifier)
	, _Length(abs(direction == Direction::Horizontal ? (point2.X - point1.X) : (point2.Y - point1.Y)))
	, _HalfLength(_Length / 2.0f)
	, _Direction(direction)
	, _Min((direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength)
	, _Max((direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength)
{
}


ObjectType Line::Type() const
{
	return ObjectType::Line;
}


float Line::Length() const
{
	return _Length;
}


float Line::HalfLength() const
{
	return _HalfLength;
}


Direction Line::GetDirection() const
{
	return _Direction;
}


float Line::Min() const
{
	return _Min;
}


float Line::Max() const
{
	return _Max;
}


void Line::SetLength(float length)
{
	_Length = length;
	_HalfLength = length / 2.0f;
	_Min = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength;
	_Max = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength;
}


void Line::SetDirection(Direction direction)
{
	_Direction = direction;
	_Min = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength;
	_Max = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength;
}


void Line::AdjustLength(float amount)
{
	_Length += amount;
	_HalfLength = _Length / 2.0f;
	_Min = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength;
	_Max = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength;
}
