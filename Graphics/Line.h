#pragma once

#include "GraphicsLibrary.h"
#include "Point.h"
#include "Bitmap.h"

namespace Graphics
{
	class GRAPHICS_LIBRARY Line
	{
	public:
		Line();
		~Line();
		void Draw(Bitmap& bitmap);

	private:
		Point _Start;
		Point _End;
	};
}