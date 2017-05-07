#include "Goal.h"

using namespace Physics2D;
using namespace Graphics2D;


Goal::Goal(float x, float minY, float maxY)
	: _PhysicsLine(Vector(x, minY), 90, Vector(0, 0), Vector(0, 0), 0, 0, 1, this)
	, _GraphicsLine(Point(x, minY), Point(x, maxY), Color(128, 255, 128, 255))
{
}
