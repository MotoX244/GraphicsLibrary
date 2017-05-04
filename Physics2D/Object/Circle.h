#pragma once

#include "../Object.h"


namespace Physics2D
{
	class Circle : public Object
	{
	public:
		Circle(const Vector& position, float radius, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		ObjectType Type() const override;
		float Radius() const;
		void SetRadius(float radius);
		void AdjustRadius(float amount);
		
	private:
		float _Radius;
	};
}
