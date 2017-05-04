#include "Canvas.h"
#include "Color.h"
#include "Object/Line.h"
#include "Object/Circle.h"
#include "Object/Rectangle.h"
#include "Object/Bitmap.h"
#include "Factory.h"
#include "CanvasImplementor.h"

using namespace Graphics2D;


Canvas::Canvas(Camera& camera, int width, int height)
	: _Implementor(Factory::CreateCanvas(camera, width, height))
{
}


Canvas::~Canvas()
{
}


int Canvas::Width() const
{
	return _Implementor->Width();
}


int Canvas::Height() const
{
	return _Implementor->Height();
}


const char* Canvas::GetBitmap() const
{
	return _Implementor->GetBitmap();
}


void Canvas::SetSize(int width, int height)
{
	_Implementor->SetSize(width, height);
}


void Canvas::Clear(const Color& color)
{
	_Implementor->Clear(color);
}


void Canvas::Draw(const Line& line)
{
	_Implementor->Draw(line);
}


void Canvas::Draw(const Circle& circle)
{
	_Implementor->Draw(circle);
}


void Canvas::Draw(const Rectangle& rectangle)
{
	_Implementor->Draw(rectangle);
}


void Canvas::Draw(const Bitmap& bitmap)
{
	_Implementor->Draw(bitmap);
}
