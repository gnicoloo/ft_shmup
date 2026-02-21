#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "Entity.hpp"

class Player : public Living
{
	public:
	Player(Vector2 position) : Living(position) {}
	void Render(WINDOW* window) override;
	void Update(GameState& state) override;
};

class BaseEnemy : public Living
{
	public:
	void Render(WINDOW* window) override;
	void Update(GameState& state) override;
}; 

class Bullet : public Entity
{
	private:
	Vector2 direction;
	public:
	explicit Bullet(Vector2 direction);
	void Render(WINDOW* window) override;
	void Update(GameState& state) override;
};
#endif