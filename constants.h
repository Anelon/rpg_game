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

int MAP_SIZE_X, MAP_SIZE_Y;
int ROOM_SIZE_X, ROOM_SIZE_Y;
bool game_on;
