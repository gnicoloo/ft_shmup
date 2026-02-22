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
#include "Spawners.hpp"

using namespace std;

void FreeEntities(GameState &state)
{
	for (Entity* entity : state.entities)
		delete entity;
	
	for (Entity* entity : state.spawn_queue)
		delete entity;
}

void DrawLogo(std::string path, int start_y)
{
	std::ifstream file(path);
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

void RenderHUD(WINDOW* hud, WINDOW* upgrades, GameState& state)
{
	wprintw(hud, "\n Score: %4d\n", state.score);
	wprintw(hud, " Time: %5.2f\n", SECONDS((state.time - state.startTime)));
	wprintw(hud, " Lives: %4d", state.player->GetHealth());
	wprintw(hud, "\n Shards: %3d\n", state.shards_collected);
	wprintw(hud, " Chests: %3d\n", state.chests);

	wprintw(upgrades, "\n AUGMENT LIST:\n");
	wprintw(upgrades, "-----------------------------\n");
	for (std::string augment : state.augments)
		wprintw(upgrades, " %s\n", augment.c_str());
}

int main()
{
	WINDOW *win, *hud, *upgrades_win;

	srand(time(0));
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, LINES/2 - WINDOW_HEIGHT/2, COLS/2 - WINDOW_WIDTH/2);
	hud = newwin(HUD_HEIGHT, HUD_WIDTH, LINES/2 - WINDOW_HEIGHT/2, COLS/2 - WINDOW_WIDTH/2 - HUD_WIDTH);
	upgrades_win = newwin(UPGRADES_HEIGHT, UPGRADES_WIDTH, LINES/2 - WINDOW_HEIGHT/2, COLS /2 + WINDOW_WIDTH/2);
	
	keypad(win, TRUE);
	nodelay(win, TRUE);
	notimeout(win, TRUE);
	wrefresh(win);
	wrefresh(hud);
	wrefresh(upgrades_win);

	GameState state = {};
	state.time = getCurrentTime();
	state.startTime = state.time;
	state.player = new Player({WINDOW_WIDTH / 2 - 5, WINDOW_HEIGHT-2});
	state.entities.push_front(state.player);
	state.entities.push_front(new EnemySpawner());
	state.entities.push_front(new ChestSpawner());

	DrawLogo(std::string("logo.txt"), LOGO_HEIGHT);
	while (true)
	{
		state.pressed = wgetch(win);
		if (state.pressed == 'q')
			break;
		state.deltaTime = getCurrentTime() - state.time;
		state.time = getCurrentTime();
		werase(win);
		werase(hud);
		werase(upgrades_win);

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
		RenderHUD(hud, upgrades_win, state);
		box(hud, 0, 0);
		box(upgrades_win, 0, 0);

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

		if (state.player->GetHealth() <= 0)
		{
			DrawLogo("gameover.txt", LINES/2);
			usleep(1000000);
			getch();
			break;
		}

		wrefresh(win);
		wrefresh(hud);
		wrefresh(upgrades_win);
	}

	FreeEntities(state);

	delwin(win);
	delwin(hud);
	delwin(upgrades_win);
	endwin();
	return 0;
}
