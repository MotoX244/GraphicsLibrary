#pragma once


namespace Graphics2D
{
	class Point
	{
	public:
		float X;
		float Y;

		Point();
		Point(float x, float y);
		Point(const Point& point);

		operator bool();

		const Point& operator = (const Point& point);

		bool operator == (float scalar) const;
		bool operator != (float scalar) const;
		bool operator == (const Point& vector) const;
		bool operator != (const Point& vector) const;

		bool operator < (const Point& vector) const;
		bool operator > (const Point& vector) const;
		bool operator <= (const Point& vector) const;
		bool operator >= (const Point& vector) const;

		void operator += (float scalar);
		void operator -= (float scalar);
		void operator *= (float scalar);
		void operator /= (float scalar);
		void operator += (const Point& vector);
		void operator -= (const Point& vector);
		void operator *= (const Point& vector);
		void operator /= (const Point& vector);

		const Point operator - () const;
		const Point operator + (float scalar) const;
		const Point operator - (float scalar) const;
		const Point operator * (float scalar) const;
		const Point operator / (float scalar) const;
		const Point operator + (const Point& vector) const;
		const Point operator - (const Point& vector) const;
		const Point operator * (const Point& vector) const;
		const Point operator / (const Point& vector) const;
	};
}