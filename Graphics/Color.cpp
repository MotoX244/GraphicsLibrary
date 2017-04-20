#include "Color.h"

using namespace Graphics;


Color::Color()
	: _Red(0)
	, _Green(0)
	, _Blue(0)
	, _Alpha(255)
{
}


Color::Color(Color& color)
	: _Red(color._Red)
	, _Green(color._Green)
	, _Blue(color._Blue)
	, _Alpha(color._Alpha)
{
}


Color::Color(int red, int green, int blue, int alpha)
	: _Red(red)
	, _Green(green)
	, _Blue(blue)
	, _Alpha(alpha)
{
}


Color::~Color()
{
}


int Color::Red() const
{
	return _Red;
}


int Color::Green() const
{
	return _Green;
}


int Color::Blue() const
{
	return _Blue;
}


int Color::Alpha() const
{
	return _Alpha;
}
