#include "AxisAlignedLine.h"

using namespace Physics2D;


AxisAlignedLine::AxisAlignedLine(const Vector& position, float length, Direction direction, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(position, velocity, acceleration, mass, drag, restitution, identifier)
	, _Length(length)
	, _HalfLength(length / 2.0f)
	, _Direction(direction)
	, _Min((direction == Direction::Horizontal ? position.X : position.Y) - _HalfLength)
	, _Max((direction == Direction::Horizontal ? position.X : position.Y) + _HalfLength)
{
}


AxisAlignedLine::AxisAlignedLine(const Vector& point1, const Vector& point2, Direction direction, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(point1 + ((point2 - point1) / 2), velocity, acceleration, mass, drag, restitution, identifier)
	, _Length(abs(direction == Direction::Horizontal ? (point2.X - point1.X) : (point2.Y - point1.Y)))
	, _HalfLength(_Length / 2.0f)
	, _Direction(direction)
	, _Min((direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength)
	, _Max((direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength)
{
}


ObjectType AxisAlignedLine::Type() const
{
	return ObjectType::AxisAlignedLine;
}


float AxisAlignedLine::Length() const
{
	return _Length;
}


float AxisAlignedLine::HalfLength() const
{
	return _HalfLength;
}


Direction AxisAlignedLine::GetDirection() const
{
	return _Direction;
}


float AxisAlignedLine::Min() const
{
	return _Min;
}


float AxisAlignedLine::Max() const
{
	return _Max;
}


void AxisAlignedLine::SetLength(float length)
{
	_Length = length;
	_HalfLength = length / 2.0f;
	_Min = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength;
	_Max = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength;
}


void AxisAlignedLine::SetDirection(Direction direction)
{
	_Direction = direction;
	_Min = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength;
	_Max = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength;
}


void AxisAlignedLine::AdjustLength(float amount)
{
	_Length += amount;
	_HalfLength = _Length / 2.0f;
	_Min = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) - _HalfLength;
	_Max = (_Direction == Direction::Horizontal ? _Position.X : _Position.Y) + _HalfLength;
}
