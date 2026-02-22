#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>
#include "Settings.hpp"
#include "Data_Structs.hpp"

class Entity;
class Player;

struct GameState
{
	long long int startTime;
	long long int time;
	long long int deltaTime;
	int score;
	int level;
	int pressed;
	Player* player;
	std::list<Entity*> entities;
	std::list<Entity*> spawn_queue;
	Entity* collision_map[WINDOW_WIDTH][WINDOW_HEIGHT] = {};

	bool isKeyPressed(int key){return pressed==key;}
	Entity *GetCollisionMap(Vector2 pos)
	{
		return collision_map[pos.x][pos.y];
	}
}; 

#endif