#include "Engine.h"
#include <algorithm>
#include <iostream>
#include "Factory.h"

using namespace std;
using namespace std::chrono;
using namespace Physics2D;


Engine::Engine(float fps, const Vector& gravity)
	: _FPS(fps)
	, _Gravity(gravity)
	, _PreviousTime(high_resolution_clock::now())
{
}


Engine::~Engine()
{
}


void Engine::SetFPS(float fps)
{
	_FPS = fps;
}


void Engine::SetGravity(const Vector& gravity)
{
	_Gravity = gravity;
}


void Engine::AddObject(Object& object)
{
	for ( auto existingObject : _Objects )
	{
		ObjectPair* objectPair = Factory::CreateObjectPair(object, *existingObject);
		if ( objectPair )
		{
			_ObjectPairs.push_back(objectPair);
		}
	}

	_Objects.push_back(&object);
}


void Engine::RemoveObject(Object& object)
{
	for ( auto objectPair = _ObjectPairs.begin(); objectPair != _ObjectPairs.end(); )
	{
		if ( (*objectPair)->Contains(&object) )
		{
			delete *objectPair;
			_ObjectPairs.erase(objectPair);
		}
		else
		{
			objectPair++;
		}
	}

	for ( auto existingObject = _Objects.begin(); existingObject != _Objects.end(); existingObject++ )
	{
		if ( *existingObject == &object )
		{
			_Objects.erase(existingObject);
			break;
		}
	}
}


void Engine::Update()
{
	auto currentTime = high_resolution_clock::now();
	duration<float> delta(currentTime - _PreviousTime);
	_PreviousTime = currentTime;

	float maxSeconds = 1 / _FPS;
	float secondsRemaining = delta.count();

	while ( secondsRemaining )
	{
		float seconds = secondsRemaining > maxSeconds ? maxSeconds : secondsRemaining;

		ObjectPair* objectPair = FindFirstCollision(seconds);
		if ( objectPair )
		{
			seconds = objectPair->TimeOfCollision();
		}

		for ( auto object : _Objects )
		{
			if ( object->Sleeping() )
			{
				continue;
			}

			Vector velocity = object->Velocity();
			object->AdjustPosition(velocity * seconds);

			if ( object->InverseMass() != 0 )
			{
				velocity += _Gravity * seconds;
				velocity += (velocity * object->Drag()) * seconds;
				object->SetVelocity(velocity);
			}
		}

		if ( objectPair )
		{
			HandleCollision(*objectPair);
		}

		secondsRemaining -= seconds;
	}
}


ObjectPair* Engine::FindFirstCollision(float seconds)
{
	ObjectPair* firstCollision = nullptr;

	for ( auto objectPair : _ObjectPairs )
	{
		objectPair->FindCollision(seconds);

		if ( objectPair->TimeOfCollision() >= 0 && objectPair->TimeOfCollision() < seconds && (!firstCollision || objectPair->TimeOfCollision() < firstCollision->TimeOfCollision()) )
		{
			firstCollision = objectPair;
		}
	}

	return firstCollision;
}


void Engine::HandleCollision(ObjectPair& objectPair)
{
	//const Vector sleepThreshold = -(_Gravity / _FPS); // numeric_limits<float>::epsilon() * 1000;

	Object& object1 = objectPair.Object1();
	Object& object2 = objectPair.Object2();

	object1.Collision(&object2);
	object2.Collision(&object1);

	if ( object1.Mass() == INFINITE_MASS && object2.Mass() == INFINITE_MASS )
	{
		if ( object2.Velocity() )
		{
			object2.SetVelocity(Vector(0, 0));
			object2.SetPreviousVelocity(Vector(0, 0));
			object2.SetPosition(object2.PreviousPosition());
		}

		if ( object1.Velocity() )
		{
			object1.SetVelocity(Vector(0, 0));
			object1.SetPreviousVelocity(Vector(0, 0));
			object1.SetPosition(object1.PreviousPosition());
		}
	}
	else
	{

		Vector velocity1 = object1.Velocity();
		Vector velocity2 = object2.Velocity();
		float inverseMass1 = object1.InverseMass();
		float inverseMass2 = object2.InverseMass();
		Vector collisionNormal = objectPair.CollisionNormal();

		Vector relativeVelocity = velocity2 - velocity1;

		float velocityAlongNormal = relativeVelocity.DotProduct(collisionNormal);

		float restitution = min(object1.Restitution(), object2.Restitution());

		float impulseScalar = velocityAlongNormal * ((restitution + 1) * -1);
		impulseScalar /= inverseMass1 + inverseMass2;

		Vector impulse = collisionNormal * impulseScalar;

		velocity1 -= impulse * inverseMass1;
		velocity2 += impulse * inverseMass2;

		//if ( (object2.InverseMass() == 0 || object2.Sleeping()) && (velocity1 < sleepThreshold && velocity1 > Vector(0, 0)) )
		//{
		//	object1.SetPosition(object1.PreviousPosition());
		//	object1.Sleep(object2);
		//	object2.Sleep(object1);
		//	return;
		//}

		//if ( (object1.InverseMass() == 0 || object1.Sleeping()) && (velocity2 < sleepThreshold && velocity2 > Vector(0, 0)) )
		//{
		//	object2.SetPosition(object2.PreviousPosition());
		//	object2.Sleep(object1);
		//	object1.Sleep(object2);
		//	return;
		//}

		object1.SetVelocity(velocity1);
		object1.SetPreviousVelocity(velocity1);
		//object1.SetPosition(object1.PreviousPosition());
		//object1.AdjustPosition(velocity1 * seconds);

		object2.SetVelocity(velocity2);
		object2.SetPreviousVelocity(velocity2);
		//object2.SetPosition(object2.PreviousPosition());
		//object2.AdjustPosition(velocity2 * seconds);

		//while ( objectPair.IsCollision() )
		//{
		//	if ( object1.Position() > object2.Position() )
		//	{
		//		object1.SetPosition(Vector(nextafter(object1.Position().X, FLT_MAX), nextafter(object1.Position().Y, FLT_MAX)));
		//		object1.SetPosition(object1.PreviousPosition());
		//	}
		//	else
		//	{
		//		object2.SetPosition(Vector(nextafter(object2.Position().X, FLT_MAX), nextafter(object2.Position().Y, FLT_MAX)));
		//		object2.SetPosition(object2.PreviousPosition());
		//	}
		//}
	}
}
