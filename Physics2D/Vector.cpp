#include <cmath>
#include "Vector.h"

using namespace Physics2D;


Vector::Vector()
	: X(0)
	, Y(0)
{
}


Vector::Vector(float x, float y)
	: X(x)
	, Y(y)
{
}


Vector::Vector(const Vector& vector)
	: X(vector.X)
	, Y(vector.Y)
{
}


const Vector& Vector::operator = (const Vector& vector)
{
	X = vector.X;
	Y = vector.Y;

	return *this;
}


Vector::operator bool()
{
	return X != 0 || Y != 0;
}


bool Vector::operator == (float scalar) const
{
	return X == scalar && Y == scalar;
}


bool Vector::operator != (float scalar) const
{
	return X != scalar && Y != scalar;
}


bool Vector::operator == (const Vector& vector) const
{
	return X == vector.X && Y == vector.Y;
}


bool Vector::operator != (const Vector& vector) const
{
	return X != vector.X && Y != vector.Y;
}


bool Vector::operator < (const Vector& vector) const
{
	return X < vector.X && Y < vector.Y;
}


bool Vector::operator > (const Vector& vector) const
{
	return X > vector.X && Y > vector.Y;
}


bool Vector::operator <= (const Vector& vector) const
{
	return X <= vector.X && Y <= vector.Y;
}


bool Vector::operator >= (const Vector& vector) const
{
	return X >= vector.X && Y >= vector.Y;
}


void Vector::operator += (float scalar)
{
	X += scalar;
	Y += scalar;
}


void Vector::operator -= (float scalar)
{
	X -= scalar;
	Y -= scalar;
}


void Vector::operator *= (float scalar)
{
	X *= scalar;
	Y *= scalar;
}


void Vector::operator /= (float scalar)
{
	X /= scalar;
	Y /= scalar;
}


void Vector::operator += (const Vector& vector)
{
	X += vector.X;
	Y += vector.Y;
}


void Vector::operator -= (const Vector& vector)
{
	X -= vector.X;
	Y -= vector.Y;
}


void Vector::operator *= (const Vector& vector)
{
	X *= vector.X;
	Y *= vector.Y;
}


void Vector::operator /= (const Vector& vector)
{
	X /= vector.X;
	Y /= vector.Y;
}


const Vector Vector::operator - () const
{
	return Vector(-X, -Y);
}


const Vector Vector::operator + (float scalar) const
{
	return Vector(X + scalar, Y + scalar);
}


const Vector Vector::operator - (float scalar) const
{
	return Vector(X - scalar, Y - scalar);
}


const Vector Vector::operator * (float scalar) const
{
	return Vector(X * scalar, Y * scalar);
}


const Vector Vector::operator / (float scalar) const
{
	return Vector(X / scalar, Y / scalar);
}


const Vector Vector::operator + (const Vector& vector) const
{
	return Vector(X + vector.X, Y + vector.Y);
}


const Vector Vector::operator - (const Vector& vector) const
{
	return Vector(X - vector.X, Y - vector.Y);
}


const Vector Vector::operator * (const Vector& vector) const
{
	return Vector(X * vector.X, Y * vector.Y);
}


const Vector Vector::operator / (const Vector& vector) const
{
	return Vector(X / vector.X, Y / vector.Y);
}


float Vector::Length() const
{
	return std::sqrt((X*X) + (Y*Y));
}


const Vector& Vector::Normalize()
{
	float length = Length();

	if ( length )
	{
		*this /= length;
	}

	return *this;
}


float Vector::DotProduct(const Vector &vector) const
{
	return (X * vector.X) + (Y * vector.Y);
}


void Vector::Absolute()
{
	X = abs(X);
	Y = abs(Y);
}


void Vector::RotateDegrees(float degrees)
{
	if ( degrees )
	{
		constexpr float degreesToRadians = 0.01745329251994329576923690768489f;
		float radians = degrees * degreesToRadians;
		float sinRadians = sin(radians);
		float cosRadians = cos(radians);
		float x = (X * cosRadians) - (Y * sinRadians);
		Y = (X * sinRadians) + (Y * cosRadians);
		X = x;
	}
}


void Vector::RotateRadians(float radians)
{
	if ( radians )
	{
		float sinRadians = sin(radians);
		float cosRadians = cos(radians);
		float x = (X * cosRadians) - (Y * sinRadians);
		Y = (X * sinRadians) + (Y * cosRadians);
		X = x;
	}
}
