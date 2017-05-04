#include "Bitmap.h"
#include "../Color.h"

using namespace std;
using namespace Graphics2D;


Bitmap::Bitmap(Point& center, int width, int height, const Color& color)
	: _X(0)
	, _Y(0)
	, _Center(center)
	, _Width(width)
	, _Height(height)
	, _Bits(new vector<char>)
{
	_Bits->resize(_Width * _Height * 4);
	SetBits(color);
}


Bitmap::Bitmap(float x, float y, int width, int height, const Color& color)
	: _X(x)
	, _Y(y)
	, _Width(width)
	, _Height(height)
	, _Bits(new vector<char>)
{
	_Bits->resize(_Width * _Height * 4);
	SetBits(color);
}


float Bitmap::X() const
{
	return _X;
}


float Bitmap::Y() const
{
	return _Y;
}


int Bitmap::Width() const
{
	return _Width;
}


int Bitmap::Height() const
{
	return _Height;
}


const char* Bitmap::Bits() const
{
	return _Bits->data();
}


void Bitmap::SetBits(const Color& color)
{
	unsigned long colorValue = color.Blue() | (color.Green() << 8) | (color.Red() << 16) | (color.Alpha() << 24);
	unsigned long* pixel = reinterpret_cast<unsigned long*>(_Bits->data());
	unsigned long* end = pixel + (_Bits->size() / 4);

	while ( pixel < end )
	{
		*pixel++ = colorValue;
	}
}


void Bitmap::SetPosition(float x, float y)
{
	_X = x;
	_Y = y;
}


void Bitmap::SetSize(int width, int height)
{
	_Width = width;
	_Height = height;
	_Bits->resize(_Width * _Height * 4);
}
