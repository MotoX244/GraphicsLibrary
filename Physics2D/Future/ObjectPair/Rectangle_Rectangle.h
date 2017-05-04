#pragma once

#include "ObjectPair.h"
#include "Rectangle.h"


namespace Physics2D
{
	class Rectangle_Rectangle : public ObjectPair
	{
	public:
		Rectangle_Rectangle(Rectangle& rectangle1, Rectangle& rectangle2);
		~Rectangle_Rectangle() override {}
		Object& Object1() override { return _Rectangle1; }
		Object& Object2() override { return _Rectangle2; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Rectangle& _Rectangle1;
		Rectangle& _Rectangle2;
	};
}
