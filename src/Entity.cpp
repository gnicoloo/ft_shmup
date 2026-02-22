#include "Entity.hpp"
#include "Utils.hpp"

Entity::Entity(Vector2 position, char *graphics)
{
	this->position = position;
	this->active_graphics = graphics;
}

void Entity::Render(WINDOW *window)
{
	if (!this->active_graphics) return;
	char *graphics = this->active_graphics;
	int posy = this->position.y;
	wmove(window, this->position.y, this->position.x);
	while (*graphics)
	{
		if (*graphics == '\n')
			wmove(window, ++posy, this->position.x);
		else
			wprintw(window, "%c", *graphics);
		graphics++;
	}
}

void Entity::Update(GameState &state)
{
	this->clock += state.deltaTime;
}

void Entity::BakeCollisionMap(GameState &state)
{
	if (!this->HasCollisions()) return;
	Vector2 pos = position;
	for (size_t i = 0; i < strlen(active_graphics); i++)
	{
		if (active_graphics[i] == '\n')
		{
			i++;
			pos.y--;
			pos.x = position.x;
		}
		if (InsideScreen(pos))
		state.collision_map[pos.x][pos.y] = this;
		pos.x++;
	}
}

Entity* Entity::GetEntityInCollisionMap(GameState &state)
{
	Vector2 pos = position;
	for (size_t i = 0; i < strlen(active_graphics); i++)
	{
		if (active_graphics[i] == '\n')
		{
			i++;
			pos.y--;
			pos.x = position.x;
		}
		if (InsideScreen(pos) && state.collision_map[pos.x][pos.y] != NULL)
			return state.collision_map[pos.x][pos.y];
		pos.x++;
	}
	return NULL;
}
