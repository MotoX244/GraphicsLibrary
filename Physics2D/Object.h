#pragma once

#include <vector>
#include <functional>
#include "ObjectType.h"
#include "Vector.h"


namespace Physics2D
{
	class Object
	{
	public:
		virtual ~Object() {}

		virtual ObjectType Type() const = 0;
		float X() const { return _Position.X; }
		float Y() const { return _Position.Y; }
		Vector Position() const { return _Position; }
		Vector PreviousPosition() const { return _PreviousPosition; }
		float Mass() const { return _Mass; }
		float InverseMass() const { return _InverseMass; }
		float Drag() const { return _Drag; }
		float Restitution() const { return _Restitution; }
		float VelocityX() const { return _Velocity.X; }
		float VelocityY() const { return _Velocity.Y; }
		Vector Velocity() const { return _Velocity; }
		Vector PreviousVelocity() const { return _PreviousVelocity; }
		Vector Acceleration() const { return _Acceleration; }
		bool Sleeping() const { return _Sleeping; }
		void* Identifier() const { return _Identifier; }

		virtual void SetPosition(const Vector& position);
		virtual void SetPreviousPosition(const Vector& position);
		void SetMass(float mass);
		void SetDrag(float drag);
		void SetRestitution(float restitution);
		void SetVelocity(const Vector& velocity);
		void SetPreviousVelocity(const Vector& velocity);
		void SetAcceleration(const Vector& acceleration);
		void Sleep(Object& restingObject);
		void Awaken();
		void SetIdentifier(void* identifier);

		virtual void AdjustPosition(const Vector& amount);
		virtual void AdjustPreviousPosition(const Vector& amount);
		void AdjustVelocity(const Vector& amount);
		void AdjustAcceleration(const Vector& amount);

		typedef void (CollisionCallback)(Object* object1, Object* object2);
		void SetCollisionCallback(std::function<CollisionCallback> collisionCallback);
		void Collision(Object* otherObject);

	protected:
		Object(const Vector& position, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);

		Vector _Position;
		Vector _PreviousPosition;
		Vector _Velocity;
		Vector _PreviousVelocity;
		Vector _Acceleration;
		float _Mass;
		float _InverseMass;
		float _Drag;
		float _Restitution;
		bool _Sleeping;
		void* _Identifier;
		std::vector<Object*> _RestingObjects;
		std::function<CollisionCallback> _CollisionCallback;
	};
}
