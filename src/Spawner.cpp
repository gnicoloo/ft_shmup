#include "Spawners.hpp"
#include "Entities.hpp"
#include "Utils.hpp"

void EnemySpawner::Update(GameState &state)
{
	Entity::Update(state);

	if (SECONDS(clock) > INITIAL_SPAWN_TIME)
	{
		clock = 0;
		state.spawn_queue.push_back(new BaseEnemy({(int)RandomBetween(2, WINDOW_WIDTH-2), 0}));
	}
}

void ChestSpawner::Update(GameState &state)
{
	Entity::Update(state);

	if (SECONDS(clock) > CHEST_COOLDOWN)
	{
		clock = 0;
		state.spawn_queue.push_back(new Chest({(int)RandomBetween(2, WINDOW_WIDTH-2), 0}));
	}
}