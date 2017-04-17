#pragma once

#include "Bitmap.h"

namespace Graphics
{
	class PointImplementor
	{
	public:
		PointImplementor();
		~PointImplementor();
		void Draw(Bitmap& bitmap);
	};
}
