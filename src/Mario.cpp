#include "Entities.hpp"

void Mario::Update(GameState& state)
{
	Entity::Update(state);

	if (SECONDS(clock) > 0.05f / MARIO_SPEED)
	{
		clock = 0;
		position.x += direction;
	}
	if (!InsideScreen(position))
		to_remove = true;
}

void Mario::Destroy(GameState& state)
{
	state.isKeyPressed(0);
	state.spawn_queue.push_back(new Star(position));

	int particle_amount = (int)RandomBetween(PARTICLE_AMOUNT - PARTICLE_AMOUNT/2, PARTICLE_AMOUNT + PARTICLE_AMOUNT/2);
	for (int i = 0; i < particle_amount; i++)
	{
		char particle_animation[] = ALT_PARTICLE_ANIMATION;
		state.spawn_queue.push_back(new Particle(position + Vector2{(int)RandomBetween(0,4), (int)RandomBetween(-2,2)}, {RandomBetween(-16,16),RandomBetween(-3,-6)}, particle_animation));
	}

	to_remove = true;
}