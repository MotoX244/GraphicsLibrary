#pragma once

#include "GraphicsLibrary.h"
#include "Color.h"

namespace Graphics
{
	class GRAPHICS_LIBRARY Line
	{
	public:
		Line();
		Line(int x1, int y1, int x2, int y2, Color& color);
		~Line();
		int X1() const;
		int Y1() const;
		int X2() const;
		int Y2() const;
		const Color& GetColor() const;
		void SetPosition(int x1, int y1, int x2, int y2);

	private:
		int _X1;
		int _Y1;
		int _X2;
		int _Y2;
		Color _Color;
	};
}