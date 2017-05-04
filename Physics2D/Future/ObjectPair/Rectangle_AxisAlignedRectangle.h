#pragma once

#include "ObjectPair.h"
#include "Rectangle.h"
#include "AxisAlignedRectangle.h"


namespace Physics2D
{
	class Rectangle_AxisAlignedRectangle : public ObjectPair
	{
	public:
		Rectangle_AxisAlignedRectangle(Rectangle& rectangle1, AxisAlignedRectangle& rectangle2);
		~Rectangle_AxisAlignedRectangle() override {}
		Object& Object1() override { return _Rectangle1; }
		Object& Object2() override { return _Rectangle2; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Rectangle& _Rectangle1;
		AxisAlignedRectangle& _Rectangle2;
	};
}
