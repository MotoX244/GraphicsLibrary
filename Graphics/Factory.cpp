#include "CanvasImplementor_WinAPI.h"
#include "WindowImplementor_WinAPI.h"
#include "Factory.h"

using namespace Graphics;


CanvasImplementor* Factory::CreateCanvas(int height, int width)
{
	return new CanvasImplementor_WinAPI(height, width);
}


void Factory::DestroyCanvas(CanvasImplementor* canvas)
{
	delete reinterpret_cast<CanvasImplementor_WinAPI*>(canvas);
}


WindowImplementor* Factory::CreateWindow(int x, int y, int height, int width)
{
	return new WindowImplementor_WinAPI(x, y, height, width);
}


void Factory::DestroyWindow(WindowImplementor* window)
{
	delete reinterpret_cast<WindowImplementor_WinAPI*>(window);
}
