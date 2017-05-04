#pragma once

#include "Window.h"
#include "Camera.h"

#undef CreateWindow


namespace Graphics2D
{
	class Camera;
	class CanvasImplementor;
	class WindowImplementor;

	class Factory
	{
	public:
		static CanvasImplementor* CreateCanvas(Camera& camera, int width, int height);
		static WindowImplementor* CreateWindow(int x, int y, int width, int height, WindowState state, WindowEventHandler eventHandler, void* eventParameter);

	private:
		Factory() {}
	};
}
