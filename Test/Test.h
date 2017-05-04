#pragma once

#include "../Graphics/Window.h"
#include "../Graphics/Canvas.h"
#include "../Graphics/Point.h"
#include "../Graphics/Line.h"
#include "../Graphics/Bitmap.h"


class Test
{
public:
	Test();
	void Run();

private:
	volatile bool _Run;
	volatile bool _Resize;
	Graphics::Window _Window;
	Graphics::Canvas _Canvas;
	Graphics::Point _Point;
	Graphics::Line _Line;
	Graphics::Bitmap _Bitmap;

	static void WindowEventHandler(Graphics::WindowEvent windowEvent, void* parameter);
};

