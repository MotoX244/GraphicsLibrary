#pragma once

#include "ObjectPair.h"
#include "Circle.h"
#include "AxisAlignedRectangle.h"


namespace Physics2D
{
	class Circle_AxisAlignedRectangle : public ObjectPair
	{
	public:
		Circle_AxisAlignedRectangle(Circle& circle, AxisAlignedRectangle& rectangle);
		~Circle_AxisAlignedRectangle() override {}
		Object& Object1() override { return _Circle; }
		Object& Object2() override { return _Rectangle; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Circle& _Circle;
		AxisAlignedRectangle& _Rectangle;
	};
}
