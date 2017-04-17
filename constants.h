#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include <utility>
#include <limits>
#include <algorithm>
#include <unistd.h>
using namespace std;
//map tiles
const unsigned char OPEN = '.';
const unsigned char WALL = '#';
const unsigned char MOB = 'm';
const unsigned char BOSS = 'B';
const unsigned char PLAYER = 'P';
const unsigned char	CHEST = '$';
const unsigned char DOOR = '=';
const unsigned char KEY = 'K';
const int DOOR_CHANCE = 6; // out of 10
const int MOB_CHANCE = 10; // out of 100
//cursor movemnt (unused)
const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;
int cursor_x, cursor_y;
//locations on room (middle of sides)
const int MAP_TOP = 8;
const int MAP_BOTTOM = 248;
const int MAP_LEFT = 128;
const int MAP_RIGHT = 127;
//base sizes
int MAP_SIZE_X = 5;
int ROOM_SIZE_X = 16;

bool game_on;
const unsigned int TIMEOUT = 300;
//conver x and y to a vector index
int index(int x, int y) {
	x = x/2;
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
