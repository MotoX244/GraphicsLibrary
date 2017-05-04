#include "AxisAlignedRectangle.h"

using namespace Physics2D;


AxisAlignedRectangle::AxisAlignedRectangle(const Vector& min, const Vector& max, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(min + ((max - min) / 2), velocity, acceleration, mass, drag, restitution, identifier)
	, _Size(max - min)
	, _HalfSize(_Size / 2.0f)
	, _Min(min)
	, _Max(max)
{
}


AxisAlignedRectangle::AxisAlignedRectangle(const Vector& position, float width, float height, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: Object(position, velocity, acceleration, mass, drag, restitution, identifier)
	, _Size(width, height)
	, _HalfSize(_Size / 2.0f)
	, _Min(position - _HalfSize)
	, _Max(position + _HalfSize)
{
}


ObjectType AxisAlignedRectangle::Type() const
{
	return ObjectType::AxisAlignedRectangle;
}


const Vector& AxisAlignedRectangle::Size() const
{
	return _Size;
}


const Vector& AxisAlignedRectangle::HalfSize() const
{
	return _HalfSize;
}


float AxisAlignedRectangle::MinX() const
{
	return _Min.X;
}


float AxisAlignedRectangle::MinY() const
{
	return _Min.Y;
}


float AxisAlignedRectangle::MaxX() const
{
	return _Max.X;
}


float AxisAlignedRectangle::MaxY() const
{
	return _Max.Y;
}


const Vector& AxisAlignedRectangle::Min() const
{
	return _Min;
}


const Vector& AxisAlignedRectangle::Max() const
{
	return _Max;
}


void AxisAlignedRectangle::SetPosition(const Vector& position)
{
	_Position = position;
	_Min = position - _HalfSize;
	_Max = position + _HalfSize;
}


void AxisAlignedRectangle::SetSize(const Vector& size)
{
	_Size = size;
	_HalfSize = _Size / 2.0f;
	_Min = _Position - _HalfSize;
	_Max = _Position + _HalfSize;
}


void AxisAlignedRectangle::AdjustPosition(const Vector& amount)
{
	_Position += amount;
	_Min = _Position - _HalfSize;
	_Max = _Position + _HalfSize;
}


void AxisAlignedRectangle::AdjustSize(const Vector& amount)
{
	_Size += amount;
	_HalfSize = _Size / 2.0f;
	_Min = _Position - _HalfSize;
	_Max = _Position + _HalfSize;
}
