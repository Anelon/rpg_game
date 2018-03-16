#include "constants.h"
#include "mobAI.h"

class room {
	private:
		vector<char> tile;
		vector<Mob> monsters;
		bool seen = false;
		bool in_room = false;
		bool reachable = false;
		int player_x = 8;
		int player_y = 8;
	public:
		bool door_top = false;
		bool door_bottom = false;
		bool door_left = false;
		bool door_right = false;
		void set_room(string room);
		vector<char> render_room_map();
		void render_room();
		string string_room();
		void print_render_room_map();
		void see_room();
		bool is_seen();
		void leave_room();
		void enter_room();
		bool is_in_room();
		char get_tile(int space);
		void add_door(int place);
		void set_mob(int place);
		bool is_reachable();
		void is_reached();
		void not_reachable();
		int get_size();
		void move_monster();
		string move_player(int new_player_x,int new_player_y);
		bool player_in();
};

class map {
	private:
		vector<room> game_map;
		vector<char> mini_map;
	public:
		void render_map();
		string string_map();
		void generate_map();
		void addto_map(room add);
		void shuffle_map();
		room& get_room(int room_number);
		void open_doors();
		void solvable(int room);
		void add_mob();
		void reset();
};


void room::set_room(string room) {
	for(unsigned int i = 0; i < room.size(); i++) tile.push_back(room.at(i));
}
void room::render_room() {
	for(unsigned int i = 0; i < tile.size(); i++) {
		if(i%16 == 0 && i >=1) cout << endl;
		cout << tile.at(i);
	}
	cout << endl;
}
string room::string_room() {
	string stringRoom = "";
	for(unsigned int i = 0; i < tile.size(); i++) {
		if (i%16 == 0 && i != 0) stringRoom.push_back(' ');
		stringRoom.push_back(tile.at(i));
	}
	return stringRoom;
}
//gives a 3x3 map for the room
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
	//replace with P if player?
	//B if boss mob (when adding mobs)
	if (is_in_room()) {
		map_tile.push_back('P');
	} else {
		map_tile.push_back('.');
	}
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
		if(i%3 == 0 && i != 0) cout << endl;
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
void room::add_door(int place) {
	//TOP
	if (place == MAP_TOP) {
		tile.at(place) = '=';
		tile.at(place-1) = '=';
		door_top = true;
	}
	//BOTTOM
	else if (place == MAP_BOTTOM) {
		tile.at(place) = '=';
		tile.at(place-1) = '=';
		door_bottom = true;
	}
	//LEFT
	else if (place == MAP_LEFT) {
		tile.at(place) = '=';
		tile.at(place-16) = '=';
		door_left = true;
	}
	//RIGHT
	else if (place == MAP_RIGHT) {
		tile.at(place) = '=';
		tile.at(place+16) = '=';
		door_right = true;
	}
}
void room::set_mob(int place) {
	tile.at(place) = 'm';
	Mob temp_mob;
	temp_mob.setlife(100);
	temp_mob.set_location(place);
	monsters.push_back(temp_mob);
}
bool room::is_reachable() {
	return reachable;
}
void room::is_reached() {
	reachable = true;
}
void room::not_reachable() {
	reachable = false;
}
int room::get_size() {
	return tile.size();
}
/*void room::move_monster() {
	for (unsigned int i = 0; i < monsters.size(); i++) {
		vector<int> coord = get_coordinate(monsters.at(i));
		int new_x = coord[0] + rand()%3 -1;
		int new_y = coord[1] + rand()%3 -1;
		index(new_x, new_y);
	}
}*/
string room::move_player(int new_player_x, int new_player_y) {
	tile.at(index(player_x,player_y)) = OPEN;
	tile.at(index(new_player_x,new_player_y)) = PLAYER;
	player_x = new_player_x;
	player_y = new_player_y;
	//render_room();
	string stringed = string_room();
	return stringed;
}
bool room::player_in() {
	auto it = find(tile.begin(),tile.end(),PLAYER);
	return it != tile.end();
}



