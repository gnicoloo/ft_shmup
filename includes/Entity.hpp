#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Updatable.hpp"
#include "Data_Structs.hpp"
#include "curses.h"

class Entity : public Updatable
{
	protected:
		Vector2 position;
		Rect bounding_box;
	public:
		Entity(Vector2 position);
		void virtual Render(WINDOW* window) = 0;
		bool IsInsideBoundingBox(Vector2 point);
};

class Living : public Entity
{
	private:
	int health;
	
	public:
	Living(Vector2 position) : Entity(position) {}
	bool isDead() {return health <= 0;}
};

#endif