#pragma once

#include "../Object.h"


namespace Physics2D
{
	class AxisAlignedRectangle : public Object
	{
	public:
		AxisAlignedRectangle(const Vector& min, const Vector& max, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		AxisAlignedRectangle(const Vector& position, float width, float height, const Vector& velocity, const Vector& acceleration, float mass, float drag, float restitution, void* identifier = nullptr);
		ObjectType Type() const override;
		const Vector& Size() const;
		const Vector& HalfSize() const;
		float MinX() const;
		float MinY() const;
		float MaxX() const;
		float MaxY() const;
		const Vector& Min() const;
		const Vector& Max() const;
		void SetPosition(const Vector& position) override;
		void SetSize(const Vector& size);
		void AdjustPosition(const Vector& amount) override;
		void AdjustSize(const Vector& amount);

	private:
		Vector _Size;
		Vector _HalfSize;
		Vector _Min;
		Vector _Max;
	};
}
