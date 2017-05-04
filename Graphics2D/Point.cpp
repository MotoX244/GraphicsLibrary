#include "Point.h"

using namespace Graphics2D;


Point::Point()
	: X(0)
	, Y(0)
{
}


Point::Point(float x, float y)
	: X(x)
	, Y(y)
{
}


Point::Point(const Point& point)
	: X(point.X)
	, Y(point.Y)
{
}


Point::operator bool()
{
	return X != 0 || Y != 0;
}


const Point& Point::operator = (const Point& point)
{
	X = point.X;
	Y = point.Y;
	return *this;
}


bool Point::operator == (float scalar) const
{
	return X == scalar && Y == scalar;
}


bool Point::operator != (float scalar) const
{
	return X != scalar && Y != scalar;
}


bool Point::operator == (const Point& vector) const
{
	return X == vector.X && Y == vector.Y;
}


bool Point::operator != (const Point& vector) const
{
	return X != vector.X && Y != vector.Y;
}


bool Point::operator < (const Point& vector) const
{
	return X < vector.X && Y < vector.Y;
}


bool Point::operator > (const Point& vector) const
{
	return X > vector.X && Y > vector.Y;
}


bool Point::operator <= (const Point& vector) const
{
	return X <= vector.X && Y <= vector.Y;
}


bool Point::operator >= (const Point& vector) const
{
	return X >= vector.X && Y >= vector.Y;
}


void Point::operator += (float scalar)
{
	X += scalar;
	Y += scalar;
}


void Point::operator -= (float scalar)
{
	X -= scalar;
	Y -= scalar;
}


void Point::operator *= (float scalar)
{
	X *= scalar;
	Y *= scalar;
}


void Point::operator /= (float scalar)
{
	X /= scalar;
	Y /= scalar;
}


void Point::operator += (const Point& vector)
{
	X += vector.X;
	Y += vector.Y;
}


void Point::operator -= (const Point& vector)
{
	X -= vector.X;
	Y -= vector.Y;
}


void Point::operator *= (const Point& vector)
{
	X *= vector.X;
	Y *= vector.Y;
}


void Point::operator /= (const Point& vector)
{
	X /= vector.X;
	Y /= vector.Y;
}


const Point Point::operator - () const
{
	return Point(-X, -Y);
}


const Point Point::operator + (float scalar) const
{
	return Point(X + scalar, Y + scalar);
}


const Point Point::operator - (float scalar) const
{
	return Point(X - scalar, Y - scalar);
}


const Point Point::operator * (float scalar) const
{
	return Point(X * scalar, Y * scalar);
}


const Point Point::operator / (float scalar) const
{
	return Point(X / scalar, Y / scalar);
}


const Point Point::operator + (const Point& vector) const
{
	return Point(X + vector.X, Y + vector.Y);
}


const Point Point::operator - (const Point& vector) const
{
	return Point(X - vector.X, Y - vector.Y);
}


const Point Point::operator * (const Point& vector) const
{
	return Point(X * vector.X, Y * vector.Y);
}


const Point Point::operator / (const Point& vector) const
{
	return Point(X / vector.X, Y / vector.Y);
}
