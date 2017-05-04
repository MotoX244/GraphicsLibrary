#pragma once

#include "Physics2D/Object/AxisAlignedRectangle.h"
#include "Graphics2D/Object/Rectangle.h"


class Paddle
{
public:
	Paddle(float x, float y, float width, float height);
	operator Physics2D::AxisAlignedRectangle&() { return _PhysicsRectangle; }
	operator Graphics2D::Rectangle&() { return _GraphicsRectangle; }
	void SetPosition(float y);
	void Reposition();

private:
	float _X;
	Physics2D::AxisAlignedRectangle _PhysicsRectangle;
	Graphics2D::Rectangle _GraphicsRectangle;
};
