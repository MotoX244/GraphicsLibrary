#pragma once

#include "ObjectPair.h"
#include "Line.h"
#include "Rectangle.h"


namespace Physics2D
{
	class Line_Rectangle : public ObjectPair
	{
	public:
		Line_Rectangle(Line& line, Rectangle& rectangle);
		~Line_Rectangle() override {}
		Object& Object1() override { return _Line; }
		Object& Object2() override { return _Rectangle; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Line& _Line;
		Rectangle& _Rectangle;
	};
}
