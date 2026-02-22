#include "Entities.hpp"
#include "Settings.hpp"
#include "Utils.hpp"

void Particle::Update(GameState& state)
{
	Entity::Update(state);

	active_graphics = &frames[(2*(int)(initial_offset + SECONDS(clock*PARTICLE_SPEED))) % 8];
    precise_position = precise_position + (velocity * SECONDS(state.deltaTime));
    velocity.y += PARTICLE_GRAVITY * SECONDS(state.deltaTime);
    
    position = precise_position;

    if (Player* player = dynamic_cast<Player*>(GetEntityInCollisionMap(state)))
	{
		state.score += RandomBetweenINT(1,3) * (state.HasAugment("Particle Score Augment") ? 2 : 1);
		state.shards_collected++;
		to_remove = true;
	}

    if (!InsideScreen(position))
        to_remove = true;
}