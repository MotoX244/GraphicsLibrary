#pragma once

#include <vector>
#include <chrono>
#include "Vector.h"
#include "Object.h"
#include "ObjectPair.h"


namespace Physics2D
{
	constexpr int INFINITE_MASS = 0;

	class Engine
	{
	public:
		Engine(float fps, const Vector& gravity);
		~Engine();
		void SetFPS(float fps);
		void SetGravity(const Vector& gravity);
		void AddObject(Object& object);
		void RemoveObject(Object& object);
		void Update();

	private:
		ObjectPair* FindFirstCollision(float seconds);
		void HandleCollision(ObjectPair& objectPair);

		float _FPS;
		Vector _Gravity;
		std::vector<Object*> _Objects;
		std::vector<ObjectPair*> _ObjectPairs;
		std::chrono::high_resolution_clock::time_point _PreviousTime;
	};
}
