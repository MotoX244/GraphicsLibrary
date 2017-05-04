#pragma once

#include "ObjectPair.h"
#include "Line.h"
#include "AxisAlignedRectangle.h"


namespace Physics2D
{
	class Line_AxisAlignedRectangle : public ObjectPair
	{
	public:
		Line_AxisAlignedRectangle(Line& line, AxisAlignedRectangle& rectangle);
		~Line_AxisAlignedRectangle() override {}
		Object& Object1() override { return _Line; }
		Object& Object2() override { return _Rectangle; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Line& _Line;
		AxisAlignedRectangle& _Rectangle;
	};
}
