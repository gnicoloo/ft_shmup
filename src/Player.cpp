#include "Entities.hpp"

void Player::Render(WINDOW* win)
{
	mvwprintw(win, this->position.y, this->position.x, "#");
}
// 260 left
// 261 right
// 259 up
// 258 down
void Player::Update(GameState& state)
{
	switch (state.pressed)
	{
		case 259: this->position.y -= 1; break;
		case 258: this->position.y += 1; break;
		case 261: this->position.x += 1; break;
		case 260: this->position.x -= 1; break;
		default: break;
	}
}