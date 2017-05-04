#pragma once

#include "ObjectPair.h"
#include "Circle.h"


namespace Physics2D
{
	class Circle_Circle : public ObjectPair
	{
	public:
		Circle_Circle(Circle& circle1, Circle& circle2);
		~Circle_Circle() override {}
		Object& Object1() override { return _Circle1; }
		Object& Object2() override { return _Circle2; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Circle& _Circle1;
		Circle& _Circle2;
	};
}
