#pragma once

#include "Paddle.h"
#include "Ball.h"
#include "Goal.h"
#include "Wall.h"
#include "Physics2D/Engine.h"
#include "Graphics2D/Camera.h"
#include "Graphics2D/Canvas.h"
#include "Graphics2D/Window.h"
#include "Graphics2D/Engine.h"


class Pong
{
public:
	Pong(int width, int height);
	void Run();

private:
	const float _WinningScore = 0.1f;
	const float _BallSize = 0.04f;
	const float _PaddleWidth = 0.02f;
	const float _PaddleHeight = 0.2f;
	const float _PaddlePosition = 0.04f;
	const float _BorderSize = 0.02f;

	void Reset();
	void LeftGoal();
	void RightGoal();

	static void WindowEventHandler(Graphics2D::WindowEvent windowEvent, void* parameter);

	bool _Run;
	int _Width;
	int _Height;
	int _ScoreLeft;
	int _ScoreRight;
	Paddle _PaddleLeft;
	Paddle _PaddleRight;
	Ball _Ball;
	Ball _Ball2;
	Goal _GoalLeft;
	Goal _GoalRight;
	Wall _WallTop;
	Wall _WallBottom;
	Physics2D::Engine _PhysicsEngine;
	Graphics2D::Engine _GraphicsEngine;
	Graphics2D::Camera _Camera;
	Graphics2D::Canvas _Canvas;
	Graphics2D::Window _Window;
};
