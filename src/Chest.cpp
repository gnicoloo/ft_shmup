#include "GameState.hpp"
#include "Entities.hpp"

void Chest::Update(GameState& state)
{
	Entity::Update(state);
	if (SECONDS(clock) > 0.05f / CHEST_SPEED)
	{
		position.y += 1;
		clock = 0;
	}
	if (!InsideScreen(position))
	{
		to_remove = true;
		return;
	}
}