#include "Entity.hpp"

Entity::Entity(Vector2 position, char *graphics)
{
	this->position = position;
	this->active_graphics = graphics;
}

void Entity::Update(GameState &state)
{
	//state.collision_map[] ima do this later
}

bool Entity::IsInsideBoundingBox(Vector2 point)
{
	return	point.x > bounding_box.position.x &&
			point.x < (bounding_box.position.x + bounding_box.width) &&
			point.y > bounding_box.position.y &&
			point.y < (bounding_box.position.y + bounding_box.height);
}