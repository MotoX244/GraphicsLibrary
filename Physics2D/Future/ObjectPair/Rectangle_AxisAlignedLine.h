#pragma once

#include "ObjectPair.h"
#include "Rectangle.h"
#include "AxisAlignedLine.h"


namespace Physics2D
{
	class Rectangle_AxisAlignedLine : public ObjectPair
	{
	public:
		Rectangle_AxisAlignedLine(Rectangle& rectangle, AxisAlignedLine& line);
		~Rectangle_AxisAlignedLine() override {}
		Object& Object1() override { return _Rectangle; }
		Object& Object2() override { return _Line; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Rectangle& _Rectangle;
		AxisAlignedLine& _Line;
	};
}
