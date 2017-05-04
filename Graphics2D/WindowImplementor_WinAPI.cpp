#include <exception>
#include <chrono>
#include <sstream>
#include "WindowImplementor_WinAPI.h"
#include "Canvas.h"

using namespace std;
using namespace std::chrono;
using namespace Graphics2D;


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
		FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
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


WindowImplementor_WinAPI::WindowImplementor_WinAPI(int x, int y, int width, int height, WindowState state, WindowEventHandler eventHandler, void* eventParameter)
: _Thread(nullptr)
, _Exception(nullptr)
, _X(x)
, _Y(y)
, _Width(width)
, _Height(height)
, _ClientWidth(0)
, _ClientHeight(0)
, _BitmapWidth(0)
, _BitmapHeight(0)
, _BitmapInfo{}
, _Window(nullptr)
, _State(state)
, _EventHandler(eventHandler)
, _EventParameter(eventParameter)
{
	try
	{
		ResizeBitmap(100, 100);

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
	catch (...)
	{
		Destroy();
		throw;
	}
}


WindowImplementor_WinAPI::~WindowImplementor_WinAPI()
{
	Destroy();
}


void WindowImplementor_WinAPI::Destroy()
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


void WindowImplementor_WinAPI::ResizeBitmap(int width, int height)
{
	_BitmapWidth = width;
	_BitmapHeight = height;

	_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	_BitmapInfo.bmiHeader.biPlanes = 1;
	_BitmapInfo.bmiHeader.biBitCount = 32;
	_BitmapInfo.bmiHeader.biCompression = BI_RGB;
	_BitmapInfo.bmiHeader.biHeight = _BitmapHeight;
	_BitmapInfo.bmiHeader.biWidth = _BitmapWidth;
	_BitmapInfo.bmiHeader.biSizeImage = _BitmapWidth * _BitmapHeight * _BitmapInfo.bmiHeader.biBitCount / 8;

	_Bitmap.resize(_BitmapInfo.bmiHeader.biSizeImage);
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

	if ( _EventHandler )
	{
		_EventHandler(WindowEvent::Closed, _EventParameter);
	}
}


void WindowImplementor_WinAPI::InitializeWindow()
{
	HINSTANCE instance = GetModuleHandle(nullptr);

	WNDCLASS windowClass = {};
	windowClass.style = CS_PARENTDC;
	windowClass.hInstance = instance;
	windowClass.lpfnWndProc = WindowProcedureEntry;
	windowClass.lpszClassName = _WindowClassName;
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);

	if ( !RegisterClass(&windowClass) )
	{
		throw WindowException("Error registering window class.");
	}

	DWORD style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	switch ( _State )
	{
		case WindowState::Minimized:	style |= WS_MINIMIZE;	break;
		case WindowState::Maximized:	style |= WS_MAXIMIZE;	break;
	}

	_Window = CreateWindowEx(0, _WindowClassName, nullptr, style, _X, _Y, _Width, _Height, nullptr, nullptr, instance, this);
	if ( !_Window )
	{
		throw WindowException("Error creating window.");
	}
}


void WindowImplementor_WinAPI::DestroyWindow()
{
	if ( _Window )
	{
		::DestroyWindow(_Window);
		_Window = nullptr;
	}

	UnregisterClass(_WindowClassName, GetModuleHandle(nullptr));
}


LRESULT CALLBACK WindowImplementor_WinAPI::WindowProcedureEntry(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	WindowImplementor_WinAPI* windowImplementor = nullptr;

	if ( message == WM_CREATE )
	{
		CREATESTRUCT* createStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
		windowImplementor = reinterpret_cast<WindowImplementor_WinAPI*>(createStruct->lpCreateParams);

		SetLastError(0);
		if ( SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(windowImplementor)) == 0 )
		{
			if ( GetLastError() != 0 )
			{
				throw WindowException("Error setting window user data.");
			}
		}
	}
	else
	{
		windowImplementor = reinterpret_cast<WindowImplementor_WinAPI*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}

	return windowImplementor->WindowProcedure(hWnd, message, wParam, lParam);
}


LRESULT WindowImplementor_WinAPI::WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
	{
		case WM_SIZE:
			Size(LOWORD(lParam), HIWORD(lParam), wParam);
			return 0;

		case WM_PAINT:
			Paint();
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
}


void WindowImplementor_WinAPI::Paint()
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(_Window, &ps);

	_Mutex.lock();

	if ( StretchDIBits(hdc, 0, 0, _ClientWidth, _ClientHeight, 0, 0, _BitmapWidth, _BitmapHeight, _Bitmap.data(), &_BitmapInfo, DIB_RGB_COLORS, SRCCOPY) == 0 )
	{
		throw WindowException("StretchDIBits error.");
	}

	_Mutex.unlock();

	EndPaint(_Window, &ps);
}


void WindowImplementor_WinAPI::Size(WORD width, WORD height, WPARAM type)
{
	_ClientWidth = width;
	_ClientHeight = height;
	
	switch ( type )
	{
		case SIZE_MAXHIDE:		_State = WindowState::Normal;		break;
		case SIZE_MAXIMIZED:	_State = WindowState::Maximized;	break;
		case SIZE_MAXSHOW:		_State = WindowState::Normal;		break;
		case SIZE_MINIMIZED:	_State = WindowState::Minimized;	break;
		case SIZE_RESTORED:		_State = WindowState::Normal;		break;
	}

	if ( _EventHandler )
	{
		_EventHandler(WindowEvent::Resized, _EventParameter);
	}

	InvalidateRect(_Window, nullptr, FALSE);
}


int WindowImplementor_WinAPI::ClientWidth() const
{
	return _ClientWidth;
}


int WindowImplementor_WinAPI::ClientHeight() const
{
	return _ClientHeight;
}

WindowState WindowImplementor_WinAPI::GetState() const
{
	return _State;
}

void WindowImplementor_WinAPI::Draw(const Canvas& canvas)
{
	_Mutex.lock();

	if ( _BitmapWidth != canvas.Width() || _BitmapHeight != canvas.Height() )
	{
		ResizeBitmap(canvas.Width(), canvas.Height());
	}

	memcpy(_Bitmap.data(), canvas.GetBitmap(), _Bitmap.size());

	_Mutex.unlock();

	InvalidateRect(_Window, nullptr, FALSE);
}
