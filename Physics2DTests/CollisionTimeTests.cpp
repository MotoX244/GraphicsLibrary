#include "gtest/gtest.h"
#include "Physics2D/CollisionTime.h"
#include <iostream>

using namespace std;
using namespace Physics2D;


TEST(CollisionTimeTest, OnLeftMoveRight_OnRightMoveLeft_WillEnter_WillExit)
{
	CollisionTime ct(1, 2, 3, 3, 10, 12, 14, -2);
	ASSERT_EQ(ct.Entry(), 1.4f);
	ASSERT_EQ(ct.Exit(), 2.6f);
}

TEST(CollisionTimeTest, OnRightMoveLeft_OnLeftMoveRight_WillEnter_WillExit)
{
	CollisionTime ct(10, 12, 14, -2, 1, 2, 3, 3);
	ASSERT_EQ(ct.Entry(), 1.4f);
	ASSERT_EQ(ct.Exit(), 2.6f);
}


TEST(CollisionTimeTest, OnLeftMoveRight_OnRightMoveRight_WillEnter_WillExit)
{
	CollisionTime ct(1, 2, 3, 3, 10, 12, 14, 2);
	ASSERT_EQ(ct.Entry(), 7.0f);
	ASSERT_EQ(ct.Exit(), 13.0f);
}

TEST(CollisionTimeTest, OnRightMoveRight_OnLeftMoveRight_WillEnter_WillExit)
{
	CollisionTime ct(10, 12, 14, 2, 1, 2, 3, 3);
	ASSERT_EQ(ct.Entry(), 7.0f);
	ASSERT_EQ(ct.Exit(), 13.0f);
}


TEST(CollisionTimeTest, OnLeftMoveLeft_OnRightMoveLeft_WillEnter_WillExit)
{
	CollisionTime ct(1, 2, 3, -2, 10, 12, 14, -3);
	ASSERT_EQ(ct.Entry(), 7.0f);
	ASSERT_EQ(ct.Exit(), 13.0f);
}

TEST(CollisionTimeTest, OnRightMoveLeft_OnLeftMoveLeft_WillEnter_WillExit)
{
	CollisionTime ct(10, 12, 14, -3, 1, 2, 3, -2);
	ASSERT_EQ(ct.Entry(), 7.0f);
	ASSERT_EQ(ct.Exit(), 13.0f);
}



TEST(CollisionTimeTest, OnLeftMoveLeft_OnRightMoveRight_DidEnter_DidExit)
{
	CollisionTime ct(1, 2, 3, -3, 10, 12, 14, 2);
	ASSERT_EQ(ct.Entry(), -2.6f);
	ASSERT_EQ(ct.Exit(), -1.4f);
}

TEST(CollisionTimeTest, OnRightMoveRight_OnLeftMoveLeft_DidEnter_DidExit)
{
	CollisionTime ct(10, 12, 14, 2, 1, 2, 3, -3);
	ASSERT_EQ(ct.Entry(), -2.6f);
	ASSERT_EQ(ct.Exit(), -1.4f);
}


TEST(CollisionTimeTest, OnLeftMoveRight_OnRightMoveRight_DidEnter_DidExit)
{
	CollisionTime ct(1, 2, 3, 2, 10, 12, 14, 3);
	ASSERT_EQ(ct.Entry(), -13.0f);
	ASSERT_EQ(ct.Exit(), -7.0f);
}

TEST(CollisionTimeTest, OnRightMoveRight_OnLeftMoveRight_DidEnter_DidExit)
{
	CollisionTime ct(10, 12, 14, 3, 1, 2, 3, 2);
	ASSERT_EQ(ct.Entry(), -13.0f);
	ASSERT_EQ(ct.Exit(), -7.0f);
}


TEST(CollisionTimeTest, OnLeftMoveLeft_OnRightMoveLeft_DidEnter_DidExit)
{
	CollisionTime ct(1, 2, 3, -3, 10, 12, 14, -2);
	ASSERT_EQ(ct.Entry(), -13.0f);
	ASSERT_EQ(ct.Exit(), -7.0f);
}

TEST(CollisionTimeTest, OnRightMoveLeft_OnLeftMoveLeft_DidEnter_DidExit)
{
	CollisionTime ct(10, 12, 14, -2, 1, 2, 3, -3);
	ASSERT_EQ(ct.Entry(), -13.0f);
	ASSERT_EQ(ct.Exit(), -7.0f);
}



TEST(CollisionTimeTest, OnLeftMoveRight_OnRightMoveRight_ForeverEnter_NeverExit)
{
	CollisionTime ct(1, 3, 5, 3, 4, 7, 10, 3);
	ASSERT_EQ(ct.Entry(), -numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), numeric_limits<float>::infinity());
}

TEST(CollisionTimeTest, OnRightMoveRight_OnLeftMoveRight_ForeverEnter_NeverExit)
{
	CollisionTime ct(4, 7, 10, 3, 1, 3, 5, 3);
	ASSERT_EQ(ct.Entry(), -numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), numeric_limits<float>::infinity());
}


TEST(CollisionTimeTest, OnLeftMoveLeft_OnRightMoveLeft_ForeverEnter_NeverExit)
{
	CollisionTime ct(1, 3, 5, -3, 4, 7, 10, -3);
	ASSERT_EQ(ct.Entry(), -numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), numeric_limits<float>::infinity());
}

TEST(CollisionTimeTest, OnRightMoveLeft_OnLeftMoveLeft_ForeverEnter_NeverExit)
{
	CollisionTime ct(4, 7, 10, -3, 1, 3, 5, -3);
	ASSERT_EQ(ct.Entry(), -numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), numeric_limits<float>::infinity());
}



TEST(CollisionTimeTest, OnLeftMoveRight_OnRightMoveRight_NeverEnter_ForeverExit)
{
	CollisionTime ct(1, 2, 3, 3, 4, 7, 10, 3);
	ASSERT_EQ(ct.Entry(), numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), -numeric_limits<float>::infinity());
}

TEST(CollisionTimeTest, OnRightMoveRight_OnLeftMoveRight_NeverEnter_ForeverExit)
{
	CollisionTime ct(4, 7, 10, 3, 1, 2, 3, 3);
	ASSERT_EQ(ct.Entry(), numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), -numeric_limits<float>::infinity());
}


TEST(CollisionTimeTest, OnLeftMoveLeft_OnRightMoveLeft_NeverEnter_ForeverExit)
{
	CollisionTime ct(1, 2, 3, -3, 4, 7, 10, -3);
	ASSERT_EQ(ct.Entry(), numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), -numeric_limits<float>::infinity());
}

TEST(CollisionTimeTest, OnRightMoveLeft_OnLeftMoveLeft_NeverEnter_ForeverExit)
{
	CollisionTime ct(4, 7, 10, -3, 1, 2, 3, -3);
	ASSERT_EQ(ct.Entry(), numeric_limits<float>::infinity());
	ASSERT_EQ(ct.Exit(), -numeric_limits<float>::infinity());
}
