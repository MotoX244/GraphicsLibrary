#include "Wall.h"

using namespace Physics2D;
using namespace Graphics2D;


Wall::Wall(float minX, float minY, float maxX, float maxY)
	: _PhysicsRectangle(Vector(minX, minY), Vector(maxX, maxY), Vector(0, 0), Vector(0, 0), 0, 0, 1, this)
	, _GraphicsRectangle(Point(minX, minY), Point(maxX, maxY), 0, Color(255, 255, 255, 255))
{
}
