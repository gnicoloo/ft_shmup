#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>
#include "Settings.hpp"

class Entity;

struct GameState
{
	long long int time;
	int score;
	int level;
	int pressed;
	std::list<Entity*> entities;
	Entity* collision_map[WINDOW_WIDTH][WINDOW_HEIGHT];

	bool isKeyPressed(int key){return pressed==key;}
}; 

#endif