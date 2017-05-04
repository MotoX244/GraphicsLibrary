#include "Camera.h"

using namespace Graphics2D;


Camera::Camera(float x, float y)
	: _X(x)
	, _Y(y)
{
}


Camera::~Camera()
{
}


float Camera::X()
{
	return _X;
}


float Camera::Y()
{
	return _Y;
}
