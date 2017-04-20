#pragma once

#include "GraphicsLibrary.h"


namespace Graphics
{
	class GRAPHICS_LIBRARY Color
	{
	public:
		Color();
		Color(Color& color);
		Color(int red, int green, int blue, int alpha);
		~Color();
		int Red() const;
		int Green() const;
		int Blue() const;
		int Alpha() const;

	private:
		int _Red;
		int _Green;
		int _Blue;
		int _Alpha;
	};
}
