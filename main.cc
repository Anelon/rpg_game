#include "startup.h"
//#include "splash.h"

int main() {
	//setup ncurses
	initscr();//start curses mode
	start_color(); // enable colors if possible
	//add desired colors when time comes
	clear();
	noecho();
	//cdbreak();
	timeout(TIMEOUT);

	//spash screen
	//splash();
	timeout(TIMEOUT);

	clear();
	map game_map = make_rooms(); //in startup.h
	game_map.get_room(1).print_room();
	game_map.print_map();
	refresh();
	wait_ticks(10000);

}
