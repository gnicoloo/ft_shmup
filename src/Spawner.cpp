#include "Spawners.hpp"
#include "Entities.hpp"
#include "Utils.hpp"

void EnemySpawner::Update(GameState &state)
{
	Entity::Update(state);

	if (SECONDS(clock) > spawnCooldown)
	{
		clock = 0;

		if (RandomBetween(0, 1) > 0.9f)
		{
			if (RandomBetween(0,1) > 0.5f)
				state.spawn_queue.push_back(new Mario({1, WINDOW_HEIGHT/2}, 1));
			else
				state.spawn_queue.push_back(new Mario({WINDOW_WIDTH-1, WINDOW_HEIGHT/2}, -1));
			return;
		}
		state.spawn_queue.push_back(new BaseEnemy({(int)RandomBetween(2, WINDOW_WIDTH-2), 0}));
		spawnCooldown -= 0.05f;
		if (spawnCooldown < 0.3f)
			spawnCooldown = 0.3f;
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