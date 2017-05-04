#include "Wall.h"

using namespace Physics2D;
using namespace Graphics2D;


Wall::Wall(float minX, float maxX, float y)
	: _PhysicsLine(Vector(minX, y), Vector(maxX, y), Direction::Horizontal, Vector(0, 0), Vector(0, 0), 0, 0, 1, this)
	, _GraphicsLine(Point(minX, y), Point(maxX, y), Color(255, 255, 255, 255))
{
}
