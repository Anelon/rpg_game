#include "startup.h"

//game setup
map game_map = make_rooms(); //in startup.h
//game_map.print_map();
//initialize variables	
int frame = 0;
int player_x = 8;
int player_y = 8;
int current_room = 2;
bool can_move = true;
//game_on = true;


int main() {
	//clear();
	//makes and prints out map with mini_map
	//map game_map = make_rooms();
	//main loop of doom TURN INTO GAME LOOP FUNCTION
	//gameLoop(' ');
	cout << "Game Started\n";
}

const char* EMSCRIPTEN_KEEPALIVE gameLoop(int ch) {
	if (ch == 'q' || ch == 'Q') return game_map.get_room(current_room).string_room().c_str();
	else if (ch == ' ' && game_on) ;//add attack
	else if (ch == '\n') game_on = !game_on ;//pause or unpause game

///////////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////////
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
	//start AI monster moving
	if(game_on) {
	}
	if (current_room == 22) {
		system("clear");
		cout << "You Win!\n";
		return game_map.get_room(current_room).string_room().c_str();
	}

	can_move = true;
	string stringRoom = game_map.get_room(current_room).string_room();
	cout << stringRoom;
	return stringRoom.c_str();
}
