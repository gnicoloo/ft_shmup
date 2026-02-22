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
	if (Player* player = dynamic_cast<Player*>(GetEntityInCollisionMap(state)))
	{
		to_remove = true;
		state.chests++;
		if (state.augments_left.size() == 0)
		{
			state.score += 20;
			return;
		}
		int index = RandomBetweenINT(0, state.augments_left.size() - 1);
		auto it = std::next(state.augments_left.begin(), index);
		state.augments.push_back(*it);
		state.augments_left.erase(it);
	}
}