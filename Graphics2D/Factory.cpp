#include "CanvasImplementor_WinAPI.h"
#include "WindowImplementor_WinAPI.h"
#include "Factory.h"

using namespace Graphics2D;


CanvasImplementor* Factory::CreateCanvas(Camera& camera, int width, int height)
{
	return new CanvasImplementor_WinAPI(camera, width, height);
}


WindowImplementor* Factory::CreateWindow(int x, int y, int width, int height, WindowState state, WindowEventHandler eventHandler, void* eventParameter)
{
	return new WindowImplementor_WinAPI(x, y, width, height, state, eventHandler, eventParameter);
}
