#include "startup.h"

class frame {
	private:
		int frame = 0;
	public:
		int next_frame() {return frame++;};
};

//game setup
map game_map = make_rooms(); //in startup.h
//initialize variables	
frame frameCount;


int main() {
	//shows when c++ is ready
	cout << "Game Started\n";
	game_map.get_room(current_room).enter_room();
	game_map.get_room(current_room).see_room();
	EM_ASM("runGameLoop(' ')");
}

const char* EMSCRIPTEN_KEEPALIVE getGameMap() {
	string gameMap = game_map.string_map().c_str();
	//cout << gameMap << endl;
	return gameMap.c_str();
}

const char* EMSCRIPTEN_KEEPALIVE gameLoop(int ch) {
	cout << "Frame: " << frameCount.next_frame() << endl;
	bool can_move = true;
	if (ch == 'q' || ch == 'Q') return game_map.get_room(current_room).string_room().c_str();
	else if (ch == ' ' && game_on) {
		;//interact with
	}
	else if (ch == '\n') game_on = !game_on ;//pause or unpause game

///////////////////////////////////////////////////////////////////////////////////
	else if (ch == 'w' && game_on) {	//UP
		prevMove = ch;
		//check for door
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y-1)) == DOOR){
			//leave room change room enter room
			game_map.get_room(current_room).leave_room();
			current_room+=5;
			game_map.get_room(current_room).enter_room();	
			game_map.get_room(current_room).see_room();	
			new_player_y = 14;
			can_move = false;
		}
		//check if can move
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y-1)) != OPEN) can_move = false;
		if(!(new_player_y < 2) && can_move) new_player_y--;

///////////////////////////////////////////////////////////////////////////////////
	} else if (ch == 's' && game_on) {	//DOWN
		prevMove = ch;
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y+1)) == DOOR) {
			//leave room change room enter room
			game_map.get_room(current_room).leave_room();
			current_room-=5;
			game_map.get_room(current_room).enter_room();	
			game_map.get_room(current_room).see_room();	
			new_player_y = 1;
			can_move = false;
		}
		//check if can move
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y+1)) != OPEN) can_move = false;
		if(!(new_player_y > ROOM_SIZE_X-3) && can_move) new_player_y++;

///////////////////////////////////////////////////////////////////////////////////
	} else if (ch == 'a' && game_on) {	//LEFT
		prevMove = ch;
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y)-1) == DOOR) {
			//leave room change room enter room
			game_map.get_room(current_room).leave_room();
			current_room--;
			game_map.get_room(current_room).enter_room();	
			game_map.get_room(current_room).see_room();	
			new_player_x = 14;
			can_move = false;
		}
		//check if can move
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y)-1) != OPEN) can_move = false;
		if(!(new_player_x < 2) && can_move) new_player_x--;

///////////////////////////////////////////////////////////////////////////////////
	} else if (ch == 'd' && game_on) {	//RIGHT
		prevMove = ch;
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y)+1) == DOOR) {
			//leave room change room enter room
			game_map.get_room(current_room).leave_room();
			current_room++;
			game_map.get_room(current_room).enter_room();	
			game_map.get_room(current_room).see_room();	
			new_player_x = 1;
			can_move = false;
		}
		//check if can move
		if(game_map.get_room(current_room).get_tile(index(new_player_x,new_player_y)+1) != OPEN) can_move = false;
		if(!(new_player_x > ROOM_SIZE_X-1) && can_move) new_player_x++;
	}
	//move the player to the new location
	string stringRoom = game_map.get_room(current_room).move_player(new_player_x,new_player_y);
	//start AI monster moving
	if(game_on) {
	}
	if (current_room == 22) {
		//system("clear");
		cout << "You Win!\n";
		//return "0";
		return game_map.get_room(current_room).string_room().c_str();
	}
	wcout << stringRoom.c_str();
	return stringRoom.c_str();
}
