#include "gtest/gtest.h"
#include <iostream>
#include <limits>
#include "Physics2D/Object/Circle.h"
#include "Physics2D/Object/AxisAlignedLine.h"
#include "Physics2D/ObjectPair/Circle_AxisAlignedLine.h"

using namespace std;
using namespace Physics2D;


TEST(Circle_AxisAlignedLine_Test, Test1)
{
	Circle circle(Vector(3, 2), 1, Vector(0, 1), Vector(), 0, 0, 0);
	AxisAlignedLine line(Vector(1, 4), 6, Direction::Horizontal, Vector(0, -1), Vector(), 0, 0, 0);
	Circle_AxisAlignedLine cc(circle, line);
	cc.FindCollision();
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.5f);
	Vector normal(0, -1);
	ASSERT_NEAR(cc.CollisionNormal().X, normal.X, numeric_limits<float>::epsilon() * 2);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_AxisAlignedLine_Test, Test2)
{
	Circle circle(Vector(3, 2), 1, Vector(1, 0), Vector(), 0, 0, 0);
	AxisAlignedLine line(Vector(4, 1), 6, Direction::Horizontal, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle_AxisAlignedLine cc(circle, line);
	cc.FindCollision();
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.5f);
	Vector normal(1, 0);
	ASSERT_NEAR(cc.CollisionNormal().X, normal.X, numeric_limits<float>::epsilon() * 2);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}