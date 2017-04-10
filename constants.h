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
const unsigned char PLAY = 'P';
const unsigned char	CHEST = '$';
const unsigned char DOOR = '=';
const unsigned char KEY = 'K';

const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int right = 67;
int cursor_x, cursor_y;

int MAP_SIZE_X = 5;
int ROOM_SIZE_X = 16;
bool game_on;
const unsigned int TIMEOUT = 300;

int index(int i, int j) {
	while (i < 0) i+=ROOM_SIZE_X;
	while (j < 0) j+=ROOM_SIZE_X;
	if (i >= ROOM_SIZE_X) i %= ROOM_SIZE_X;
	if (j >= ROOM_SIZE_X) j %= ROOM_SIZE_X;
	return (i*ROOM_SIZE_X+j);
}
