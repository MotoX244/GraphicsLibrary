#pragma once

#include "GraphicsLibrary.h"
#include "Bitmap.h"

namespace Graphics
{
	class GRAPHICS_LIBRARY Point
	{
	public:
		Point();
		~Point();
		void Draw(Bitmap& bitmap);

		float x;
		float y;
	};
}
