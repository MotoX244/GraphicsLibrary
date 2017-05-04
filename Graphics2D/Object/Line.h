#pragma once

#include "../Point.h"
#include "../Color.h"


namespace Graphics2D
{
	class Line
	{
	public:
		Line(const Point& center, float length, float rotation, const Color& color);
		Line(const Point& point1, const Point& point2, const Color& color);
		const Point& Point1() const;
		const Point& Point2() const;
		const Point& Center() const;
		float Length() const;
		float Rotation() const;
		const Color& GetColor() const;
		void SetPoints(const Point& point1, const Point& point2);
		void SetCenter(const Point& center);
		void SetLength(float length);
		void SetRotation(float rotation);

	private:
		void CalculateLine();
		void CalculatePoints();

		Point _Point1;
		Point _Point2;
		Point _Center;
		float _Length;
		float _Rotation;
		Color _Color;
	};
}
