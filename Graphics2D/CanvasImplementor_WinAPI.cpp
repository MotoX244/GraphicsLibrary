#include <exception>
#include <sstream>
#include "CanvasImplementor_WinAPI.h"
#include "Camera.h"
#include "Object/Line.h"
#include "Object/Circle.h"
#include "Object/Rectangle.h"
#include "Object/Bitmap.h"

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

	CanvasException(const char* message, DWORD lastError)
	{
		LPSTR lastErrorString = nullptr;
		FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr, lastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lastErrorString, 0, nullptr);

		stringstream ss;
		ss << "Canvas: " << message << " (" << lastErrorString << ")";
		_Message = ss.str();

		LocalFree(lastErrorString);
	}

	const char* what() const override
	{
		return _Message.c_str();
	}

private:
	string _Message;
};


CanvasImplementor_WinAPI::CanvasImplementor_WinAPI(Camera& camera, int width, int height)
	: _Camera(camera)
	, _Width(width)
	, _Height(height)
	, _DC(nullptr)
	, _BitmapHandle(nullptr)
	, _BitmapData(nullptr)
{
	HDC screenDC = nullptr;

	try
	{
		screenDC = GetDC(nullptr);
		if ( !screenDC )
		{
			throw CanvasException("Error getting screen DC.");
		}

		_DC = CreateCompatibleDC(screenDC);
		if ( !_DC )
		{
			throw CanvasException("Error creating DC.");
		}

		ReleaseDC(nullptr, screenDC);

		SetSize(width, height);
	}
	catch (...)
	{
		if ( screenDC )
		{
			ReleaseDC(nullptr, screenDC);
		}
		Destroy();
		throw;
	}
}


CanvasImplementor_WinAPI::~CanvasImplementor_WinAPI()
{
	Destroy();
}


void CanvasImplementor_WinAPI::Destroy()
{
	if ( _BitmapHandle )
	{
		DeleteObject(_BitmapHandle);
		_BitmapHandle = nullptr;
	}

	if ( _DC )
	{
		DeleteDC(_DC);
		_DC = nullptr;
	}
}


int CanvasImplementor_WinAPI::Width() const
{
	return _Width;
}


int CanvasImplementor_WinAPI::Height() const
{
	return _Height;
}


const char* CanvasImplementor_WinAPI::GetBitmap() const
{
	return _BitmapData;
}


void CanvasImplementor_WinAPI::SetSize(int width, int height)
{
	if ( _BitmapHandle )
	{
		DeleteObject(_BitmapHandle);
		_BitmapHandle = nullptr;
	}

	_Width = width;
	_Height = height;

	BITMAPINFO bitmapInfo{};
	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biBitCount = 32;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biHeight = _Height;
	bitmapInfo.bmiHeader.biWidth = _Width;
	bitmapInfo.bmiHeader.biSizeImage = _Width * _Height * bitmapInfo.bmiHeader.biBitCount / 8;

	_BitmapHandle = CreateDIBSection(_DC, &bitmapInfo, DIB_RGB_COLORS, (void**)&_BitmapData, nullptr, 0);
	if ( !_BitmapHandle )
	{
		throw CanvasException("Error creating bitmap.");
	}

	SelectObject(_DC, _BitmapHandle);
}


void CanvasImplementor_WinAPI::Clear(const Color& color)
{
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(color.Red(), color.Green(), color.Blue()));
	HBRUSH brush = CreateSolidBrush(RGB(color.Red(), color.Green(), color.Blue()));
	HPEN oldPen = static_cast<HPEN>(SelectObject(_DC, pen));
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(_DC, brush));

	::Rectangle(_DC, 0, 0, _Width, _Height);

	SelectObject(_DC, oldBrush);
	SelectObject(_DC, oldPen);
	DeleteObject(pen);
	DeleteObject(brush);
}


