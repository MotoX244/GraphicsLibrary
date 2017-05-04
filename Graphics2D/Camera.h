#pragma once


namespace Graphics2D
{
	class Camera
	{
	public:
		Camera(float x, float y);
		~Camera();
		float X();
		float Y();

	private:
		float _X;
		float _Y;
	};
}
