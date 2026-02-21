#include "Entities.hpp"

void BaseEnemy::Render(WINDOW *win)
{
	mvwprintw(win, this->position.y, this->position.x, "{}");
}

void BaseEnemy::Update(GameState& state)
{

}