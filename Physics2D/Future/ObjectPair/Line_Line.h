#pragma once

#include "ObjectPair.h"
#include "Line.h"

namespace Physics2D
{
	class Line_Line : public ObjectPair
	{
	public:
		Line_Line(Line& line1, Line& line2);
		~Line_Line() override {}
		Object& Object1() override { return _Line1; }
		Object& Object2() override { return _Line2; }
		bool Contains(const Object* object) const override;
		bool IsCollision() override;
		void FindTimeOfCollision() override;

	private:
		Line& _Line1;
		Line& _Line2;
	};
}
