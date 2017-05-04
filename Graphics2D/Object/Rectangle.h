#pragma once

#include "../Point.h"
#include "../Color.h"


namespace Graphics2D
{
	class Rectangle
	{
	public:
		Rectangle(const Point& center, float width, float height, float rotation, const Color& color);
		Rectangle(const Point& min, const Point& max, float rotation, const Color& color);
		const Point& Center() const;
		float CenterX() const;
		float CenterY() const;
		const Point& Min() const;
		float MinX() const;
		float MinY() const;
		const Point& Max() const;
		float MaxX() const;
		float MaxY() const;
		float Width() const;
		float Height() const;
		float Rotation() const;
		const Color& GetColor() const;
		void SetCenter(const Point& center);
		void SetCenterX(float centerX);
		void SetCenterY(float centerY);
		void SetMin(const Point& min);
		void SetMinX(float minX);
		void SetMinY(float minY);
		void SetMax(const Point& max);
		void SetMaxX(float maxX);
		void SetMaxY(float maxY);
		void SetCorners(const Point& min, const Point& max);
		void SetSize(float width, float height);
		void SetRotation(float rotation);

	private:
		float _Width;
		float _Height;
		float _HalfWidth;
		float _HalfHeight;
		Point _Center;
		Point _Min;
		Point _Max;
		float _Rotation;
		Color _Color;
	};
}
