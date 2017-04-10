#include "constants.h"

class room {
	private:
		vector<char> tile;
		bool seen = false;
	public:
		void set_room(string room);
		vector<char> render_room_map();
		void render_room();
		void print_render_room_map();
		void see_room();
		bool is_seen();
};

class map {
	private:
		vector<room> game_map;
		vector<char> mini_map;
	public:
		void render_map();
		void generate_map();
		void addto_map(room add);
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
vector<char> room::render_room_map() {
	vector<char> map_tile;
	map_tile.push_back('#');
	if(tile.at(8) == '=') map_tile.push_back('=');
	else map_tile.push_back('#');
	map_tile.push_back('#');
	if(tile.at(128) == '=') map_tile.push_back('=');
	else map_tile.push_back('#');
	map_tile.push_back('.');
	if(tile.at(127) == '=') map_tile.push_back('=');
	else map_tile.push_back('#');
	map_tile.push_back('#');
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
//will update the mini map to show the room entered
void room::see_room() {
	seen = true;
}
bool room::is_seen() {
	return seen;
}

void map::render_map() {
	//shows mini map (move to side get working with curses)
	vector<char> blank_room(9, ' ');
	//takes the rending of the rooms vector and puts them in mini map vector if seen
	for (unsigned int i = 0; i < game_map.size(); i++) {
		vector<char>basic_room = game_map.at(i).render_room_map();
		//if(game_map.at(i).is_seen())
		mini_map.insert(mini_map.end(), basic_room.begin(), basic_room.end());
		//else mimi_map.insert(mini_map.end(), blank_room.begin(), blank_room.end());
	}
	//formats and outputs the minimap
	int column = 0;
	int row = 0;
	for (unsigned int i = 0; i < mini_map.size(); i++) {
		if(i%9 == 0) {
			cout << mini_map.at(i);
			column++;
		}
		if(i%9 == 1) {
			cout << mini_map.at(i);
			column++;
		}
		if(i%9 == 2) {
			cout << mini_map.at(i);
			column++;
			row++;
		}
		if(i%9 == 3) {
			cout << mini_map.at(i);
		}
		if(i%9 == 4) {
			cout << mini_map.at(i);
		}
		if(i%9 == 5) {
			cout << mini_map.at(i);
		}
		if(i%9 == 6) {
			cout << mini_map.at(i);
		}
		if(i%9 == 7) {
			cout << mini_map.at(i);
		}
		if(i%9 == 8) {
			cout << mini_map.at(i);
			cout << endl;
		}
	}	
	cout << endl;
}
void map::generate_map() {
	random_shuffle(game_map.begin(), game_map.end());
}

void map::addto_map(room add) {
	game_map.push_back(add);
}
