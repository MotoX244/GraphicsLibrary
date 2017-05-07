#include "gtest/gtest.h"
#include <iostream>
#include <limits>
#include "Physics2D/Object/Circle.h"
#include "Physics2D/ObjectPair/Circle_Circle.h"

using namespace std;
using namespace Physics2D;


TEST(Circle_Circle_Test, Test1)
{
	Circle c1(Vector(1, 0), 1, Vector(1, 0), Vector(), 0, 0, 0);
	Circle c2(Vector(5, 0), 1, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 1.0f);
	Vector normal(1, 0);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test2)
{
	Circle c1(Vector(5, 0), 1, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle c2(Vector(1, 0), 1, Vector(1, 0), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 1.0f);
	Vector normal(1, 0);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test3)
{
	Circle c1(Vector(0, 1), 1, Vector(0, 1), Vector(), 0, 0, 0);
	Circle c2(Vector(0, 5), 1, Vector(0, -1), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 1.0f);
	Vector normal(0, -1);
	ASSERT_NEAR(cc.CollisionNormal().X, normal.X, numeric_limits<float>::epsilon() * 2);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test4)
{
	Circle c1(Vector(0, 5), 1, Vector(0, -1), Vector(), 0, 0, 0);
	Circle c2(Vector(0, 1), 1, Vector(0, 1), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 1.0f);
	Vector normal(0, 1);
	ASSERT_NEAR(cc.CollisionNormal().X, normal.X, numeric_limits<float>::epsilon() * 2);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test5)
{
	Circle c1(Vector(1, 3), 1, Vector(1, 0), Vector(), 0, 0, 0);
	Circle c2(Vector(3, 1), 1, Vector(0, 1), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, -1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test6)
{
	Circle c1(Vector(3, 1), 1, Vector(0, 1), Vector(), 0, 0, 0);
	Circle c2(Vector(1, 3), 1, Vector(1, 0), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, -1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test7)
{
	Circle c1(Vector(1, 3), 1, Vector(0, -1), Vector(), 0, 0, 0);
	Circle c2(Vector(3, 1), 1, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, -1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test8)
{
	Circle c1(Vector(3, 1), 1, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle c2(Vector(1, 3), 1, Vector(0, -1), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, -1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test9)
{
	Circle c1(Vector(1, 1), 1, Vector(1, 0), Vector(), 0, 0, 0);
	Circle c2(Vector(3, 3), 1, Vector(0, -1), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, 1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test10)
{
	Circle c1(Vector(3, 3), 1, Vector(0, -1), Vector(), 0, 0, 0);
	Circle c2(Vector(1, 1), 1, Vector(1, 0), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, 1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test11)
{
	Circle c1(Vector(1, 1), 1, Vector(0, 1), Vector(), 0, 0, 0);
	Circle c2(Vector(3, 3), 1, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, 1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}


TEST(Circle_Circle_Test, Test12)
{
	Circle c1(Vector(3, 3), 1, Vector(-1, 0), Vector(), 0, 0, 0);
	Circle c2(Vector(1, 1), 1, Vector(0, 1), Vector(), 0, 0, 0);
	Circle_Circle cc(c1, c2);
	cc.FindCollision(1);
	ASSERT_FLOAT_EQ(cc.TimeOfCollision(), 0.585786402f);
	Vector normal = Vector(1, 1).Normalize();
	ASSERT_FLOAT_EQ(cc.CollisionNormal().X, normal.X);
	ASSERT_FLOAT_EQ(cc.CollisionNormal().Y, normal.Y);
}