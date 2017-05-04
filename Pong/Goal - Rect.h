#pragma once

#include "Physics2D/Object/AxisAlignedRectangle.h"
#include "Graphics2D/Object/Rectangle.h"


class Goal
{
public:
	Goal(float minX, float minY, float maxX, float maxY);
	operator Physics2D::AxisAlignedRectangle&() { return _PhysicsRectangle; }
	operator Graphics2D::Rectangle&() { return _GraphicsRectangle; }

private:
	Physics2D::AxisAlignedRectangle _PhysicsRectangle;
	Graphics2D::Rectangle _GraphicsRectangle;
};
