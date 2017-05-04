#include "CanvasImplementor_Custom.h"
#include <exception>
#include <sstream>
#include <limits>

using namespace std;
using namespace Graphics2D;


class CanvasException final : public exception
{
public:
	CanvasException(const char* message)
	{
		stringstream ss;
		ss << "Canvas: " << message;
		_Message = ss.str();
	}

	const char* what() const override
	{
		return _Message.c_str();
	}

private:
	string _Message;
};


CanvasImplementor_Custom::CanvasImplementor_Custom(int height, int width)
: _Height(height)
, _Width(width)
, _Bits(new vector<char>)
{
	SetSize(height, width);
}


CanvasImplementor_Custom::~CanvasImplementor_Custom()
{
	delete _Bits;
}


int CanvasImplementor_Custom::Height() const
{
	return _Height;
}


int CanvasImplementor_Custom::Width() const
{
	return _Width;
}


const char* CanvasImplementor_Custom::GetBitmap() const
{
	return _Bits->data();
}


void CanvasImplementor_Custom::SetSize(int height, int width)
{
	_Height = height;
	_Width = width;
	_Bits->resize(_Height * _Width * 4);
}


void CanvasImplementor_Custom::Clear(Color& color)
{
	unsigned long colorValue = color.Blue() | (color.Green() << 8) | (color.Red() << 16) | (color.Alpha() << 24);
	unsigned long* pixel = reinterpret_cast<unsigned long*>(_Bits->data());
	unsigned long* end = pixel + (_Bits->size() / 4);

	while ( pixel < end )
	{
		*pixel++ = colorValue;
	}
}


void CanvasImplementor_Custom::Draw(Point& point)
{
	int x = point.X();
	int y = point.Y();
	const Color& color = point.GetColor();
}


void CanvasImplementor_Custom::Draw(Line& line)
{
	unsigned long* pixel = reinterpret_cast<unsigned long*>(_Bits->data());

	const Color& color = line.GetColor();
	unsigned long colorValue = color.Blue() | (color.Green() << 8) | (color.Red() << 16) | (color.Alpha() << 24);

	int x1 = line.X1();
	int y1 = line.Y1();
	int x2 = line.X2();
	int y2 = line.Y2();

	int width = abs(x2 - x1);
	int height = abs(y2 - y1);

	if ( width > height )
	{
		if ( x1 > x2 )
		{
			x1 = line.X2();
			y1 = line.Y2();
			x2 = line.X1();
			y2 = line.Y1();
		}

		if ( y1 > y2 )
		{
			for ( int x = 0; x < width; x++ )
			{
				int y = y1 - ((height * x) / width);

				pixel[(y * _Width) + x1 + x] = colorValue;
			}
		}
		else
		{
			for ( int x = 0; x < width; x++ )
			{
				int y = ((height * x) / width) + y1;

				pixel[(y * _Width) + x1 + x] = colorValue;
			}
		}
	}
	else
	{
		if ( y1 > y2 )
		{
			x1 = line.X2();
			y1 = line.Y2();
			x2 = line.X1();
			y2 = line.Y1();
		}

		if ( x1 > x2 )
		{
			for ( int y = 0; y < height; y++ )
			{
				int x = x1 - ((width * y) / height);

				pixel[((y + y1) * _Width) + x] = colorValue;
			}
		}
		else
		{
			for ( int y = 0; y < height; y++ )
			{
				int x = ((width * y) / height) + x1;

				pixel[((y + y1) * _Width) + x] = colorValue;
			}
		}
	}
}


void CanvasImplementor_Custom::Draw(Bitmap& bitmap)
{
	int x = bitmap.X();
	int y = bitmap.Y();
	int height = bitmap.Height();
	int width = bitmap.Width();
	const char* bits = bitmap.Bits();
}
