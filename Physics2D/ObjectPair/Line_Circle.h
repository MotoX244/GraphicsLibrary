#pragma once

#include "../ObjectPair.h"


namespace Physics2D
{
	class Object;
	class Line;
	class Circle;

	class Line_Circle : public ObjectPair
	{
	public:
		Line_Circle(Line& line, Circle& circle);
		~Line_Circle() override {}
		Object& Object1() override;
		Object& Object2() override;
		bool Contains(const Object* object) const override;
		void FindCollision(float seconds) override;

	private:
		Line& _Line;
		Circle& _Circle;
	};
}
