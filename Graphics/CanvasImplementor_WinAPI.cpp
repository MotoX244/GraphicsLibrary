#include "CanvasImplementor_WinAPI.h"
#include <exception>
#include <sstream>

using namespace std;
using namespace Graphics;


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
		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
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


CanvasImplementor_WinAPI::CanvasImplementor_WinAPI(int height, int width)
: _Height(height)
, _Width(width)
, _DC(nullptr)
, _BitmapHandle(nullptr)
, _BitmapData(nullptr)
{
	HDC screenDC = GetDC(nullptr);
	if ( !screenDC )
	{
		throw CanvasException("Error getting screen DC.");
	}

	_DC = CreateCompatibleDC(screenDC);
	if ( !_DC )
	{
		ReleaseDC(nullptr, screenDC);
		throw CanvasException("Error creating DC.");
	}

	BITMAPINFO bitmapInfo{};
	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biBitCount = 32;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biHeight = _Height;
	bitmapInfo.bmiHeader.biWidth = _Width;
	bitmapInfo.bmiHeader.biSizeImage = _Height * _Width * 4;

	_BitmapHandle = CreateDIBSection(_DC, &bitmapInfo, DIB_RGB_COLORS, (void**)&_BitmapData, nullptr, 0);
	if ( !_BitmapHandle )
	{
		ReleaseDC(nullptr, screenDC);
		throw CanvasException("Error creating bitmap.");
	}

	ReleaseDC(nullptr, screenDC);

	SelectObject(_DC, _BitmapHandle);
}


CanvasImplementor_WinAPI::~CanvasImplementor_WinAPI()
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


int CanvasImplementor_WinAPI::Height() const
{
	return _Height;
}


int CanvasImplementor_WinAPI::Width() const
{
	return _Width;
}


const char* CanvasImplementor_WinAPI::GetBitmap() const
{
	return _BitmapData;
}


void CanvasImplementor_WinAPI::SetSize(int height, int width)
{
}


void CanvasImplementor_WinAPI::Draw(Point& point)
{
	int x = point.X();
	int y = point.Y();
	const Color& color = point.GetColor();

	HPEN pen = CreatePen(PS_SOLID, 6, RGB(color.Red(), color.Green(), color.Blue()));
	HPEN oldPen = (HPEN)SelectObject(_DC, pen);

	MoveToEx(_DC, x, y, nullptr);
	LineTo(_DC, x, y);

	SelectObject(_DC, oldPen);
	DeleteObject(pen);
}


void CanvasImplementor_WinAPI::Draw(Line& line)
{
	int x1 = line.X1();
	int y1 = line.Y1();
	int x2 = line.X2();
	int y2 = line.Y2();
	const Color& color = line.GetColor();

	HPEN pen = CreatePen(PS_SOLID, 6, RGB(color.Red(), color.Green(), color.Blue()));
	HPEN oldPen = (HPEN)SelectObject(_DC, pen);

	MoveToEx(_DC, x1, y1, nullptr);
	LineTo(_DC, x2, y2);

	SelectObject(_DC, oldPen);
	DeleteObject(pen);
}


void CanvasImplementor_WinAPI::Draw(Bitmap& bitmap)
{
	int x = bitmap.X();
	int y = bitmap.Y();
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
		printf("StretchDIBits error\n");
	}
}
