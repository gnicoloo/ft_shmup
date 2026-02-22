#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Updatable.hpp"
#include "Data_Structs.hpp"
#include "curses.h"
#include <string.h>
#include <cstdlib>

#define SECONDS(clock) (clock / 1000000000.0f)

class Entity : public Updatable
{
	protected:
		Vector2 position;
		char *active_graphics;
		long long int clock = 0;
		bool to_remove = false;
		virtual bool HasCollisions() {return true;}
	public:
		virtual ~Entity() { free(active_graphics); }
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
	protected:
	int health;
	
	public:
	Living(Vector2 position, char *graphics) : Entity(position, graphics) {}
	int GetHealth() {return health;}
	bool isDead() {return health <= 0;}
};

class Enemy : public Living
{
	public:
	void virtual Destroy(GameState& state) = 0;
	Enemy(Vector2 position, char *graphics) : Living(position, graphics) {}
};

#endif