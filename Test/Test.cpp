#include "Test.h"
#include <chrono>
#include <thread>

using namespace Graphics;
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;


Test::Test()
	: _Run(true)
	, _Resize(false)
	,_Window(0, 0, 1000, 1000, WindowState::Normal, WindowEventHandler, this)
	, _Canvas(200, 200)
	, _Point(10, 20, Color(255, 0, 0, 255))
	, _Line(30, 40, 87, 91, Color(0, 255, 0, 255))
	, _Bitmap(100, 110, 163, 199, Color(0, 0, 255, 255))
{
}


void Test::Run()
{
	int x = 0;
	int y = 0;
	int state = 0;

	while ( _Run )
	{
		sleep_for(milliseconds(16));

		if ( _Resize )
		{
			_Resize = false;
			if ( _Window.GetState() != WindowState::Minimized )
			{
				_Canvas.SetSize(_Window.ClientHeight(), _Window.ClientWidth());
			}
		}

		if ( _Window.GetState() == WindowState::Minimized )
		{
			continue;
		}

		switch ( state )
		{
			case 0:
				x++;
				if ( x == 200 )
				{
					state = 1;
				}
				break;
			case 1:
				y++;
				if ( y == 200 )
				{
					state = 2;
				}
				break;
			case 2:
				x--;
				if ( x == 0 )
				{
					state = 3;
				}
				break;
			case 3:
				y--;
				if ( y == 0 )
				{
					state = 0;
				}
				break;
		}

		_Line.SetPosition(x, y, 100, 100);

		_Canvas.Clear(Color(0, 0, 0, 255));
		_Canvas.Draw(_Point);
		_Canvas.Draw(_Line);
		_Canvas.Draw(_Bitmap);

		_Window.Draw(_Canvas);
	}
}


void Test::WindowEventHandler(WindowEvent windowEvent, void* parameter)
{
	Test* test = reinterpret_cast<Test*>(parameter);

	switch ( windowEvent )
	{
		case WindowEvent::Closed:
			test->_Run = false;
			break;

		case WindowEvent::Resized:
			test->_Resize = true;
			break;
	}
}
