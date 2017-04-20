#include "Canvas.h"
#include "Factory.h"

using namespace Graphics;


Canvas::Canvas(int height, int width)
	: _Implementor(Factory::CreateCanvas(height, width))
{
}


Canvas::~Canvas()
{
	Factory::DestroyCanvas(_Implementor);
}


int Canvas::Height() const
{
	return _Implementor->Height();
}


int Canvas::Width() const
{
	return _Implementor->Width();
}


const char* Canvas::GetBitmap() const
{
	return _Implementor->GetBitmap();
}


void Canvas::SetSize(int height, int width)
{
	_Implementor->SetSize(height, width);
}


void Canvas::Draw(Point& point)
{
	_Implementor->Draw(point);
}


void Canvas::Draw(Line& line)
{
	_Implementor->Draw(line);
}


void Canvas::Draw(Bitmap& bitmap)
{
	_Implementor->Draw(bitmap);
}
