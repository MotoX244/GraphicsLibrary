#pragma once

#include "ObjectPair.h"
#include "Line.h"
#include "AxisAlignedLine.h"


namespace Physics2D
{
	class Line_AxisAlignedLine : public ObjectPair
	{
	public:
		Line_AxisAlignedLine(Line& line1, AxisAlignedLine& line2);
		~Line_AxisAlignedLine() override {}
		Object& Object1() override { return _Line1; }
		Object& Object2() override { return _Line2; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Line& _Line1;
		AxisAlignedLine& _Line2;
	};
}