void CanvasImplementor_WinAPI::Draw(const Line& line)
{
	float leftEdge = _Camera.X() - (_Width / 2);
	float topEdge = _Camera.Y() + (_Height / 2) - 1;
	int x1 = static_cast<int>(leftEdge + line.Point1().X);
	int y1 = static_cast<int>(topEdge - line.Point1().Y);
	int x2 = static_cast<int>(leftEdge + line.Point2().X);
	int y2 = static_cast<int>(topEdge - line.Point2().Y);
	const Color& color = line.GetColor();

	HPEN pen = CreatePen(PS_SOLID, 1, RGB(color.Red(), color.Green(), color.Blue()));
	HPEN oldPen = static_cast<HPEN>(SelectObject(_DC, pen));

	MoveToEx(_DC, x1, y1, nullptr);
	LineTo(_DC, x2, y2);

	SelectObject(_DC, oldPen);
	DeleteObject(pen);
}


void CanvasImplementor_WinAPI::Draw(const Circle& circle)
{
	float leftEdge = _Camera.X() - (_Width / 2);
	float topEdge = _Camera.Y() + (_Height / 2) - 1;
	float radius = circle.Radius();
	int x1 = static_cast<int>(leftEdge + circle.Center().X - radius);
	int y1 = static_cast<int>(topEdge - circle.Center().Y - radius);
	int x2 = static_cast<int>(leftEdge + circle.Center().X + radius);
	int y2 = static_cast<int>(topEdge - circle.Center().Y + radius);
	const Color& color = circle.GetColor();

	HPEN pen = CreatePen(PS_SOLID, 1, RGB(color.Red(), color.Green(), color.Blue()));
	HBRUSH brush = CreateSolidBrush(RGB(color.Red(), color.Green(), color.Blue()));
	HPEN oldPen = static_cast<HPEN>(SelectObject(_DC, pen));
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(_DC, brush));

	Ellipse(_DC, x1, y1, x2, y2);

	SelectObject(_DC, oldBrush);
	SelectObject(_DC, oldPen);
	DeleteObject(pen);
	DeleteObject(brush);
}


void CanvasImplementor_WinAPI::Draw(const Graphics2D::Rectangle& rectangle)
{
	float leftEdge = _Camera.X() - (_Width / 2);
	float topEdge = _Camera.Y() + (_Height / 2) - 1;
	int x1 = static_cast<int>(leftEdge + rectangle.MinX());
	int y1 = static_cast<int>(topEdge - rectangle.MaxY());
	int x2 = static_cast<int>(leftEdge + rectangle.MaxX());
	int y2 = static_cast<int>(topEdge - rectangle.MinY());
	const Color& color = rectangle.GetColor();

	HPEN pen = CreatePen(PS_SOLID, 1, RGB(color.Red(), color.Green(), color.Blue()));
	HBRUSH brush = CreateSolidBrush(RGB(color.Red(), color.Green(), color.Blue()));
	HPEN oldPen = static_cast<HPEN>(SelectObject(_DC, pen));
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(_DC, brush));

	::Rectangle(_DC, x1, y1, x2, y2);

	SelectObject(_DC, oldBrush);
	SelectObject(_DC, oldPen);
	DeleteObject(pen);
	DeleteObject(brush);
}


void CanvasImplementor_WinAPI::Draw(const Bitmap& bitmap)
{
	float leftEdge = _Camera.X() - (_Width / 2);
	float topEdge = _Camera.Y() + (_Height / 2) - 1;
	int x = static_cast<int>(leftEdge + bitmap.X());
	int y = static_cast<int>(topEdge - bitmap.Y());
	int height = bitmap.Height();
	int width = bitmap.Width();
	const char* bits = bitmap.Bits();

	BITMAPINFO bitmapInfo;
	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biBitCount = 32;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biHeight = -height;
	bitmapInfo.bmiHeader.biWidth = width;
	bitmapInfo.bmiHeader.biSizeImage = height * width * 4;

	if ( StretchDIBits(_DC, x, y, width, height, 0, 0, width, height, bits, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY) == 0 )
	{
		throw CanvasException("StretchDIBits error.");
	}
}
