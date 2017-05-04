#pragma once


namespace Physics2D
{
	class Vector
	{
	public:
		float X;
		float Y;

		Vector();
		Vector(float x, float y);
		Vector(const Vector& vector);

		const Vector& operator = (const Vector& vector);

		operator bool();

		bool operator == (float scalar) const;
		bool operator != (float scalar) const;
		bool operator == (const Vector& vector) const;
		bool operator != (const Vector& vector) const;

		bool operator < (const Vector& vector) const;
		bool operator > (const Vector& vector) const;
		bool operator <= (const Vector& vector) const;
		bool operator >= (const Vector& vector) const;

		void operator += (float scalar);
		void operator -= (float scalar);
		void operator *= (float scalar);
		void operator /= (float scalar);
		void operator += (const Vector& vector);
		void operator -= (const Vector& vector);
		void operator *= (const Vector& vector);
		void operator /= (const Vector& vector);

		const Vector operator - () const;
		const Vector operator + (float scalar) const;
		const Vector operator - (float scalar) const;
		const Vector operator * (float scalar) const;
		const Vector operator / (float scalar) const;
		const Vector operator + (const Vector& vector) const;
		const Vector operator - (const Vector& vector) const;
		const Vector operator * (const Vector& vector) const;
		const Vector operator / (const Vector& vector) const;

		float Length() const;

		const Vector& Normalize();

		float DotProduct(const Vector &vector) const;

		void Absolute();

		void RotateDegrees(float degrees);

		void RotateRadians(float radians);
	};
}