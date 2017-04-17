#include "Factory.h"

using namespace Graphics;


Factory::Factory()
{
}


Factory::~Factory()
{
}


PointImplementor* Factory::CreatePoint()
{
	return nullptr;
}


LineImplementor* Factory::CreateLine()
{
	return nullptr;
}


BitmapImplementor* Factory::CreateBitmap()
{
	return nullptr;
}


void Factory::DestroyPoint(PointImplementor* point)
{
}


void Factory::DestroyLine(LineImplementor* line)
{
}


void Factory::DestroyBitmap(BitmapImplementor* bitmap)
{
}
