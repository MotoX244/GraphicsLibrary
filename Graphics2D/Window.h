#pragma once

#include <memory>


namespace Graphics2D
{
	class Canvas;
	class WindowImplementor;

	enum class WindowState
	{
		Normal
	,	Minimized
	,	Maximized
	};

	enum class WindowEvent
	{
		Resized
	,	Closed
	};

	typedef void(*WindowEventHandler)(WindowEvent windowEvent, void* parameter);

	class Window
	{
	public:
		explicit Window(int x, int y, int width, int height, WindowState state, WindowEventHandler eventHandler, void* eventParameter);
		~Window();
		int ClientWidth() const;
		int ClientHeight() const;
		WindowState GetState() const;
		void Draw(const Canvas& canvas);

	private:
		std::unique_ptr<WindowImplementor> _Implementor;
	};
}
