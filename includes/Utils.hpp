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

#endif