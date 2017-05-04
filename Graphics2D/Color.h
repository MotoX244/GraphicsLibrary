#pragma once


namespace Graphics2D
{
	class Color
	{
	public:
		Color();
		Color(const Color& color);
		Color(int red, int green, int blue, int alpha);
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
