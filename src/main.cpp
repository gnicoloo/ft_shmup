#include "curses.h"

#include <ctime>
#include "GameState.hpp"
#include "Entities.hpp"
#include "Settings.hpp"
#include <chrono>
#include <unistd.h>

using namespace std;

long long int getCurrentTimeMs() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
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
	Player *player = new Player({WINDOW_WIDTH / 2 - 1, WINDOW_HEIGHT-2});
	state.entities.push_front(player);

	while (true)
	{
		state.pressed = wgetch(win);
		state.time = getCurrentTimeMs();
		werase(win);
		box(win, 0, 0);
		for (Entity* entity : state.entities)
		{
			entity->Update(state);
			entity->Render(win);
		}
		wrefresh(win);
	}

	delwin(win);
	endwin();
	return 0;
}
