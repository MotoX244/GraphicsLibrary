#pragma once

#include "Bitmap.h"

namespace Graphics
{
	class LineImplementor
	{
	public:
		LineImplementor();
		~LineImplementor();
		void Draw(Bitmap& bitmap);
	};
}