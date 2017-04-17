#pragma once

#include "GraphicsLibrary.h"

namespace Graphics
{
	class GRAPHICS_LIBRARY Bitmap
	{
	public:
		Bitmap();
		~Bitmap();
		void SetSize(int x, int y);
		void Draw(Bitmap& bitmap);

	private:
		char* _Bits;
	};
}
