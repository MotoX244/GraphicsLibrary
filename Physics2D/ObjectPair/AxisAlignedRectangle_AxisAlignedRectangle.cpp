#include <cmath>
#include <algorithm>
#include "AxisAlignedRectangle_AxisAlignedRectangle.h"
#include "../Object/AxisAlignedRectangle.h"
#include "../CollisionTime.h"

using namespace std;
using namespace Physics2D;


AxisAlignedRectangle_AxisAlignedRectangle::AxisAlignedRectangle_AxisAlignedRectangle(AxisAlignedRectangle& rectangle1, AxisAlignedRectangle& rectangle2)
	: _Rectangle1(rectangle1)
	, _Rectangle2(rectangle2)
{
}


Object& AxisAlignedRectangle_AxisAlignedRectangle::Object1()
{
	return _Rectangle1;
}


Object& AxisAlignedRectangle_AxisAlignedRectangle::Object2()
{
	return _Rectangle2;
}


bool AxisAlignedRectangle_AxisAlignedRectangle::Contains(const Object* object) const
{
	return object == &_Rectangle1 || object == &_Rectangle2;
}


void AxisAlignedRectangle_AxisAlignedRectangle::FindCollision()
{
	CollisionTime collisionX(_Rectangle1.MinX(), _Rectangle1.X(), _Rectangle1.MaxX(), _Rectangle1.VelocityX(), _Rectangle2.MinX(), _Rectangle2.X(), _Rectangle2.MaxX(), _Rectangle2.VelocityX());
	CollisionTime collisionY(_Rectangle1.MinY(), _Rectangle1.Y(), _Rectangle1.MaxY(), _Rectangle1.VelocityY(), _Rectangle2.MinY(), _Rectangle2.Y(), _Rectangle2.MaxY(), _Rectangle2.VelocityY());

	if ( collisionX.Entry() > collisionY.Entry() )
	{
		if ( collisionX.Entry() < collisionY.Exit() )
		{
			_CollisionNormal = Vector(1, 0);
			_TimeOfCollision = collisionX.Entry();
			return;
		}
	}
	else if ( collisionY.Entry() > collisionX.Entry() )
	{
		if ( collisionY.Entry() < collisionX.Exit() )
		{
			_CollisionNormal = Vector(0, 1);
			_TimeOfCollision = collisionY.Entry();
			return;
		}
	}
	else
	{
		if ( (_Rectangle2.X() > _Rectangle1.X() && _Rectangle2.Y() > _Rectangle1.Y()) || (_Rectangle2.X() < _Rectangle1.X() && _Rectangle2.Y() < _Rectangle1.Y()) )
		{
			_CollisionNormal = Vector(1, 1).Normalize();
		}
		else
		{
			_CollisionNormal = Vector(-1, 1).Normalize();
		}
		_TimeOfCollision = collisionX.Entry();
		return;
	}

	_TimeOfCollision = numeric_limits<float>::infinity();
}
