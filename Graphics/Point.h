#pragma once

#include "GraphicsLibrary.h"
#include "Color.h"

namespace Graphics
{
	class GRAPHICS_LIBRARY Point
	{
	public:
		Point();
		Point(int x, int y, Color& color);
		~Point();
		int X() const;
		int Y() const;
		const Color& GetColor() const;
		void SetPosition(int x, int y);

	private:
		int _X;
		int _Y;
		Color _Color;
	};
}
