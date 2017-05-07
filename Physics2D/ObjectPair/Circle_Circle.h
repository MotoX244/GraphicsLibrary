#pragma once

#include "../ObjectPair.h"


namespace Physics2D
{
	class Object;
	class Circle;

	class Circle_Circle : public ObjectPair
	{
	public:
		Circle_Circle(Circle& circle1, Circle& circle2);
		~Circle_Circle() override {}
		Object& Object1() override;
		Object& Object2() override;
		bool Contains(const Object* object) const override;
		void FindCollision(float seconds) override;

	private:
		Circle& _Circle1;
		Circle& _Circle2;
	};
}
