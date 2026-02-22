#include "Entities.hpp"
#include "Utils.hpp"

void BaseEnemy::Update(GameState& state)
{
	Entity::Update(state);

	if (SECONDS(clock) > 1.5f)
	{
		position.x += (int)RandomBetween(-3,3);
		position.y += 1;
		clock = 0;
		if (RandomBetween(0,1) > 0.5f)
			state.spawn_queue.push_back(new Bullet(position, {0, 1}, Bullet::Target::Player));
	}
}

void BaseEnemy::Destroy(GameState& state)
{
	to_remove = true;
	state.score += 10;
	int particle_amount = (int)RandomBetween(PARTICLE_AMOUNT - PARTICLE_AMOUNT/2, PARTICLE_AMOUNT + PARTICLE_AMOUNT/2);
	for (size_t i = 0; i < particle_amount; i++)
	{
		state.spawn_queue.push_back(new Particle(position + Vector2{(int)RandomBetween(-2,2), (int)RandomBetween(-2,2)}, {RandomBetween(-16,16),RandomBetween(-3,-6)}));
	}
}
