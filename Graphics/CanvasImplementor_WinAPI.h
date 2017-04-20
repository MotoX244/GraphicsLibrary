#pragma once

#include "CanvasImplementor.h"
#include <thread>
#include <condition_variable>
#include <Windows.h>


namespace Graphics
{
	class CanvasImplementor_WinAPI : public CanvasImplementor
	{
	public:
		explicit CanvasImplementor_WinAPI(int height, int width);
		~CanvasImplementor_WinAPI() override;
		int Height() const override;
		int Width() const override;
		const char* GetBitmap() const override;
		void SetSize(int height, int width) override;
		void Draw(Point& point) override;
		void Draw(Line& line) override;
		void Draw(Bitmap& bitmap) override;

	private:
		int _Height;
		int _Width;
		HDC _DC;
		HBITMAP _BitmapHandle;
		char* _BitmapData;
	};
}
