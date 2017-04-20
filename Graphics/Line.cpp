#include "Line.h"

using namespace Graphics;


Line::Line()
	: _X1(0)
	, _Y1(0)
	, _X2(0)
	, _Y2(0)
{
}


Line::Line(int x1, int y1, int x2, int y2, Color& color)
	: _X1(x1)
	, _Y1(y1)
	, _X2(x2)
	, _Y2(y2)
	, _Color(color)
{
}


Line::~Line()
{
}


int Line::X1() const
{
	return _X1;
}


int Line::Y1() const
{
	return _Y1;
}

int Line::X2() const
{
	return _X2;
}


int Line::Y2() const
{
	return _Y2;
}


const Color& Line::GetColor() const
{
	return _Color;
}


void Line::SetPosition(int x1, int y1, int x2, int y2)
{
	_X1 = x1;
	_X2 = x2;
	_Y1 = y1;
	_Y2 = y2;
}
