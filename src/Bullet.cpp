#include "Entities.hpp"
#include "Utils.hpp"

void Bullet::Update(GameState& state)
{
	Entity::Update(state);

	if (SECONDS(clock) > 0.05f)
	{
		position = position + direction;
		clock = 0;
	}
	if (!InsideScreen(position))
		to_remove = true;
	
	Vector2 nextPos = position + direction;
	Entity* other = state.collision_map[nextPos.x][nextPos.y];
	if (other == nullptr)
		return;

	if (target == Target::Enemy)
	if (BaseEnemy *enemy = dynamic_cast<BaseEnemy*>(other))
	{
		enemy->Destroy(state);
		to_remove = true;
	}
}
