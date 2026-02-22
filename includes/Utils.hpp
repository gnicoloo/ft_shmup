#ifndef UTILS_HPP
#define UTILS_HPP

#include "Data_Structs.hpp"
#include "Settings.hpp"
#include <cstdlib>

inline bool InsideScreen(Vector2 point)
{
    return point.x < WINDOW_WIDTH && point.x >= 0 && point.y < WINDOW_HEIGHT && point.y >= 0;
}

inline float RandomBetween(float min, float max)
{
    return min + ((rand() % 100) / 100.0f) * (max - min); 
}

inline void ClampScreen(Vector2& pos, char *graphics)
{
	if (pos.x > WINDOW_WIDTH - (int)strlen(graphics) - 1)
		pos.x = WINDOW_WIDTH - (int)strlen(graphics ) - 1;
	if (pos.x < 1)
		pos.x = 1;
    if (pos.y > WINDOW_HEIGHT)
		pos.y = WINDOW_HEIGHT;
	if (pos.y < 1)
		pos.y = 1;
}

#endif