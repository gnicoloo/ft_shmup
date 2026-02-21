#ifndef DATA_STRUCTS_HPP
#define DATA_STRUCTS_HPP

#include "Updatable.hpp"

struct Vector2
{
	int x = 0;
	int y = 0;

	Vector2(int x, int y){
		this->x = x;
		this->y = y;
	}

	Vector2() = default;
};

struct Rect
{
	Vector2 position;
	int height;
	int width;
};

#endif