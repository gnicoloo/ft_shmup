#include "Entity.hpp"

Entity::Entity(Vector2 position)
{
	this->position = position;
}

bool Entity::IsInsideBoundingBox(Vector2 point)
{
	return	point.x > bounding_box.position.x &&
			point.x < (bounding_box.position.x + bounding_box.width) &&
			point.y > bounding_box.position.y &&
			point.y < (bounding_box.position.y + bounding_box.height);
}