#pragma once

#include "CanvasImplementor.h"
#include "WindowImplementor.h"

#undef CreateWindow

namespace Graphics
{
	class Factory
	{
	public:
		static CanvasImplementor* CreateCanvas(int height, int width);
		static WindowImplementor* CreateWindow(int x, int y, int height, int width);
		static void DestroyCanvas(CanvasImplementor* canvas);
		static void DestroyWindow(WindowImplementor* window);

	private:
		Factory() {}
	};
}
