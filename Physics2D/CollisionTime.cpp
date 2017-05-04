#include <algorithm>
#include "CollisionTime.h"

using namespace std;
using namespace Physics2D;


CollisionTime::CollisionTime(float min1, float center1, float max1, float velocity1, float min2, float center2, float max2, float velocity2)
	: _Entry(0)
	, _Exit(0)
{
	float rate = velocity2 - velocity1;

	if ( rate > 0 )
	{
		float distance;

		distance = max1 - min2;
		_Exit = distance / rate;

		distance = min1 - max2;
		_Entry = distance / rate;
	}
	else if ( rate < 0 )
	{
		float distance;

		distance = max1 - min2;
		_Entry = distance / rate;

		distance = min1 - max2;
		_Exit = distance / rate;
	}
	else
	{
		if ( center1 > center2 )
		{
			if ( min1 < max2 )
			{
				_Entry = -numeric_limits<float>::infinity();
				_Exit = numeric_limits<float>::infinity();
			}
			else
			{
				_Entry = numeric_limits<float>::infinity();
				_Exit = -numeric_limits<float>::infinity();
			}
		}
		else
		{
			if ( max1 > min2 )
			{
				_Entry = -numeric_limits<float>::infinity();
				_Exit = numeric_limits<float>::infinity();
			}
			else
			{
				_Entry = numeric_limits<float>::infinity();
				_Exit = -numeric_limits<float>::infinity();
			}
		}
	}
}


float CollisionTime::Entry()
{
	return _Entry;
}


float CollisionTime::Exit()
{
	return _Exit;
}
