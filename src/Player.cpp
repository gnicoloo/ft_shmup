#include "Entities.hpp"

void Player::Shoot(GameState& state)
{
	if (shootCooldown > 0) return;
	shootCooldown = PLAYER_SHOOT_COOLDOWN * 1000000000;
	Vector2 shootPosition = position;
	shootPosition.x += strlen(active_graphics) / 2;
	shootPosition.y -= 1;
	state.spawn_queue.push_back(new Bullet(shootPosition, {0, -1}, Bullet::Target::Enemy));
}

// 260 left
// 261 right
// 259 up
// 258 down
void Player::Update(GameState& state)
{
	Entity::Update(state);
	invincibiltyClock -= state.deltaTime;
	shootCooldown -= state.deltaTime;
	if (shootCooldown < 0)
		shootCooldown = 0;
	switch (state.pressed)
	{
		//case 259: this->position.y -= 1; break;
		//case 258: this->position.y += 1; break;
		case 261: this->position.x += 1; break;
		case 260: this->position.x -= 1; break;
		case ' ': Shoot(state); break;
		default: break;
	}
	if (position.x > WINDOW_WIDTH - (int)strlen(active_graphics) - 1)
		position.x = WINDOW_WIDTH - (int)strlen(active_graphics ) - 1;
	if (position.x < 1)
		position.x = 1;
	
	active_graphics = &frames[10 * (int)(SECONDS(shootCooldown) * 5 / PLAYER_SHOOT_COOLDOWN)];
}