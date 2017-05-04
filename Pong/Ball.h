#pragma once

//#include "Physics2D/Object/AxisAlignedRectangle.h"
#include "Physics2D/Object/Circle.h"
#include "Graphics2D/Object/Circle.h"


class Ball
{
public:
	Ball(float diameter);
	//operator Physics2D::AxisAlignedRectangle&() { return _PhysicsCircle; }
	operator Physics2D::Circle&() { return _PhysicsCircle; }
	operator Graphics2D::Circle&() { return _GraphicsCircle; }
	void SetPosition(float x, float y);
	void SetVelocity(float speed, float direction);
	void Reposition();

private:
	//Physics2D::AxisAlignedRectangle _PhysicsCircle;
	Physics2D::Circle _PhysicsCircle;
	Graphics2D::Circle _GraphicsCircle;
};
