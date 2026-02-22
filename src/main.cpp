#include "curses.h"

#include <ctime>
#include "GameState.hpp"
#include "Entities.hpp"
#include "Entity.hpp"
#include "Settings.hpp"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

void DrawLogo(int start_y)
{
	std::ifstream file("logo.txt");
    std::string line;
    
    while (std::getline(file, line)) 
    {
        int x = (COLS - line.length()) / 2;
        mvprintw(start_y++, x, "%s", line.c_str());
    }
    refresh();
}

long long int getCurrentTime() {
    return std::chrono::steady_clock().now().time_since_epoch().count();
}

void RenderHUD(WINDOW* hud, WINDOW* win, GameState& state)
{
	wprintw(hud, "\n Score: %d\n", state.score);
	wprintw(hud, " Level: %d\n", state.level);
	wprintw(hud, " Time: %.2f\n", SECONDS((state.time - state.startTime)));
}

int main()
{


	WINDOW *win, *hud;
	int startx, starty, width, height;

	srand(time(0));
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, LINES/2 - WINDOW_HEIGHT/2, COLS/2 - WINDOW_WIDTH/2);
	hud = newwin(HUD_HEIGHT, HUD_WIDTH, LINES/2 - WINDOW_HEIGHT/2, COLS/2 - WINDOW_WIDTH/2 - 20);
	keypad(win, TRUE);
	nodelay(win, TRUE);
	notimeout(win, TRUE);
	wrefresh(win);
	wrefresh(hud);

	GameState state = {};
	state.time = getCurrentTime();
	state.startTime = state.time;
	state.entities.push_front(new Player({WINDOW_WIDTH / 2 - 1, WINDOW_HEIGHT-2}));
	state.entities.push_front(new BaseEnemy({WINDOW_WIDTH / 2 - 1, 5}));

	DrawLogo(5);
	while (true)
	{
		state.pressed = wgetch(win);
		state.deltaTime = getCurrentTime() - state.time;
		state.time = getCurrentTime();
		werase(win);
		werase(hud);

		state.entities.splice(state.entities.begin(), state.spawn_queue);
		state.spawn_queue.clear();
		
		for (Entity* entity : state.entities)
			entity->BakeCollisionMap(state);

		for (Entity* entity : state.entities)
		{
			entity->Update(state);
			entity->Render(win);
		}
		box(win, 0, 0);
		RenderHUD(hud, win, state);
		box(hud, 0, 0);

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
		wrefresh(hud);
	}

	delwin(win);
	delwin(hud);
	endwin();
	return 0;
}
