#include "Ball.h"

using namespace Physics2D;
using namespace Graphics2D;


Ball::Ball(float diameter)
	//: _PhysicsCircle(Vector(0, 0), diameter, diameter, Vector(0, 0), Vector(0, 0), 1, 0, 1, this)
	: _PhysicsCircle(Vector(0, 0), diameter / 2, Vector(0, 0), Vector(0, 0), 1, 0, 1, this)
	, _GraphicsCircle(Point(0, 0), diameter / 2, Color(255, 0, 0, 255))
{
}


void Ball::SetPosition(float x, float y)
{
	_GraphicsCircle.SetCenter(Point(x, y));
	_PhysicsCircle.SetPosition(Vector(x, y));
}


void Ball::SetVelocity(float speed, float direction)
{
	constexpr float degreesToRadians = 0.01745329251994329576923690768489f;
	float radians = direction * degreesToRadians;

	Vector v(cos(radians), sin(radians));
	v *= speed;
	_PhysicsCircle.SetVelocity(v);
}


void Ball::Reposition()
{
	Vector v = _PhysicsCircle.Position();
	_GraphicsCircle.SetCenter(Point(v.X, v.Y));
}
