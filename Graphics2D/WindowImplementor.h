#pragma once

#include "Window.h"


namespace Graphics2D
{
	class Canvas;

	class WindowImplementor
	{
	public:
		virtual ~WindowImplementor() {}
		virtual int ClientWidth() const = 0;
		virtual int ClientHeight() const = 0;
		virtual WindowState GetState() const = 0;
		virtual void Draw(const Canvas& canvas) = 0;

	protected:
		WindowImplementor() {}
	};
}
