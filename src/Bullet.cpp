#include "Entities.hpp"

void Bullet::Update(GameState& state)
{
	Entity::Update(state);

	if (SECONDS(clock) > 0.05f)
	{
		position = position + direction;
		clock = 0;
	}
	if (position.y < 1)
		to_remove = true;
	
	Entity* other = state.collision_map[position.x][position.y-1];
	if (other == nullptr)
		return;

	if (BaseEnemy *enemy = dynamic_cast<BaseEnemy*>(other))
	{
		enemy->Destroy(state);
		to_remove = true;
	}
}
