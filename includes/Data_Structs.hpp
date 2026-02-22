#ifndef DATA_STRUCTS_HPP
#define DATA_STRUCTS_HPP

struct Vector2f; 

struct Vector2
{
    int x = 0;
    int y = 0;

    Vector2(int x, int y) : x(x), y(y) {}
    Vector2() = default;

    inline Vector2 operator+(Vector2 other) {
        return {x + other.x, y + other.y};
    }

    Vector2& operator=(const Vector2f& other); 
};

struct Vector2f
{
    float x = 0;
    float y = 0;

    Vector2f(float x, float y) : x(x), y(y) {}
    Vector2f() = default;

    inline Vector2f operator+(Vector2f other) {
        return {x + other.x, y + other.y};
    }

	inline Vector2f operator*(float other) {
        return {x * other, y * other};
    }

    inline Vector2f& operator=(const Vector2& other) {
        this->x = (float)other.x;
        this->y = (float)other.y;
        return *this;
    }
};

inline Vector2& Vector2::operator=(const Vector2f& other)
{
    this->x = (int)other.x;
    this->y = (int)other.y;
    return *this;
}

struct Rect
{
	Vector2 position;
	int height;
	int width;
};

#endif