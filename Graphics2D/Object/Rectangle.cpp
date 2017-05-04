#include "Rectangle.h"

using namespace Graphics2D;


Rectangle::Rectangle(const Point& center, float width, float height, float rotation, const Color& color)
	: _Width(width)
	, _Height(height)
	, _HalfWidth(width / 2)
	, _HalfHeight(height / 2)
	, _Center(center)
	, _Min(center.X - _HalfWidth, center.Y - _HalfHeight)
	, _Max(center.X + _HalfWidth, center.Y + _HalfHeight)
	, _Rotation(rotation)
	, _Color(color)
{
}


Rectangle::Rectangle(const Point& min, const Point& max, float rotation, const Color& color)
	: _Width(min.X - max.X)
	, _Height(min.Y - max.Y)
	, _HalfWidth(_Width / 2)
	, _HalfHeight(_Height / 2)
	, _Center(min.X + _HalfWidth, max.Y + _HalfHeight)
	, _Min(min)
	, _Max(max)
	, _Rotation(rotation)
	, _Color(color)
{
}


const Point& Rectangle::Center() const
{
	return _Center;
}


float Rectangle::CenterX() const
{
	return _Center.X;
}


float Rectangle::CenterY() const
{
	return _Center.Y;
}


const Point& Rectangle::Min() const
{
	return _Min;
}


float Rectangle::MinX() const
{
	return _Min.X;
}


float Rectangle::MinY() const
{
	return _Min.Y;
}


const Point& Rectangle::Max() const
{
	return _Max;
}


float Rectangle::MaxX() const
{
	return _Max.X;
}


float Rectangle::MaxY() const
{
	return _Max.Y;
}


float Rectangle::Width() const
{
	return _Width;
}


float Rectangle::Height() const
{
	return _Height;
}


float Rectangle::Rotation() const
{
	return _Rotation;
}


const Color& Rectangle::GetColor() const
{
	return _Color;
}


void Rectangle::SetCenter(const Point& center)
{
	_Center = center;

	_Min.X = _Center.X - _HalfWidth;
	_Min.Y = _Center.Y - _HalfHeight;
	_Max.X = _Center.X + _HalfWidth;
	_Max.Y = _Center.Y + _HalfHeight;
}


void Rectangle::SetCenterX(float centerX)
{
	_Center.X = centerX;

	_Min.X = _Center.X - _HalfWidth;
	_Max.X = _Center.X + _HalfWidth;
}


void Rectangle::SetCenterY(float centerY)
{
	_Center.Y = centerY;

	_Min.Y = _Center.Y - _HalfHeight;
	_Max.Y = _Center.Y + _HalfHeight;
}


void Rectangle::SetMin(const Point& min)
{
	_Min = min;
	_Width = _Max.X - _Min.X;
	_Height = _Max.Y - _Min.Y;
	_HalfWidth = _Width / 2;
	_HalfHeight = _Height / 2;
	_Center.X = _Min.X + _HalfWidth;
	_Center.Y = _Min.Y + _HalfHeight;
}


void Rectangle::SetMinX(float minX)
{
	_Min.X = minX;
	_Width = _Max.X - _Min.X;
	_HalfWidth = _Width / 2;
	_Center.X = _Min.X + _HalfWidth;
}


void Rectangle::SetMinY(float minY)
{
	_Min.Y = minY;
	_Height = _Max.Y - _Min.Y;
	_HalfHeight = _Height / 2;
	_Center.Y = _Min.Y + _HalfHeight;
}


void Rectangle::SetMax(const Point& max)
{
	_Max = max;
	_Width = _Max.X - _Min.X;
	_Height = _Max.Y - _Min.Y;
	_HalfWidth = _Width / 2;
	_HalfHeight = _Height / 2;
	_Center.X = _Min.X + _HalfWidth;
	_Center.Y = _Min.Y + _HalfHeight;
}


void Rectangle::SetMaxX(float maxX)
{
	_Max.X = maxX;
	_Width = _Max.X - _Min.X;
	_HalfWidth = _Width / 2;
	_Center.X = _Min.X + _HalfWidth;
}


void Rectangle::SetMaxY(float maxY)
{
	_Max.Y = maxY;
	_Height = _Max.Y - _Min.Y;
	_HalfHeight = _Height / 2;
	_Center.Y = _Min.Y + _HalfHeight;
}


void Rectangle::SetCorners(const Point& min, const Point& max)
{
	_Min = min;
	_Max = max;
	_Width = _Max.X - _Min.X;
	_Height = _Max.Y - _Min.Y;
	_HalfWidth = _Width / 2;
	_HalfHeight = _Height / 2;
	_Center.X = _Min.X + _HalfWidth;
	_Center.Y = _Min.Y + _HalfHeight;
}


void Rectangle::SetSize(float width, float height)
{
	_Width = width;
	_Height = height;

	_HalfWidth = _Width / 2;
	_HalfHeight = _Height / 2;

	_Min.X = _Center.X - _HalfWidth;
	_Min.Y = _Center.Y - _HalfHeight;
	_Max.X = _Center.X + _HalfWidth;
	_Max.Y = _Center.Y + _HalfHeight;
}


void Rectangle::SetRotation(float rotation)
{
	_Rotation = rotation;
}
