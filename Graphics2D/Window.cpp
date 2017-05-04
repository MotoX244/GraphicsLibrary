#include "Window.h"
#include "Canvas.h"
#include "WindowImplementor.h"
#include "Factory.h"

using namespace Graphics2D;


Window::Window(int x, int y, int width, int height, WindowState state, WindowEventHandler eventHandler, void* eventParameter)
	: _Implementor(Factory::CreateWindow(x, y, width, height, state, eventHandler, eventParameter))
{
}


Window::~Window()
{
}


int Window::ClientHeight() const
{
	return _Implementor->ClientHeight();
}


int Window::ClientWidth() const
{
	return _Implementor->ClientWidth();
}


WindowState Window::GetState() const
{
	return _Implementor->GetState();
}


void Window::Draw(const Canvas& canvas)
{
	_Implementor->Draw(canvas);
}
