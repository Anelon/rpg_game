#include "constants.h"

class room {
	private:
		vector<char> tile;
		bool seen = false;
		bool in_room = false;
	public:
		void set_room(string room);
		vector<char> render_room_map();
		void render_room();
		void print_room();
		void print_render_room_map();
		void see_room();
		bool is_seen();
		void leave_room();
		void enter_room();
		bool is_in_room();
		char get_tile(int space);
};

class map {
	private:
		vector<room> game_map;
		vector<char> mini_map;
	public:
		void render_map();
		void print_map();
		void generate_map();
		void addto_map(room add);
		void shuffle_map();
		room get_room(int room_number);
};


void room::set_room(string room) {
	for(unsigned int i = 0; i < room.size(); i++) tile.push_back(room.at(i));
}
void room::render_room() {
	for(unsigned int i = 0; i < tile.size(); i++) {
		if(i%16 == 0 && i >=1) cout << endl;
		cout << tile.at(i) << " ";
	}
	cout << endl;
}
void room::print_room() {
	int row = 0;
	int column = 0;
	//move 2 columns for every one out (to look nicer)
	for(unsigned int i = 0; i < tile.size(); i++) {
		if(i%16 == 0 && i >=1) {
			row++;
			column -=16;
		}
		mvaddch(row,(i%16)+column,tile.at(i));
		column++;
	}
}
vector<char> room::render_room_map() {
	vector<char> map_tile;
	map_tile.push_back('#');
	//check top room for door
	if(tile.at(8) == '=') map_tile.push_back('=');
	else map_tile.push_back('#');
	map_tile.push_back('#');
	//check left side for door
	if(tile.at(128) == '=') map_tile.push_back('=');
	else map_tile.push_back('#');
	map_tile.push_back('.');
	//check right side for door
	if(tile.at(127) == '=') map_tile.push_back('=');
	else map_tile.push_back('#');
	map_tile.push_back('#');
	//check bottom for door
	if(tile.at(248) == '=') map_tile.push_back('=');
	else map_tile.push_back('#');
	map_tile.push_back('#');
	return map_tile;
}
void room::print_render_room_map() {
	vector<char> room_vec = render_room_map();
	for(unsigned int i = 0; i < room_vec.size(); i++) {
		if(i%3 == 0 && i >= 1) cout << endl;
		cout << room_vec.at(i);
	}
	cout << endl;
}
//will update the mini map to show the rooms entered
void room::see_room() {
	seen = true;
}
bool room::is_seen() {
	return seen;
}
void room::leave_room() {
	in_room = false;
}
void room::enter_room() {
	in_room = true;
}
bool room::is_in_room() {
	return in_room;
}
char room::get_tile(int space) {
	return tile.at(space);
}

void map::render_map() {
	//shows mini map
	vector<char> blank_room(9, ' ');
	//takes the rending of the rooms vector and puts them in mini map vector if seen
	for (unsigned int i = 0; i < game_map.size(); i++) {
		vector<char>basic_room = game_map.at(i).render_room_map();
		//if(game_map.at(i).is_seen())
		mini_map.insert(mini_map.end(), basic_room.begin(), basic_room.end());
		//else mimi_map.insert(mini_map.end(), blank_room.begin(), blank_room.end());
	}
}
void map::print_map() {
	render_map();
	int column = 35;
	int row = 0;
	for (unsigned int i = 0; i < mini_map.size(); i++) {
		//place character on map then incriment column
		mvaddch(row,column,mini_map.at(i));
		column++;
		//moves the map row down 1 and puts the columns back to the start
		if(i%45 == 44) {
			row += 4;
			column -=20;
		}
		//handles each room's map positioning
		if(i%9 == 2) {
			row++;
			column -=3;
		}else if(i%9 == 5) {
			row++;
			column -=3;
		} else if(i%9 == 8) {
			row-=2;
			column++;
		}
	}	
}
void map::generate_map() {
	random_shuffle(game_map.begin()+1, game_map.end()-1);
}

void map::addto_map(room add) {
	game_map.push_back(add);
}
room map::get_room(int room_number) {
	return game_map.at(room_number);
}
