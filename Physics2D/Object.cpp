#include "Object.h"

using namespace std;
using namespace Physics2D;


Object::Object(const Vector& position, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier)
	: _Position(position)
	, _PreviousPosition(position)
	, _Velocity(velocity)
	, _PreviousVelocity(velocity)
	, _Acceleration(acceleration)
	, _Mass(mass)
	, _InverseMass((mass == 0) ? 0 : (1 / mass))
	, _Drag(drag)
	, _Restitution(restitution)
	, _Sleeping(false)
	, _Identifier(identifier)
	, _CollisionCallback(nullptr)
{
}


void Object::SetPosition(const Vector& position)
{
	_Position = position;
}


void Object::SetPreviousPosition(const Vector& position)
{
	_PreviousPosition = position;
}


void Object::SetMass(float mass)
{
	_Mass = mass;
	_InverseMass = (_Mass == 0) ? 0 : (1 / _Mass);
}


void Object::SetDrag(float drag)
{
	_Drag = drag;
}


void Object::SetRestitution(float restitution)
{
	_Restitution = restitution;
}


void Object::SetVelocity(const Vector& velocity)
{
	_Velocity = velocity;
	Awaken();
}


void Object::SetPreviousVelocity(const Vector& velocity)
{
	_PreviousVelocity = velocity;
}


void Object::SetAcceleration(const Vector& acceleration)
{
	_Acceleration = acceleration;
}


void Object::Sleep(Object& restingObject)
{
	_Sleeping = true;
	_Velocity = Vector(0, 0);
	_PreviousVelocity = Vector(0, 0);
	_RestingObjects.push_back(&restingObject);
}


void Object::Awaken()
{
	_Sleeping = false;

	while ( _RestingObjects.size() )
	{
		Object* object = _RestingObjects.back();
		_RestingObjects.pop_back();
		object->Awaken();
	}
}


void Object::SetIdentifier(void* identifier)
{
	_Identifier = identifier;
}


void Object::SetCollisionCallback(function<CollisionCallback> collisionCallback)
{
	_CollisionCallback = collisionCallback;
}


void Object::AdjustPosition(const Vector& amount)
{
	_PreviousPosition = _Position;
	_Position += amount;
}


void Object::AdjustPreviousPosition(const Vector& amount)
{
	_PreviousPosition += amount;
}


void Object::AdjustVelocity(const Vector& amount)
{
	_Velocity += amount;
}


void Object::AdjustAcceleration(const Vector& amount)
{
	_Acceleration += amount;
}


void Object::Collision(Object* otherObject)
{
	if ( _CollisionCallback )
	{
		_CollisionCallback(this, otherObject);
	}
}