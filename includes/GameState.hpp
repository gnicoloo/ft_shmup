#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>
class Entity;

struct GameState
{
	long long int time;
	int score;
	int level;
	int pressed;
	std::list<Entity*> entities;

	bool isKeyPressed(int key){return pressed==key;}
}; 

#endif