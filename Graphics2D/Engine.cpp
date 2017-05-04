#include "Engine.h"
#include "Object/Line.h"
#include "Object/Circle.h"
#include "Object/Rectangle.h"
#include "Object/Bitmap.h"
#include "Canvas.h"

using namespace std;
using namespace Graphics2D;


Engine::Engine(Canvas& canvas)
	: _Canvas(canvas)
	, _Lines(new vector<Line*>)
	, _Circles(new vector<Circle*>)
	, _Rectangles(new vector<Rectangle*>)
	, _Bitmaps(new vector<Bitmap*>)
{
}


void Engine::AddObject(Line& line)
{
	_Lines->push_back(&line);
}


void Engine::AddObject(Circle& circle)
{
	_Circles->push_back(&circle);
}


void Engine::AddObject(Rectangle& rectangle)
{
	_Rectangles->push_back(&rectangle);
}


void Engine::AddObject(Bitmap& bitmap)
{
	_Bitmaps->push_back(&bitmap);
}


void Engine::RemoveObject(Line& line)
{
	for ( auto existingLine = _Lines->begin(); existingLine != _Lines->end(); existingLine++ )
	{
		if ( *existingLine == &line )
		{
			_Lines->erase(existingLine);
			break;
		}
	}
}


void Engine::RemoveObject(Circle& circle)
{
	for ( auto existingCircle = _Circles->begin(); existingCircle != _Circles->end(); existingCircle++ )
	{
		if ( *existingCircle == &circle )
		{
			_Circles->erase(existingCircle);
			break;
		}
	}
}


void Engine::RemoveObject(Rectangle& rectangle)
{
	for ( auto existingRectangle = _Rectangles->begin(); existingRectangle != _Rectangles->end(); existingRectangle++ )
	{
		if ( *existingRectangle == &rectangle )
		{
			_Rectangles->erase(existingRectangle);
			break;
		}
	}
}


void Engine::RemoveObject(Bitmap& bitmap)
{
	for ( auto existingBitmap = _Bitmaps->begin(); existingBitmap != _Bitmaps->end(); existingBitmap++ )
	{
		if ( *existingBitmap == &bitmap )
		{
			_Bitmaps->erase(existingBitmap);
			break;
		}
	}
}


void Engine::Render()
{
	for ( auto line : *_Lines )
	{
		_Canvas.Draw(*line);
	}

	for ( auto circle : *_Circles )
	{
		_Canvas.Draw(*circle);
	}

	for ( auto rectangle : *_Rectangles )
	{
		_Canvas.Draw(*rectangle);
	}

	for ( auto bitmap : *_Bitmaps )
	{
		_Canvas.Draw(*bitmap);
	}
}
