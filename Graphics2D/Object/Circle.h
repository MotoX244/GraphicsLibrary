#pragma once

#include "../Point.h"
#include "../Color.h"


namespace Graphics2D
{
	class Circle
	{
	public:
		Circle(const Point& center, float radius, const Color& color);
		const Point& Center() const;
		float Radius() const;
		const Color& GetColor() const;
		void SetCenter(const Point& center);
		void SetRadius(float radius);

	private:
		Point _Center;
		float _Radius;
		Color _Color;
	};
}
