#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Updatable.hpp"
#include "Data_Structs.hpp"
#include "curses.h"
#include <string.h>

#define SECONDS(clock) clock / 1000000000.0f

class Entity : public Updatable
{
	protected:
		Vector2 position;
		Rect bounding_box;
		char *active_graphics;
		bool to_remove = false;

	public:
		long long int clock = 0;
		Entity(Vector2 position, char *graphics);
		void virtual Render(WINDOW* window);
		void virtual Update(GameState& state) override;
		void BakeCollisionMap(GameState& state);
		bool IsInsideBoundingBox(Vector2 point);
		bool IsToRemove() {return to_remove;}
		Entity* GetEntityInCollisionMap(GameState &state);
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