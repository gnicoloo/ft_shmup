#include "Entities.hpp"

void Star::Update(GameState& state)
{
	Entity::Update(state);
	if (SECONDS(clock) > 0.05f / STAR_SPEED)
	{
		position.y += 1;
		clock = 0;
	}

	if (Player* player = dynamic_cast<Player*>(GetEntityInCollisionMap(state)))
	{
		state.score += STAR_POINTS;
		state.player->Heal(1);
		to_remove = true;
	}
	if (!InsideScreen(position))
		to_remove = true;
}