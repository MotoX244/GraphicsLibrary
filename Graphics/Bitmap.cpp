#include "Bitmap.h"

using namespace Graphics;


Bitmap::Bitmap()
	: _Bits(nullptr)
{
}


Bitmap::~Bitmap()
{
	delete [] _Bits;
}


void Bitmap::SetSize(int x, int y)
{
	delete _Bits;
	_Bits = new char[x*y];
}


void Bitmap::Draw(Bitmap& bitmap)
{
}
