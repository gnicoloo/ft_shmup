#include "curses.h"

#include <ctime>
#include "GameState.hpp"
#include "Entities.hpp"
#include "Settings.hpp"
#include <chrono>
#include <unistd.h>

using namespace std;

long long int getCurrentTime() {
    return std::chrono::steady_clock().now().time_since_epoch().count();
}

int main()
{
	WINDOW *win;
	int startx, starty, width, height;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, LINES/2 - WINDOW_HEIGHT/2, COLS/2 - WINDOW_WIDTH/2);
	keypad(win, TRUE);
	nodelay(win, TRUE);
	notimeout(win, TRUE);
	wrefresh(win);

	GameState state = {};
	state.time = getCurrentTime();
	state.entities.push_front(new Player({WINDOW_WIDTH / 2 - 1, WINDOW_HEIGHT-2}));
	state.entities.push_front(new BaseEnemy({WINDOW_WIDTH / 2 - 1, 5}));

	while (true)
	{
		state.pressed = wgetch(win);
		state.deltaTime = getCurrentTime() - state.time;
		state.time = getCurrentTime();
		werase(win);
		box(win, 0, 0);

		state.entities.splice(state.entities.begin(), state.spawn_queue);
		state.spawn_queue.clear();
		
		for (Entity* entity : state.entities)
			entity->BakeCollisionMap(state);

		for (Entity* entity : state.entities)
		{
			entity->Update(state);
			entity->Render(win);
		}
		memset(state.collision_map, 0, sizeof(state.collision_map));
		state.entities.remove_if([](Entity* entity) 
		{
			if (entity->IsToRemove())
			{
				delete entity;
				return true;
			}
			return false;
		});

		wrefresh(win);
	}

	delwin(win);
	endwin();
	return 0;
}
