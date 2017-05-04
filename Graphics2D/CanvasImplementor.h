#pragma once


namespace Graphics2D
{
	class Color;
	class Line;
	class Circle;
	class Rectangle;
	class Bitmap;

	class CanvasImplementor
	{
	public:
		virtual ~CanvasImplementor() {};
		virtual int Width() const = 0;
		virtual int Height() const = 0;
		virtual const char* GetBitmap() const = 0;
		virtual void SetSize(int width, int height) = 0;
		virtual void Clear(const Color& color) = 0;
		virtual void Draw(const Line& line) = 0;
		virtual void Draw(const Circle& circle) = 0;
		virtual void Draw(const Rectangle& rectangle) = 0;
		virtual void Draw(const Bitmap& bitmap) = 0;

	protected:
		CanvasImplementor() {};
	};
}
