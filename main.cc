#include "startup.h"
#include "splash.h"

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
	splash();
	timeout(TIMEOUT);
	clear();

	mvaddch(0,0,'i');
	mvprintw(1,0,"test");
	//make_rooms(); //in startup.h
}
