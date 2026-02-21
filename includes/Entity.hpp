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
		char *active_graphics;

	public:
		Entity(Vector2 position, char *graphics);
		void virtual Render(WINDOW* window) = 0;
		void Update(GameState& state) override;
		bool IsInsideBoundingBox(Vector2 point);
};

class Living : public Entity
{
	private:
	int health;
	
	public:
	Living(Vector2 position, char *graphics) : Entity(position, graphics) {}
	bool isDead() {return health <= 0;}
};

#endif