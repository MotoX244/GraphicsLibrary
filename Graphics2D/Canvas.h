#pragma once

#include <memory>

namespace Graphics2D
{
	class Color;
	class Line;
	class Circle;
	class Rectangle;
	class Bitmap;
	class Camera;
	class CanvasImplementor;

	class Canvas
	{
	public:
		explicit Canvas(Camera& camera, int width, int height);
		~Canvas();
		int Width() const;
		int Height() const;
		const char* GetBitmap() const;
		void SetSize(int width, int height);
		void Clear(const Color& color);
		void Draw(const Line& line);
		void Draw(const Circle& circle);
		void Draw(const Rectangle& rectangle);
		void Draw(const Bitmap& bitmap);

	private:
		std::unique_ptr<CanvasImplementor> _Implementor;
	};
}
