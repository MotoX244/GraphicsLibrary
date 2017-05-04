#pragma once


namespace Physics2D
{
	class CollisionTime
	{
	public:
		CollisionTime(float min1, float center1, float max1, float velocity1, float min2, float center2, float max2, float velocity2);
		float Entry();
		float Exit();

	private:
		float _Entry;
		float _Exit;
	};
}
