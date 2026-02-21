#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "Entity.hpp"
#include <string.h>

class Player : public Living
{
	private:
	void Shoot(GameState& state);

	public:
	Player(Vector2 position) : Living(position, strdup(")--[^]--(")) {}
	void Update(GameState& state) override;
};

class BaseEnemy : public Living
{
	public:
	BaseEnemy(Vector2 position) : Living(position, strdup(" _\n/O\\\n^ ^")) {}
	void Update(GameState& state) override;
	void Destroy(GameState& state);
}; 

class Bullet : public Entity
{
	private:
	Vector2 direction;

	public:
	explicit Bullet(Vector2 position, Vector2 direction) : Entity(position, strdup("|"))
	{
		this->direction = direction;
	}
	void Update(GameState& state) override;
};
#endif