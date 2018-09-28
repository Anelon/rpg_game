#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
//#include <ncurses.h>
#include <utility>
#include <limits>
#include <algorithm>
#include <unistd.h>
#include <emscripten/emscripten.h>
using namespace std;
//map tiles
const unsigned char OPEN = '.';
const unsigned char WALL = '#';
const unsigned char MOB = 'm';
const unsigned char BOSS = 'B';
const unsigned char PLAYER = 'P';
const unsigned char CHEST = '$';
const unsigned char GOAL = 'G';
const unsigned char DOOR = '=';
const unsigned char LOCKED_DOOR = 'L';
const unsigned char KEY = 'K';
const int DOOR_CHANCE = 6; // out of 10
const int MOB_CHANCE = 3; // out of 100
char prevMove = ' ';
//cursor movemnt (unused)
const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;
int cursor_x, cursor_y;
int new_player_x = 8;
int new_player_y = 8;
int current_room = 2;
//locations on room (middle of sides)
const int MAP_TOP = 8;
const int MAP_BOTTOM = 248;
const int MAP_LEFT = 128;
const int MAP_RIGHT = 127;
//base sizes
int MAP_SIZE_X = 5;
int ROOM_SIZE_X = 16;

vector<string> dialogues = {"Sorry, no speak english"};
/*
	,
	"Go to the top",
	"Gl HF",
	"I have this song stuck in my head but I am missing one word, </br>'You know how people always say</br>Seize the moment</br>I dont know im kindof thinking its the other way around,</br>Like the moment seizes us",
	"42"
};
*/
vector<string> names = {"Kerney"};
//,"Bill","Bell","Roberkora","Cagver","Mareriona","Capridriguez","Honinki","Parkerhugia","Rosephasia","Hydrasmith","Mythichenry","Firepatterson","Walkerganta","Diazgoodness","Weaspell","Jenkinstomp","Satannoz","Youngelf","Ramozoga","Taylorreeka","Pakesmi","Simmonsabiella","Blalga","Morrisaphima","Murrayensteinia","Lloflame","Menshark","Elright","Rhaelhall","Flolafia","Graypower","Cheekperry","Compa","Orticlop","Cari The Cat","Gigantnor","Bryantoadie","Huntsparkle","Hawkinsrot","Serabooth","Sanchepuff","Ogoherrera","Legospencer","Pricetter","Abaltson","Blala","Executionyes","Gnohunter","Harriw","Dilka","Waroshark","Turnerstinkie","Ramireddy","Moraleniar","Stewartganto","Rotrosity","Executionmurphy","Hydrakelley","Silverross","Gonzalek","Mcdonaldazor","Drekagonzales","Chafoot","Hammastierrez","Hernandevac","Henderhell","Rillop","Hernandemane","Mashwens","Rainse","Hussainreek","Fletpop","Battledner","Clarcoffin","Firellins","Keverse","Thoshine","Greenllace","Capogo","Do'edwa","Grrriley","Grangriffiths","Gardneralam","Warry","Barnesthumper","Malesanders","Ohmsarnold","Daviessparkle","Alehuge","Spensmoke","Gangrant","Do'shar","Talchell","Fangrales","Gwydnald","Brootopus","Snyderubim","Grindyreed","Ramireshark","Seratson","Garook"};
string getName() {
	return names.at(0);
}
string getDialogue() {
	return dialogues.at(0);
}

bool game_on = true;

const unsigned int TIMEOUT = 300;
//conver x and y to a vector index
int index(int x, int y) {
	//x = x/2;
	while (x < 0) x+=ROOM_SIZE_X;
	while (y < 0) y+=ROOM_SIZE_X;
	if (x >= ROOM_SIZE_X) x %= ROOM_SIZE_X;
	if (y >= ROOM_SIZE_X) y %= ROOM_SIZE_X;
	return (y*ROOM_SIZE_X+x);
}
vector<int> coordinate(int index) {
	vector<int> coordiantes;
	coordiantes.push_back(index%16);
	coordiantes.push_back(index/16);
	return coordiantes;
}
void wait_ticks(int ticks) {
	clock_t start = clock();
	while ((clock() - start) < ticks) ;
}
