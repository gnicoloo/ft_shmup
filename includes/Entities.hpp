#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "Entity.hpp"
#include <string.h>
#include "Utils.hpp"

class Player : public Living
{
	private:
	long long invincibiltyClock = 0;
	long long shootCooldown = 0;
	char *frames;
	void Shoot(GameState& state);

	public:
	~Player()
	{
		active_graphics = NULL;
		free(frames);
	}
	Player(Vector2 position) : Living(position, nullptr) 
	{
		this->health = 3;

		this->frames = (char*)malloc(sizeof(char) * 50);
		memmove(this->frames, PLAYER_ANIMATION, 50);
		this->active_graphics = frames;
	}
	void Update(GameState& state) override;
	void Damage(int amount)
	{
		 if (invincibiltyClock < 0) 
		 {
			health-=amount;
			invincibiltyClock= (long long)(PLAYER_INVINCIBILITY_SECONDS * 1000000000);
		}
	}
};

class BaseEnemy : public Living
{
	private:
	long long shootCooldown = 0;
	public:
	BaseEnemy(Vector2 position) : Living(position, strdup(BASE_ENEMY_SPRITE)) {this->health = 3; shootCooldown = RandomBetween(0,INITIAL_SHOOT_COOLDOWN);}
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
	
	protected:
		bool HasCollisions() override {return false;}

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

class Chest : public Entity
{
	private:

	protected:
		bool HasCollisions() override {return false;}

	public:
	explicit Chest(Vector2 position) : Entity(position, strdup(CHEST_SPRITE)) {}
	void Update(GameState& state) override;
};

#endif