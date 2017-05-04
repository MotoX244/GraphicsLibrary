#pragma once

#include "../ObjectPair.h"


namespace Physics2D
{
	class Object;
	class Circle;
	class AxisAlignedLine;

	class Circle_AxisAlignedLine : public ObjectPair
	{
	public:
		Circle_AxisAlignedLine(Circle& circle, AxisAlignedLine& line);
		~Circle_AxisAlignedLine() override {}
		Object& Object1() override;
		Object& Object2() override;
		bool Contains(const Object* object) const override;
		void FindCollision() override;

	private:
		Circle& _Circle;
		AxisAlignedLine& _Line;
	};
}
