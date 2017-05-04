#pragma once

#include <thread>
#include <condition_variable>
#include <Windows.h>
#include "CanvasImplementor.h"


namespace Graphics2D
{
	class Camera;

	class CanvasImplementor_WinAPI : public CanvasImplementor
	{
	public:
		explicit CanvasImplementor_WinAPI(Camera& camera, int width, int height);
		~CanvasImplementor_WinAPI() override;
		int Width() const override;
		int Height() const override;
		const char* GetBitmap() const override;
		void SetSize(int width, int height) override;
		void Clear(const Color& color) override;
		void Draw(const Line& line) override;
		void Draw(const Circle& circle) override;
		void Draw(const Rectangle& rectangle) override;
		void Draw(const Bitmap& bitmap) override;

	private:
		void Destroy();

		Camera& _Camera;
		int _Width;
		int _Height;
		HDC _DC;
		HBITMAP _BitmapHandle;
		char* _BitmapData;
	};
}
