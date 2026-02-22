#include "Entities.hpp"
#include "Utils.hpp"
#include "Settings.hpp"

void Bullet::Update(GameState& state)
{
	Entity::Update(state);

	float speed = target == Target::Enemy ? PLAYER_BULLET_SPEED : ENEMY_BULLET_SPEED; 
	if (SECONDS(clock) > (0.05f / speed))
	{
		position = position + direction;
		clock = 0;
	}
	if (!InsideScreen(position))
	{
		to_remove = true;
		return;
	}
	
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

	if (target == Target::Player)
	if (Player *player = dynamic_cast<Player*>(other))
		player->Damage(1);
	
}
