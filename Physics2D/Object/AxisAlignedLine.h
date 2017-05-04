#pragma once

#include "../Object.h"


namespace Physics2D
{
	enum class Direction
	{
		Vertical,
		Horizontal
	};

	class AxisAlignedLine : public Object
	{
	public:
		AxisAlignedLine(const Vector& position, float length, Direction direction, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		AxisAlignedLine(const Vector& point1, const Vector& point2, Direction direction, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		ObjectType Type() const override;
		float Length() const;
		float HalfLength() const;
		Direction GetDirection() const;
		float Min() const;
		float Max() const;
		void SetLength(float length);
		void SetDirection(Direction direction);
		void AdjustLength(float amount);

	private:
		float _Length;
		float _HalfLength;
		Direction _Direction;
		float _Min;
		float _Max;
	};
}
