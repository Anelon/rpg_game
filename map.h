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
};

class map {
	private:
		vector<room> game_map;
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

void map::render_map() {
	for(int i = 0; i < MAP_SIZE_X; i++) {
		for(int j = 0; j < MAP_SIZE_X; j++) { 
			cout << "#" << endl;
		}
		cout << endl;
	}
}
void map::generate_map() {
	random_shuffle(game_map.begin(), game_map.end());
}

void map::addto_map(room add) {
	game_map.push_back(add);
}
