#pragma once

#include "ObjectPair.h"
#include "Circle.h"
#include "Rectangle.h"


namespace Physics2D
{
	class Circle_Rectangle : public ObjectPair
	{
	public:
		Circle_Rectangle(Circle& circle, Rectangle& rectangle);
		~Circle_Rectangle() override {}
		Object& Object1() override { return _Circle; }
		Object& Object2() override { return _Rectangle; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		bool IsCollision(const Vector& circlePosition, const Vector& rectanglePosition);

		Circle& _Circle;
		Rectangle& _Rectangle;
	};
}
