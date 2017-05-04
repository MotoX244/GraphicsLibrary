#pragma once

#include "CanvasImplementor.h"
#include <thread>
#include <condition_variable>
#include <Windows.h>


namespace Graphics2D
{
	class CanvasImplementor_Custom : public CanvasImplementor
	{
	public:
		explicit CanvasImplementor_Custom(int height, int width);
		~CanvasImplementor_Custom() override;
		int Height() const override;
		int Width() const override;
		const char* GetBitmap() const override;
		void SetSize(int height, int width) override;
		void Clear(Color& color) override;
		void Draw(Point& point) override;
		void Draw(Line& line) override;
		void Draw(Bitmap& bitmap) override;

	private:
		int _Height;
		int _Width;
		std::vector<char>* _Bits;
	};
}
