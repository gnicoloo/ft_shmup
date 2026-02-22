#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>
#include "Settings.hpp"
#include "Data_Structs.hpp"
#include <string>

class Entity;
class Player;

struct GameState
{
	long long int startTime;
	long long int time;
	long long int deltaTime;
	int score;
	int shards_collected;
	int chests;
	int pressed;
	Player* player;
	std::list<Entity*> entities;
	std::list<Entity*> spawn_queue;
	Entity* collision_map[WINDOW_WIDTH][WINDOW_HEIGHT] = {};
	std::list<std::string> augments;
	std::list<std::string> augments_left;

	GameState() 
	{
		augments_left = {
			"Particle Augment",
			"Particle Score Augment",
			"Shooting speed Augment",
			"Shooting cooldown Augment"
		};
	}
	bool isKeyPressed(int key){return pressed==key;}
	Entity *GetCollisionMap(Vector2 pos)
	{
		return collision_map[pos.x][pos.y];
	}

	bool HasAugment(std::string augment)
	{
		for (std::string item : augments)
			if (item == augment)
				return true;
		return false;
	}
}; 

#endif