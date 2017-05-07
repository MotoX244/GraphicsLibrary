#pragma once

#include "../Object.h"


namespace Physics2D
{
	class Line : public Object
	{
	public:
		Line(const Vector& position, float rotation, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		ObjectType Type() const override;
		float Rotation() const;
		void SetRotation(float rotation);
		void AdjustRotation(float amount);

	private:
		void NormalizeRotation();

		float _Rotation;
	};
}
