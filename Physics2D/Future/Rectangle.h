#pragma once

#include "Object.h"


namespace Physics2D
{
	class Rectangle : public Object
	{
	public:
		Rectangle(const Vector& position, const Vector& size, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		ObjectType Type() override;
		float Left() const;
		float Right() const;
		float Top() const;
		float Bottom() const;
		const Vector& Size() const;
		const Vector& HalfSize() const;
		void SetPosition(const Vector& position) override;
		void SetSize(const Vector& size);
		void AdjustSize(const Vector& amount);

	private:
		Vector _Size;
		Vector _HalfSize;
		Vector _TopLeft;
		Vector _BottomRight;
	};
}
