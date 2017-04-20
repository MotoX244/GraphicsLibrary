#pragma once

#include "GraphicsLibrary.h"
#include "Canvas.h"

namespace Graphics
{
	class WindowImplementor;

	class GRAPHICS_LIBRARY Window
	{
	public:
		explicit Window(int x, int y, int height, int width);
		~Window();
		int ClientHeight() const;
		int ClientWidth() const;
		void SetPosition(int x, int y);
		void SetSize(int height, int width);
		void Draw(Canvas& canvas);

	private:
		WindowImplementor* _Implementor;
	};
}