void map::render_map() {
	//shows mini map
	mini_map.clear();
	vector<char> blank_room(9, ' ');
	//takes the rending of the rooms vector and puts them in mini map vector if seen
	for (unsigned int i = 0; i < game_map.size(); i++) {
		vector<char>basic_room = game_map.at(i).render_room_map();
		//if(game_map.at(i).is_seen())
		mini_map.insert(mini_map.end(), basic_room.begin(), basic_room.end());
		//else mimi_map.insert(mini_map.end(), blank_room.begin(), blank_room.end());
	}
}
string map::string_map() {
	render_map();
	string stringMap = "";
	for (size_t i = 0 ; i < mini_map.size(); i++) {
		stringMap.push_back(mini_map.at(i));
	}
	return stringMap;
}
void map::generate_map() {
	cout << "shuffle shuffle shuffle\n";
	srand(time(NULL));
	random_shuffle(game_map.begin()+1, game_map.end()-1);
	swap(game_map.at(0),game_map.at(2));
	swap(game_map.at(24),game_map.at(22));
}
//add a room to the map (used on startup)
void map::addto_map(room add) {
	game_map.push_back(add);
}
//give the room number get the room
//POSSIBLY WHERE NOT GETTING SAVED?
room& map::get_room(int room_number) {
	return game_map.at(room_number);
}
void map::open_doors() {
	srand(time(NULL));
	for(unsigned int i = 0; i < game_map.size(); i+=2) {
		int roll = 0;
		if (i !=2) {
			//top
			if (i <= 19) {
				roll = (rand()%10);
				if (roll < DOOR_CHANCE) {
					game_map.at(i).add_door(MAP_TOP);
					game_map.at(i+5).add_door(MAP_BOTTOM);
					if (i == 22) continue; //only allow one door in boss room
				}
			}
			//bottom
			if(i >= 5) {
				roll = (rand()%10);
				if (roll < DOOR_CHANCE) {
					game_map.at(i).add_door(MAP_BOTTOM);
					game_map.at(i-5).add_door(MAP_TOP);
					if (i == 22) continue; //only allow one door in boss room
				}
			}
			//left
			if(i%5 != 0) {
				roll = (rand()%10);
				if (roll < DOOR_CHANCE) {
					game_map.at(i).add_door(MAP_LEFT);
					game_map.at(i-1).add_door(MAP_RIGHT);
					if (i == 22) continue; //only allow one door in boss room
				}
			}
			//right
			if (i%5 != 4) {
				roll = (rand()%10);
				if (i == 22) roll = 1; //force a door to be in boss room
				if (roll < DOOR_CHANCE) {
					game_map.at(i).add_door(MAP_RIGHT);
					game_map.at(i+1).add_door(MAP_LEFT);
				}
			}
		} else {//force doors around starting room
			game_map.at(i-1).add_door(MAP_RIGHT);
			game_map.at(i+1).add_door(MAP_LEFT);
			game_map.at(i+5).add_door(MAP_BOTTOM);
		}
	}
}
void map::solvable(int room) {
	cout << "test\n";
	bool door_top = (get_room(room).get_tile(8) == '=');
	bool door_bottom = (get_room(room).get_tile(248) == '=');
	bool door_left = (get_room(room).get_tile(128) == '=');
	bool door_right = (get_room(room).get_tile(127) == '=');
	get_room(room).is_reached();
	if (door_top && !game_map.at(room+5).is_reachable()) {
		solvable(room+5);
	} 
	if (door_bottom && !game_map.at(room-5).is_reachable()) {
		solvable(room-5);
	} 
	if (door_left && !game_map.at(room-1).is_reachable()) {
		solvable(room-1);
	} 
	if (door_right && !game_map.at(room+1).is_reachable()) {
		solvable(room+1);
	}
}
void map::add_mob() {
	for(unsigned int i = 0; i < game_map.size(); i++) {
		int roll = 0;
		if (i !=2) {
			for(int j = 0; j < game_map.at(i).get_size(); j++) {
				//set monsters to not spawn on edges of maps
				if(i > 32 || i < 224 || (i%16) == 1 || (i%16) == 15) continue;
				//place monsters
				if(game_map.at(i).get_tile(j) == '.') {
					roll = (rand()%100);
					if (roll < MOB_CHANCE) { //add monster to room
						game_map.at(i).set_mob(j);
					}
				}
			}
		}
	}
}
void map::reset() {
	game_map.clear();
}
