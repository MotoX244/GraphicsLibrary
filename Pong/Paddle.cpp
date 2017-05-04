#include "Paddle.h"

using namespace Physics2D;
using namespace Graphics2D;


Paddle::Paddle(float x, float y, float width, float height)
	: _X(x)
	, _PhysicsRectangle(Vector(x, y), width, height, Vector(0, 0), Vector(0, 0), 0, 0, 1, this)
	, _GraphicsRectangle(Point(x, y), width, height, 0, Color(0, 0, 255, 255))
{
}


void Paddle::SetPosition(float y)
{
	_PhysicsRectangle.SetPosition(Vector(_X, y));
	_GraphicsRectangle.SetCenter(Point(_X, y));
}


void Paddle::Reposition()
{
	Vector v = _PhysicsRectangle.Position();
	_GraphicsRectangle.SetCenter(Point(v.X, v.Y));
}
