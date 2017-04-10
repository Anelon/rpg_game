#include "startup.h"
#include "splash.h"

int main() {
	//setup ncurses
	initscr();//start curses mode
	start_color(); // enable colors if possible
	//add desired colors when time comes
	clear();
	noecho();
//	cdbreak(); not working for some reason (check includes)
	timeout(TIMEOUT);

	//spash screen
	splash();
	timeout(TIMEOUT);
	clear();

	make_rooms(); //in startup.h
}
