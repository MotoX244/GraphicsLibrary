#include "Goal.h"

using namespace Physics2D;
using namespace Graphics2D;


Goal::Goal(float minX, float minY, float maxX, float maxY)
	: _PhysicsRectangle(Vector(minX, minY), Vector(maxX, maxY), Vector(0, 0), Vector(0, 0), 0, 0, 1, this)
	, _GraphicsRectangle(Point(minX, minY), Point(maxX, maxY), 0, Color(128, 255, 128, 255))
{
}
