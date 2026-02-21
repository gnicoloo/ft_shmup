#include "Entities.hpp"

void BaseEnemy::Update(GameState& state)
{

}

void BaseEnemy::Destroy(GameState& state)
{
	to_remove = true;
}
