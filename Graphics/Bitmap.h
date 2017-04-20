#pragma once

#include "GraphicsLibrary.h"
#include <vector>
#include "Color.h"


namespace Graphics
{
	class GRAPHICS_LIBRARY Bitmap
	{
	public:
		Bitmap();
		Bitmap(int x, int y, int height, int width, Color& color);
		~Bitmap();
		int X() const;
		int Y() const;
		int Height() const;
		int Width() const;
		const char* Bits() const;
		void SetBits(Color& color);
		void SetPosition(int x, int y);
		void SetSize(int height, int width);

	private:
		int _X;
		int _Y;
		int _Height;
		int _Width;
		std::vector<char>* _Bits;
	};
}
