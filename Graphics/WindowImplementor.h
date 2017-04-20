#pragma once

#include "Window.h"


namespace Graphics
{
	class WindowImplementor
	{
	public:
		virtual int ClientHeight() const = 0;
		virtual int ClientWidth() const = 0;
		virtual void SetPosition(int x, int y) = 0;
		virtual void SetSize(int height, int width) = 0;
		virtual void Draw(Canvas& canvas) = 0;

	protected:
		WindowImplementor() {};
		virtual ~WindowImplementor() {};
	};
}
