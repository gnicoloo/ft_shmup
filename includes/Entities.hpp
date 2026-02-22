#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "Entity.hpp"
#include <string.h>
#include "Utils.hpp"

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
	public:
	enum class Target {
        Enemy,
        Player
    };

	private:
	Vector2 direction;
	Target target;

	public:
	explicit Bullet(Vector2 position, Vector2 direction, Target target) : Entity(position, target == Target::Enemy ? strdup("|") : strdup("+\n+\n+"))
	{
		this->direction = direction;
		this->target = target;
	}
	void Update(GameState& state) override;
};

class Particle : public Entity
{
	private:
	Vector2f velocity;
	Vector2f precise_position;
	char *frames = NULL;
	float initial_offset;

	protected:
		bool HasCollisions() override {return false;}

	public:
	~Particle()
	{
		active_graphics = NULL;
		free(frames);
	}
	explicit Particle(Vector2 position, Vector2f initial_velocity) : Entity(position, nullptr)
	{
		this->velocity = initial_velocity;
		this->precise_position = position;
		this->frames = (char*)malloc(sizeof(char) * 16);
		memmove(this->frames, PARTICLE_ANIMATION, 16);
		this->active_graphics = frames;
		initial_offset = PARTICLE_RANDOM_OFFSET ? RandomBetween(0, 8) : 0;
	}
	void Update(GameState& state) override;
};

#endif