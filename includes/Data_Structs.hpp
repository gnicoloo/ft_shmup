#ifndef DATA_STRUCTS_HPP
#define DATA_STRUCTS_HPP

struct Vector2
{
	int x = 0;
	int y = 0;

	Vector2(int x, int y){
		this->x = x;
		this->y = y;
	}

	Vector2() = default;

	inline Vector2 operator+(Vector2 other)
	{
		return {x + other.x, y + other.y};
	}  
};

struct Rect
{
	Vector2 position;
	int height;
	int width;
};

#endif