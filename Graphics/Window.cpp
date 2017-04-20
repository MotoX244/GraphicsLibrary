#include "Window.h"
#include "Factory.h"

using namespace Graphics;


Window::Window(int x, int y, int height, int width)
	: _Implementor(Factory::CreateWindow(x, y, height, width))
{
}


Window::~Window()
{
	Factory::DestroyWindow(_Implementor);
}


int Window::ClientHeight() const
{
	return _Implementor->ClientHeight();
}


int Window::ClientWidth() const
{
	return _Implementor->ClientWidth();
}


void Window::SetPosition(int x, int y)
{
	_Implementor->SetPosition(x, y);
}


void Window::SetSize(int height, int width)
{
	_Implementor->SetSize(height, width);
}


void Window::Draw(Canvas& canvas)
{
	_Implementor->Draw(canvas);
}
