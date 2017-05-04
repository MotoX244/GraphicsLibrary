#pragma once

#include "Object.h"


namespace Physics2D
{
	class Line : public Object
	{
	public:
		Line(const Vector& position, float length, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		ObjectType Type() override;
		float Length();
		void SetLength(float length);
		void AdjustLength(float amount);

	private:
		float _Length;
	};
}
