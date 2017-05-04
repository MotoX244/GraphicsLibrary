#pragma once

#include "Object.h"
#include "ObjectPair.h"


namespace Physics2D
{
	class Factory
	{
	public:
		static ObjectPair* CreateObjectPair(Object& object1, Object& object2);
	};
}
