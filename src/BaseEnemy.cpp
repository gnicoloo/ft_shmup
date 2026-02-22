#include "Entities.hpp"
#include "Utils.hpp"

void BaseEnemy::Update(GameState& state)
{
	Entity::Update(state);
	shootCooldown += state.deltaTime;
	if (SECONDS(shootCooldown) > INITIAL_SHOOT_COOLDOWN && RandomBetween(0,1) > 0.5f)
	{
		state.spawn_queue.push_back(new Bullet(position, {0, 1}, Bullet::Target::Player));
		shootCooldown = 0;
	}

	if (SECONDS(clock) > INITIAL_MOVEMENT_COOLDOWN)
	{
		Vector2 delta = {(int)RandomBetween(-3,3), 1};
		if (!state.GetCollisionMap(position + delta))
		{
			position = position + delta;
			ClampScreen(position, this->active_graphics);
		}

		clock = 0;
		if (!InsideScreen(position))
			to_remove = true;
	}
}

void BaseEnemy::Destroy(GameState& state)
{
	to_remove = true;
	state.score += 10;
	int particle_amount = (int)RandomBetween(PARTICLE_AMOUNT - PARTICLE_AMOUNT/2, PARTICLE_AMOUNT + PARTICLE_AMOUNT/2);
	for (int i = 0; i < particle_amount; i++)
	{
		state.spawn_queue.push_back(new Particle(position + Vector2{(int)RandomBetween(0,4), (int)RandomBetween(-2,2)}, {RandomBetween(-16,16),RandomBetween(-3,-6)}));
	}
}
