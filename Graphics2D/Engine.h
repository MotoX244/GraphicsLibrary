#pragma once

#include <memory>
#include <vector>


namespace Graphics2D
{
	class Line;
	class Circle;
	class Rectangle;
	class Bitmap;
	class Canvas;

	class Engine
	{
	public:
		Engine(Canvas& canvas);
		void AddObject(Line& line);
		void AddObject(Circle& circle);
		void AddObject(Rectangle& rectangle);
		void AddObject(Bitmap& bitmap);
		void RemoveObject(Line& line);
		void RemoveObject(Circle& circle);
		void RemoveObject(Rectangle& rectangle);
		void RemoveObject(Bitmap& bitmap);
		void Render();

	private:
		Canvas& _Canvas;
		std::unique_ptr<std::vector<Line*>> _Lines;
		std::unique_ptr<std::vector<Circle*>> _Circles;
		std::unique_ptr<std::vector<Rectangle*>> _Rectangles;
		std::unique_ptr<std::vector<Bitmap*>> _Bitmaps;
	};
}
