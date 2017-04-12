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
using namespace std;

const unsigned char OPEN = '.';
const unsigned char WALL = '#';
const unsigned char MOB = 'M';
const unsigned char BOSS = 'B';
const unsigned char PLAYER = 'P';
const unsigned char	CHEST = '$';
const unsigned char DOOR = '=';
const unsigned char KEY = 'K';

const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;
int cursor_x, cursor_y;

int MAP_SIZE_X = 5;
int ROOM_SIZE_X = 16;
bool game_on;
const unsigned int TIMEOUT = 300;

int index(int x, int y) {
	x = x/2;
	while (x < 0) x+=ROOM_SIZE_X;
	while (y < 0) y+=ROOM_SIZE_X;
	if (x >= ROOM_SIZE_X) x %= ROOM_SIZE_X;
	if (y >= ROOM_SIZE_X) y %= ROOM_SIZE_X;
	return (x*ROOM_SIZE_X+y);
}
void wait_ticks(int ticks) {
	clock_t start = clock();
	while ((clock() - start) < ticks) ;
}
