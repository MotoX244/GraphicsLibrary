#pragma once

#include <vector>
#include <thread>
#include <condition_variable>
#include <Windows.h>
#include "WindowImplementor.h"


namespace Graphics2D
{
	class WindowImplementor_WinAPI : public WindowImplementor
	{
	public:
		explicit WindowImplementor_WinAPI(int x, int y, int width, int height, WindowState windowState, WindowEventHandler eventHandler, void* eventParameter);
		~WindowImplementor_WinAPI() override;
		int ClientHeight() const override;
		int ClientWidth() const override;
		WindowState GetState() const override;
		void Draw(const Canvas& canvas) override;

	private:
		void Destroy();
		void ResizeBitmap(int width, int height);
		static void ThreadEntry(WindowImplementor_WinAPI* window);
		void Thread();
		void InitializeWindow();
		void DestroyWindow();
		void Paint();
		void Size(WORD width, WORD height, WPARAM type);
		static LRESULT CALLBACK WindowProcedureEntry(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		LRESULT WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		std::thread* _Thread;
		std::exception_ptr _Exception;
		std::condition_variable _ThreadRunning;
		WindowState _State;
		int _X;
		int _Y;
		int _Width;
		int _Height;
		int _ClientWidth;
		int _ClientHeight;
		int _BitmapWidth;
		int _BitmapHeight;
		BITMAPINFO _BitmapInfo;
		HWND _Window;
		std::mutex _Mutex;
		std::vector<char> _Bitmap;
		WindowEventHandler _EventHandler;
		void* _EventParameter;

		const wchar_t* const _WindowClassName = L"GraphicsLibraryWindow";
	};
}
