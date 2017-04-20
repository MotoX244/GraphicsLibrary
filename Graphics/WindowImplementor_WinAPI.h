#pragma once

#include "WindowImplementor.h"
#include <thread>
#include <condition_variable>
#include <Windows.h>


namespace Graphics
{
	class WindowImplementor_WinAPI : public WindowImplementor
	{
	public:
		explicit WindowImplementor_WinAPI(int x, int y, int height, int width);
		~WindowImplementor_WinAPI() override;
		int ClientHeight() const override;
		int ClientWidth() const override;
		void SetPosition(int x, int y) override;
		void SetSize(int height, int width) override;
		void Draw(Canvas& canvas) override;

	private:
		static void ThreadEntry(WindowImplementor_WinAPI* window);
		void Thread();
		void InitializeWindow();
		void DestroyWindow();
		void Paint(HDC hdc);
		static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		std::thread* _Thread;
		std::exception_ptr _Exception;
		std::condition_variable _ThreadRunning;
		int _X;
		int _Y;
		int _WindowHeight;
		int _WindowWidth;
		int _ClientHeight;
		int _ClientWidth;
		HWND _Window;
		std::mutex _Mutex;
		std::vector<char> _Bitmap;

		const wchar_t* const _WindowClassName = L"GraphicsLibraryWindow";
	};
}
