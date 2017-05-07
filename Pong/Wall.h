#pragma once

#include "Physics2D/Object/Line.h"
#include "Graphics2D/Object/Line.h"


class Wall
{
public:
	Wall(float minX, float maxX, float y);
	operator Physics2D::Line&() { return _PhysicsLine; }
	operator Graphics2D::Line&() { return _GraphicsLine; }

private:
	Physics2D::Line _PhysicsLine;
	Graphics2D::Line _GraphicsLine;
};
