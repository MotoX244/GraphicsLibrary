#pragma once

#include "PointImplementor.h"
#include "LineImplementor.h"
#include "BitmapImplementor.h"

namespace Graphics
{
	class Factory
	{
	public:
		Factory();
		~Factory();
		PointImplementor* CreatePoint();
		LineImplementor* CreateLine();
		BitmapImplementor* CreateBitmap();
		void DestroyPoint(PointImplementor* point);
		void DestroyLine(LineImplementor* line);
		void DestroyBitmap(BitmapImplementor* bitmap);
	};
}
