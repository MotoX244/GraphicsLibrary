#pragma once

#include "ObjectPair.h"
#include "Line.h"
#include "Circle.h"


namespace Physics2D
{
	class Line_Circle : public ObjectPair
	{
	public:
		Line_Circle(Line& line, Circle& circle);
		~Line_Circle() override {}
		Object& Object1() override { return _Line; }
		Object& Object2() override { return _Circle; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Line& _Line;
		Circle& _Circle;
	};
}
