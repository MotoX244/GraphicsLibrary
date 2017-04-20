#pragma once

#include "Canvas.h"


namespace Graphics
{
	class CanvasImplementor
	{
	public:
		virtual int Height() const = 0;
		virtual int Width() const = 0;
		virtual const char* GetBitmap() const = 0;
		virtual void SetSize(int height, int width) = 0;
		virtual void Draw(Point& point) = 0;
		virtual void Draw(Line& line) = 0;
		virtual void Draw(Bitmap& bitmap) = 0;

	protected:
		CanvasImplementor() {};
		virtual ~CanvasImplementor() {};
	};
}
