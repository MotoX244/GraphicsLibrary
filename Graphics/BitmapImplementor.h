#pragma once

#include "Bitmap.h"

namespace Graphics
{
	class BitmapImplementor
	{
	public:
		BitmapImplementor();
		~BitmapImplementor();
		void SetSize(int x, int y);
		void Draw(Bitmap& bitmap);
	};
}
