#ifndef DATA_STRUCTS_HPP
#define DATA_STRUCTS_HPP

#include "Library.hpp"

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


struct Entity {
    int x, y;
    int w, h;
    std::vector<std::vector<char> > sprite;
    bool alive;

    Entity(int x_, int y_, std::vector<std::vector<char> > s)
        : x(x_), y(y_), sprite(s), alive(true)
    {
        h = sprite.size();
        w = (h > 0) ? sprite[0].size() : 0;
    }
};

#endif