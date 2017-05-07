#include "gtest/gtest.h"
#include <iostream>
#include <limits>
#include "Physics2D/Object/Line.h"
#include "Physics2D/Object/Circle.h"
#include "Physics2D/ObjectPair/Line_Circle.h"

using namespace std;
using namespace Physics2D;


TEST(Line_Circle_Test, Test1)
{
	Line line(Vector(0, 4), 0, Vector(0, -1), Vector(), 0, 0, 0);
	Circle circle(Vector(3, 2), 1, Vector(4, 1), Vector(), 0, 0, 0);
	Line_Circle lc(line, circle);
	lc.FindCollision(1);
	ASSERT_FLOAT_EQ(lc.TimeOfCollision(), 0.5f);
	Vector normal(0, 1);
	ASSERT_FLOAT_EQ(lc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(lc.CollisionNormal().Y, normal.Y);
}


TEST(Line_Circle_Test, Test2)
{
	Line line(Vector(0, 2), 0, Vector(0, 1), Vector(), 0, 0, 0);
	Circle circle(Vector(3, 4), 1, Vector(4, -1), Vector(), 0, 0, 0);
	Line_Circle lc(line, circle);
	lc.FindCollision(1);
	ASSERT_FLOAT_EQ(lc.TimeOfCollision(), 0.5f);
	Vector normal(0, 1);
	ASSERT_FLOAT_EQ(lc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(lc.CollisionNormal().Y, normal.Y);
}


TEST(Line_Circle_Test, Test3)
{
	Line line(Vector(4, 0), 90, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle circle(Vector(2, 3), 1, Vector(1, 4), Vector(), 0, 0, 0);
	Line_Circle lc(line, circle);
	lc.FindCollision(1);
	ASSERT_FLOAT_EQ(lc.TimeOfCollision(), 0.5f);
	Vector normal(-1, 0);
	ASSERT_NEAR(lc.CollisionNormal().X, normal.X, numeric_limits<float>::epsilon() * 2);
	ASSERT_NEAR(lc.CollisionNormal().Y, normal.Y, numeric_limits<float>::epsilon() * 2);
}


TEST(Line_Circle_Test, Test4)
{
	Line line(Vector(2, 0), 90, Vector(1, 0), Vector(), 0, 0, 0);
	Circle circle(Vector(4, 3), 1, Vector(-1, 4), Vector(), 0, 0, 0);
	Line_Circle lc(line, circle);
	lc.FindCollision(1);
	ASSERT_FLOAT_EQ(lc.TimeOfCollision(), 0.5f);
	Vector normal(-1, 0);
	ASSERT_FLOAT_EQ(lc.CollisionNormal().X, normal.X);
	ASSERT_NEAR(lc.CollisionNormal().Y, normal.Y, numeric_limits<float>::epsilon() * 2);
}


TEST(Line_Circle_Test, Test5)
{
	Line line(Vector(0, 4), 0, Vector(0, 0), Vector(), 0, 0, 0);
	Circle circle(Vector(2, 3), 1, Vector(1, -1), Vector(), 0, 0, 0);
	Line_Circle lc(line, circle);
	lc.FindCollision(1);
	ASSERT_FLOAT_EQ(lc.TimeOfCollision(), numeric_limits<float>::infinity());
}
