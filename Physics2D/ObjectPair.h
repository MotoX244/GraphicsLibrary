#pragma once

#include "Vector.h"


namespace Physics2D
{
	class Object;

	class ObjectPair
	{
	public:
		virtual ~ObjectPair() {}
		virtual Object& Object1() = 0;
		virtual Object& Object2() = 0;
		virtual bool Contains(const Object* object) const = 0;
		virtual void FindCollision() = 0;
		float TimeOfCollision() { return _TimeOfCollision; }
		const Vector& CollisionNormal() { return _CollisionNormal; }

	protected:
		ObjectPair() : _TimeOfCollision(0) {}
		float _TimeOfCollision;
		Vector _CollisionNormal;
	};
}
