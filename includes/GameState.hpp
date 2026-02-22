#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>
#include "Settings.hpp"

class Entity;

struct GameState
{
	long long int startTime;
	long long int time;
	long long int deltaTime;
	int score;
	int level;
	int pressed;
	std::list<Entity*> entities;
	std::list<Entity*> spawn_queue;
	Entity* collision_map[WINDOW_WIDTH][WINDOW_HEIGHT] = {0};

	bool isKeyPressed(int key){return pressed==key;}
}; 

#endif