#pragma once

#include "GraphicsLibrary.h"
#include "Point.h"
#include "Line.h"
#include "Bitmap.h"

namespace Graphics
{
	class CanvasImplementor;

	class GRAPHICS_LIBRARY Canvas
	{
	public:
		explicit Canvas(int height, int width);
		~Canvas();
		int Height() const;
		int Width() const;
		const char* GetBitmap() const;
		void SetSize(int height, int width);
		void Draw(Point& point);
		void Draw(Line& line);
		void Draw(Bitmap& bitmap);

	private:
		CanvasImplementor* _Implementor;
	};
}
