#pragma once
#include<math.h>

bool CircleToCircle(Vector2 aPos, float aRadius, Vector2 bPos, float bRadius)
{
	float distance = sqrtf((aPos.x - bPos.x) * (aPos.x - bPos.x) + (aPos.y - bPos.y) * (aPos.y - bPos.y));

	if (aRadius + bRadius >= distance)
	{
		return true;
	}
	else
	{
		return false;
	}
}