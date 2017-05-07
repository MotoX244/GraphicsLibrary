#include "Pong.h"
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
using namespace Graphics2D;
using namespace Physics2D;


Pong::Pong(int width, int height)
	: _Width(width)
	, _Height(height)
	, _ScoreLeft(0)
	, _ScoreRight(0)
	, _Ball(height * _BallSize)
	, _Ball2(height * _BallSize)
	, _PaddleLeft(width * _PaddlePosition, _Height / 2.0f, width * _PaddleWidth, height * _PaddleHeight)
	, _PaddleRight(width - (width * _PaddlePosition), _Height / 2.0f, width * _PaddleWidth, height * _PaddleHeight)
	//, _GoalLeft(0, height * _BorderSize, height * _BorderSize, height - (height * _BorderSize))
	//, _GoalRight(width - (height * _BorderSize), height * _BorderSize, static_cast<float>(width), height - (height * _BorderSize))
	, _GoalLeft(0, 1, static_cast<float>(height-1))
	, _GoalRight(static_cast<float>(width-1), 0, static_cast<float>(height-1))
	//, _WallTop(0, height - (height * _BorderSize), static_cast<float>(width), static_cast<float>(height))
	//, _WallBottom(0, 0, static_cast<float>(width), height * _BorderSize)
	, _WallTop(0, static_cast<float>(width-1), static_cast<float>(height-1))
	, _WallBottom(0, static_cast<float>(width), 0)
	, _Camera(width / 2.0f, height / 2.0f)
	, _Canvas(_Camera, width, height)
	, _Window(0, 0, 900, 700, WindowState::Normal, WindowEventHandler, this)
	, _GraphicsEngine(_Canvas)
	, _PhysicsEngine(60, Vector(0, 0))
{
	_PhysicsEngine.AddObject(_Ball);
	_PhysicsEngine.AddObject(_Ball2);
	_PhysicsEngine.AddObject(_PaddleLeft);
	_PhysicsEngine.AddObject(_PaddleRight);
	_PhysicsEngine.AddObject(_GoalLeft);
	_PhysicsEngine.AddObject(_GoalRight);
	_PhysicsEngine.AddObject(_WallTop);
	_PhysicsEngine.AddObject(_WallBottom);

	_GraphicsEngine.AddObject(_Ball);
	_GraphicsEngine.AddObject(_Ball2);
	_GraphicsEngine.AddObject(_PaddleLeft);
	_GraphicsEngine.AddObject(_PaddleRight);
	_GraphicsEngine.AddObject(_GoalLeft);
	_GraphicsEngine.AddObject(_GoalRight);
	_GraphicsEngine.AddObject(_WallTop);
	_GraphicsEngine.AddObject(_WallBottom);

	Reset();
}


void Pong::Run()
{
	while ( _Run && _ScoreLeft != _WinningScore && _ScoreRight != _WinningScore )
	{
		sleep_for(milliseconds(16));

		_PhysicsEngine.Update();

		_Ball.Reposition();
		_Ball2.Reposition();
		_PaddleLeft.Reposition();
		_PaddleRight.Reposition();

		_Canvas.Clear(Color(0, 0, 0, 255));
		_GraphicsEngine.Render();

		_Window.Draw(_Canvas);
	}
}


void Pong::Reset()
{
	_Ball.SetPosition(_Width / 2.0f, _Height / 2.0f);
	_Ball.SetVelocity(500, 30);
	_Ball2.SetPosition((_Width / 2.0f) + 150, _Height / 2.0f);
	_Ball2.SetVelocity(500, 70);

	//_Ball.SetPosition(200, 359);
	//_Ball.SetVelocity(100, 0);
	//_Ball2.SetPosition(600, 241);
	//_Ball2.SetVelocity(100, 180);

	//_Ball.SetPosition(200, 241);
	//_Ball.SetVelocity(100, 0);
	//_Ball2.SetPosition(600, 359);
	//_Ball2.SetVelocity(100, 180);

	//_Ball.SetPosition(241, 150);
	//_Ball.SetVelocity(100, 90);
	//_Ball2.SetPosition(359, 450);
	//_Ball2.SetVelocity(100, 270);

	//_Ball.SetPosition(241, 450);
	//_Ball.SetVelocity(100, 270);
	//_Ball2.SetPosition(359, 150);
	//_Ball2.SetVelocity(100, 90);

	_PaddleLeft.SetPosition(_Height * 0.4f);
	_PaddleRight.SetPosition(_Height * 0.8f);
}


void Pong::LeftGoal()
{
	_ScoreRight++;
	Reset();
}


void Pong::RightGoal()
{
	_ScoreLeft++;
	Reset();
}


void Pong::WindowEventHandler(WindowEvent windowEvent, void* parameter)
{
	Pong* pong = reinterpret_cast<Pong*>(parameter);

	switch ( windowEvent )
	{
		case WindowEvent::Closed:
			pong->_Run = false;
			break;
	}
}
