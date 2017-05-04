#pragma once

#include "ObjectPair.h"
#include "AxisAlignedLine.h"
#include "AxisAlignedRectangle.h"


namespace Physics2D
{
	class AxisAlignedLine_AxisAlignedRectangle : public ObjectPair
	{
	public:
		AxisAlignedLine_AxisAlignedRectangle(AxisAlignedLine& line, AxisAlignedRectangle& rectangle);
		~AxisAlignedLine_AxisAlignedRectangle() override {}
		Object& Object1() override { return _Line; }
		Object& Object2() override { return _Rectangle; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		AxisAlignedLine& _Line;
		AxisAlignedRectangle& _Rectangle;
	};
}
