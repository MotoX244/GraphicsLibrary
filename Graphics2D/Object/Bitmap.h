#pragma once

#include <memory>
#include <vector>
#include "../Point.h"


namespace Graphics2D
{
	class Color;

	class Bitmap
	{
	public:
		Bitmap(Point& center, int width, int height, const Color& color);
		Bitmap(float x, float y, int width, int height, const Color& color);
		float X() const;
		float Y() const;
		int Width() const;
		int Height() const;
		const char* Bits() const;
		void SetBits(const Color& color);
		void SetPosition(float x, float y);
		void SetSize(int width, int height);

	private:
		float _X;
		float _Y;
		Point _Center;
		int _Width;
		int _Height;
		std::unique_ptr<std::vector<char>> _Bits;
	};
}
