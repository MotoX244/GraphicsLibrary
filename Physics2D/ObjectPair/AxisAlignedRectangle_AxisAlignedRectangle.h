#pragma once

#include "../ObjectPair.h"


namespace Physics2D
{
	class Object;
	class AxisAlignedRectangle;

	class AxisAlignedRectangle_AxisAlignedRectangle : public ObjectPair
	{
	public:
		AxisAlignedRectangle_AxisAlignedRectangle(AxisAlignedRectangle& rectangle1, AxisAlignedRectangle& rectangle2);
		~AxisAlignedRectangle_AxisAlignedRectangle() override {}
		Object& Object1() override;
		Object& Object2() override;
		bool Contains(const Object* object) const override;
		void FindCollision(float seconds) override;

	private:
		AxisAlignedRectangle& _Rectangle1;
		AxisAlignedRectangle& _Rectangle2;
	};
}
