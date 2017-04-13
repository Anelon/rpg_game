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
	game_map.print_map();
		
	int frame = 0;
	int player_x, player_y;
	player_x = 16, player_y = 8;
	int current_room = 2;
	bool can_move = true;
	game_on = true;
	while (true) {
		if(!game_on) mvprintw(ROOM_SIZE_X+2,0,"Game Paused");
		else mvprintw(ROOM_SIZE_X+3,0,"Game running. Frame: %i Room: %i", frame++, current_room+1);
		mvprintw(ROOM_SIZE_X+4,0, "WASD keys to move around");
		mvprintw(ROOM_SIZE_X+5,0, "Space to attack");
		mvprintw(ROOM_SIZE_X+6,0, "Enter to pause game");
		mvprintw(ROOM_SIZE_X+7,0, "Q to quit");
		mvaddch(player_y,player_x, PLAYER);
		int ch = getch();//wait for user input, with timeout delay
		if (ch == 'q' || ch == 'Q') break;
		else if (ch == ' ' && game_on) ;//add attack
		else if (ch == '\n') game_on = !game_on ;//pause or unpause game
		else if (ch == ERR) ;//do nothing
		else if (ch == 'w' && game_on) {	//UP
			//check for door
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y-1)) == DOOR){
				//leave room change room enter room
				game_map.get_room(current_room).leave_room();
				current_room+=5;
				game_map.get_room(current_room).enter_room();	
				player_x = 16, player_y = 15;
				game_map.print_map();
			}
			//check if tile moving to is open
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y-1)) != OPEN) can_move = false;
			if(!(player_y < 2) && can_move) player_y--;
		} else if (ch == 's' && game_on) {	//DOWN
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y+1)) == DOOR) {
				//leave room change room enter room
				game_map.get_room(current_room).leave_room();
				current_room-=5;
				game_map.get_room(current_room).enter_room();	
				player_x = 16, player_y = 0;
				game_map.print_map();
			}
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y+1)) != OPEN) can_move = false;
			if(!(player_y > ROOM_SIZE_X-3) && can_move) player_y++;
		} else if (ch == 'a' && game_on) {	//LEFT
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y)-1) == DOOR) {
				//leave room change room enter room
				game_map.get_room(current_room).leave_room();
				current_room--;
				game_map.get_room(current_room).enter_room();	
				player_x = 30, player_y = 8;
				game_map.print_map();
			}
			//check if can move
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y)-1) != OPEN) can_move = false;
			if(!(player_x < 4) && can_move) player_x-=2;
		} else if (ch == 'd' && game_on) {	//RIGHT
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y)+1) == DOOR) {
				//leave room change room enter room
				game_map.get_room(current_room).leave_room();
				current_room++;
				game_map.get_room(current_room).enter_room();	
				player_x = 0, player_y = 8;
				game_map.print_map();
			}
			if(game_map.get_room(current_room).get_tile(index(player_x,player_y)+1) != OPEN) can_move = false;
			if(!(player_x > (ROOM_SIZE_X*2)-6) && can_move) player_x+=2;
		}
		can_move = true;


		game_map.get_room(current_room).print_room();
		refresh();
		wait_ticks(1000);
	}
	endwin();//end curses
	system("clear");
}
