#pragma once

#include "ObjectPair.h"
#include "AxisAlignedLine.h"


namespace Physics2D
{
	class AxisAlignedLine_AxisAlignedLine : public ObjectPair
	{
	public:
		AxisAlignedLine_AxisAlignedLine(AxisAlignedLine& line1, AxisAlignedLine& line2);
		~AxisAlignedLine_AxisAlignedLine() override {}
		Object& Object1() override { return _Line1; }
		Object& Object2() override { return _Line2; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		AxisAlignedLine& _Line1;
		AxisAlignedLine& _Line2;
	};
}
