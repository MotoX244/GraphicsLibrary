#include "Bitmap.h"
#include "Factory.h"

using namespace std;
using namespace Graphics;


Bitmap::Bitmap()
	: _X(0)
	, _Y(0)
	, _Height(0)
	, _Width(0)
	, _Bits(new vector<char>)
{
}


Bitmap::Bitmap(int x, int y, int height, int width, Color& color)
	: _X(x)
	, _Y(y)
	, _Height(height)
	, _Width(width)
	, _Bits(new vector<char>)
{
	_Bits->resize(_Height * _Width * 4);
	SetBits(color);
}


Bitmap::~Bitmap()
{
	delete _Bits;
}


int Bitmap::X() const
{
	return _X;
}


int Bitmap::Y() const
{
	return _Y;
}


int Bitmap::Height() const
{
	return _Height;
}


int Bitmap::Width() const
{
	return _Width;
}


const char* Bitmap::Bits() const
{
	return _Bits->data();
}


void Bitmap::SetBits(Color& color)
{
	unsigned long colorValue = color.Blue() | (color.Green() << 8) | (color.Red() << 16) | (color.Alpha() << 24);
	unsigned long* pixel = reinterpret_cast<unsigned long*>(_Bits->data());
	unsigned long* end = pixel + (_Bits->size() / 4);

	while ( pixel < end )
	{
		*pixel++ = colorValue;
	}
}


void Bitmap::SetPosition(int x, int y)
{
	_X = x;
	_Y = y;
}


void Bitmap::SetSize(int height, int width)
{
	_Height = height;
	_Width = width;
	_Bits->resize(_Height * _Width * 4);
}
