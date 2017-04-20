#include "WindowImplementor_WinAPI.h"
#include <exception>
#include <iostream>
#include <chrono>
#include <sstream>

using namespace std;
using namespace std::chrono;
using namespace Graphics;


class WindowException final : public exception
{
public:
	WindowException(const char* message)
	{
		stringstream ss;
		ss << "Window: " << message;
		_Message = ss.str();
	}

	WindowException(const char* message, DWORD lastError)
	{
		LPSTR lastErrorString = nullptr;
		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr, lastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lastErrorString, 0, nullptr);

		stringstream ss;
		ss << "Window: " << message << " (" << lastErrorString << ")";
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


WindowImplementor_WinAPI::WindowImplementor_WinAPI(int x, int y, int height, int width)
: _Thread(nullptr)
, _Exception(nullptr)
, _X(x)
, _Y(y)
, _WindowHeight(height)
, _WindowWidth(width)
, _ClientHeight(0)
, _ClientWidth(0)
, _Window(nullptr)
{
	_Thread = new thread(ThreadEntry, this);

	mutex m;
	unique_lock<mutex> lock(m);
	auto timeout = system_clock::now() + seconds(1);
	if ( _ThreadRunning.wait_until(lock, timeout) == cv_status::timeout )
	{
		if ( _Exception )
		{
			rethrow_exception(_Exception);
		}

		throw WindowException("Error creating thread running event.");
	}
}


WindowImplementor_WinAPI::~WindowImplementor_WinAPI()
{
	if ( _Thread )
	{
		if ( _Thread->joinable() )
		{
			if ( _Window )
			{
				PostMessage(_Window, WM_QUIT, 0, 0);
			}
			_Thread->join();
		}

		delete _Thread;
		_Thread = nullptr;
	}
}


void WindowImplementor_WinAPI::ThreadEntry(WindowImplementor_WinAPI* window)
{
	window->Thread();
}


void WindowImplementor_WinAPI::Thread()
{
	try
	{
		InitializeWindow();

		_ThreadRunning.notify_all();

		MSG msg{};
		while ( GetMessage(&msg, nullptr, 0, 0) )
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	catch (...)
	{
		_Exception = current_exception();
		DestroyWindow();
		return;
	}

	DestroyWindow();
}


void WindowImplementor_WinAPI::InitializeWindow()
{
	HINSTANCE instance = GetModuleHandle(nullptr);

	WNDCLASS windowClass = {};
	windowClass.style = CS_PARENTDC;
	windowClass.lpfnWndProc = WindowProcedure;
	windowClass.hInstance = instance;
	windowClass.lpszClassName = _WindowClassName;

	if ( !RegisterClass(&windowClass) )
	{
		throw WindowException("Error registering window class.");
	}

	_Window = CreateWindowEx(0, _WindowClassName, nullptr, WS_OVERLAPPEDWINDOW | WS_VISIBLE, _X, _Y, _WindowWidth, _WindowHeight, nullptr, nullptr, instance, nullptr);
	if ( !_Window )
	{
		throw WindowException("Error creating window.");
	}

	SetLastError(0);
	if ( SetWindowLongPtr(_Window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this)) == 0 )
	{
		if ( GetLastError() != 0 )
		{
			throw WindowException("Error setting window user data.");
		}
	}

	RECT rect;
	if ( !GetClientRect(_Window, &rect) )
	{
		throw WindowException("Error getting client rectangle.");
	}

	_ClientWidth = rect.right - rect.left;
	_ClientHeight = rect.bottom - rect.top;

	_Bitmap.resize(_ClientWidth * _ClientHeight * 4);
}


void WindowImplementor_WinAPI::DestroyWindow()
{
	if ( _Window )
	{
		::DestroyWindow(_Window);
		_Window = nullptr;
	}

	if ( !UnregisterClass(_WindowClassName, GetModuleHandle(nullptr)) && GetLastError() != ERROR_CLASS_DOES_NOT_EXIST )
	{
		printf("Error unregistering window class\n");
	}
}


LRESULT CALLBACK WindowImplementor_WinAPI::WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
	{
		case WM_PAINT:
		{
			WindowImplementor_WinAPI* window = reinterpret_cast<WindowImplementor_WinAPI*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
			if ( window )
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				window->Paint(hdc);
				EndPaint(hWnd, &ps);
			}
			return 0;
		}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}


void WindowImplementor_WinAPI::Paint(HDC hdc)
{	
	_Mutex.lock();

	BITMAPINFO bitmapInfo;
	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biBitCount = 32;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biHeight = -_ClientHeight;
	bitmapInfo.bmiHeader.biWidth = _ClientWidth;
	bitmapInfo.bmiHeader.biSizeImage = _ClientHeight * _ClientWidth * 4;

	if ( StretchDIBits(hdc, 0, 0, _ClientWidth, _ClientHeight, 0, 0, _ClientWidth, _ClientHeight, _Bitmap.data(), &bitmapInfo, DIB_RGB_COLORS, SRCCOPY) == 0 )
	{
		printf("StretchDIBits error\n");
	}

	_Mutex.unlock();
}


int WindowImplementor_WinAPI::ClientHeight() const
{
	return _ClientHeight;
}


int WindowImplementor_WinAPI::ClientWidth() const
{
	return _ClientWidth;
}


void WindowImplementor_WinAPI::SetPosition(int x, int y)
{
}


void WindowImplementor_WinAPI::SetSize(int height, int width)
{
}


void WindowImplementor_WinAPI::Draw(Canvas& canvas)
{
	_Mutex.lock();

	int height = canvas.Height();
	int width = canvas.Width();
	const char* bitmap = canvas.GetBitmap();

	if ( height * width * 4 > _Bitmap.size() )
	{
		_Bitmap.resize(height * width * 4);
	}

	memcpy(_Bitmap.data(), bitmap, _Bitmap.size());

	_Mutex.unlock();

	InvalidateRect(_Window, nullptr, FALSE);
}
