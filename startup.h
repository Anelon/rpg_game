#include "map.h"
#include "mobAI.h"

map make_rooms() {
	//setup rooms and add them to room class
	room room1;
	string row1  = "#######==#######";
	string row2  = "#..............#";
	string row3  = "#.##........##.#";
	string row4  = "#.##........##.#";
	string row5  = "#..............#";
	string row6  = "#..............#";
	string row7  = "#..............#";
	string row8  = "=..............=";
	string row9  = "=..............=";
	string row10 = "#..............#";
	string row11 = "#..............#";
	string row12 = "#..............#";
	string row13 = "#.##........##.#";
	string row14 = "#.##........##.#";
	string row15 = "#..............#";
	string row16 = "################";
	string roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room1.set_room(roomtile);
	room room2;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##...m....##.#";
	row5  = "#..............#";
	row6  = "#...m..........#";
	row7  = "#.....####.....#";
	row8  = "#....######....#";
	row9  = "#....######....#";
	row10 = "#.....####.....#";
	row11 = "#..............#";
	row12 = "#...m..........#";
	row13 = "#.##.....m..##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room2.set_room(roomtile);
	room room3;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#..............#";
	row4  = "#..##########..#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#..##########..#";
	row8  = "#..............#";
	row9  = "#..............#";
	row10 = "#..##########..#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#..##########..#";
	row14 = "#..............#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room3.set_room(roomtile);
	room room4;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#....######....#";
	row8  = "#.....#........#";
	row9  = "#........#.....#";
	row10 = "#....######....#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room4.set_room(roomtile);
	room room5;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#..............#";
	row4  = "#..##########..#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#..##########..#";
	row8  = "#..............#";
	row9  = "#..............#";
	row10 = "#..##########..#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#..##########..#";
	row14 = "#..............#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room5.set_room(roomtile);
	room room6;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#....######....#";
	row8  = "#.....#........#";
	row9  = "#........#.....#";
	row10 = "#....######....#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room6.set_room(roomtile);
	room room7;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##...m....##.#";
	row5  = "#..............#";
	row6  = "#...m..........#";
	row7  = "#.....####.....#";
	row8  = "#....######....#";
	row9  = "#....######....#";
	row10 = "#.....####.....#";
	row11 = "#..............#";
	row12 = "#...m..........#";
	row13 = "#.##.....m..##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room7.set_room(roomtile);
	room room8;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##...m....##.#";
	row5  = "#..............#";
	row6  = "#...m..........#";
	row7  = "#.....####.....#";
	row8  = "#....######....#";
	row9  = "#....######....#";
	row10 = "#.....####.....#";
	row11 = "#..............#";
	row12 = "#...m..........#";
	row13 = "#.##.....m..##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room8.set_room(roomtile);
	room room9;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##...m....##.#";
	row5  = "#..............#";
	row6  = "#...m..........#";
	row7  = "#.....####.....#";
	row8  = "#....######....#";
	row9  = "#....######....#";
	row10 = "#.....####.....#";
	row11 = "#..............#";
	row12 = "#...m..........#";
	row13 = "#.##.....m..##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room9.set_room(roomtile);
	room room10;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##...m....##.#";
	row5  = "#..............#";
	row6  = "#...m..........#";
	row7  = "#.....####.....#";
	row8  = "#....######....#";
	row9  = "#....######....#";
	row10 = "#.....####.....#";
	row11 = "#..............#";
	row12 = "#...m..........#";
	row13 = "#.##.....m..##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room10.set_room(roomtile);
	room room11;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#....######....#";
	row8  = "#.....#........#";
	row9  = "#........#.....#";
	row10 = "#....######....#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room11.set_room(roomtile);
	room room12;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#....######....#";
	row8  = "#.....#........#";
	row9  = "#........#.....#";
	row10 = "#....######....#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room12.set_room(roomtile);
	room room13;
	row1  = "################";
	row2  = "####........####";
	row3  = "#####......#####";
	row4  = "######....######";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#....m.....m...#";
	row8  = "#......##......#";
	row9  = "#......##......#";
	row10 = "#....m.....m...#";
	row11 = "##............##";
	row12 = "###..........###";
	row13 = "####........####";
	row14 = "#####......#####";
	row15 = "######....######";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room13.set_room(roomtile);
	room room14;
	row1  = "################";
	row2  = "####........####";
	row3  = "#####......#####";
	row4  = "######....######";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#....m.....m...#";
	row8  = "#......##......#";
	row9  = "#......##......#";
	row10 = "#....m.....m...#";
	row11 = "##............##";
	row12 = "###..........###";
	row13 = "####........####";
	row14 = "#####......#####";
	row15 = "######....######";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room14.set_room(roomtile);
	room room15;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#..............#";
	row4  = "#..##########..#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#..##########..#";
	row8  = "#..............#";
	row9  = "#..............#";
	row10 = "#..##########..#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#..##########..#";
	row14 = "#..............#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room15.set_room(roomtile);
	room room16;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#..............#";
	row4  = "#..##########..#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#..##########..#";
	row8  = "#..............#";
	row9  = "#..............#";
	row10 = "#..##########..#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#..##########..#";
	row14 = "#..............#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room16.set_room(roomtile);
	room room17;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.#..#....#..#.#";
	row5  = "#..m...........#";
	row6  = "#.......m......#";
	row7  = "#..............#";
	row8  = "#..............#";
	row9  = "#........m.....#";
	row10 = "#....##..##....#";
	row11 = "#..m.##..##....#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room17.set_room(roomtile);
	room room18;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.#..#....#..#.#";
	row5  = "#..m...........#";
	row6  = "#.......m......#";
	row7  = "#..............#";
	row8  = "#..............#";
	row9  = "#........m.....#";
	row10 = "#....##..##....#";
	row11 = "#..m.##..##....#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room18.set_room(roomtile);
	room room19;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#.......##..#..#";
	row6  = "#....m.....#...#";
	row7  = "#.....#........#";
	row8  = "#.....m....#...#";
	row9  = "#...###........#";
	row10 = "#.....###m.....#";
	row11 = "#..............#";
	row12 = "#.....m..##....#";
	row13 = "#.##........##.#";
	row14 = "#.##..m.....##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room19.set_room(roomtile);
	room room20;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#.......##..#..#";
	row6  = "#....m.....#...#";
	row7  = "#.....#........#";
	row8  = "#.....m....#...#";
	row9  = "#...###........#";
	row10 = "#.....###m.....#";
	row11 = "#..............#";
	row12 = "#.....m..##....#";
	row13 = "#.##........##.#";
	row14 = "#.##..m.....##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room20.set_room(roomtile);
	room room21;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#.......##..#..#";
	row6  = "#....m.....#...#";
	row7  = "#.....#........#";
	row8  = "#.....m....#...#";
	row9  = "#...###........#";
	row10 = "#.....###m.....#";
	row11 = "#..............#";
	row12 = "#.....m..##....#";
	row13 = "#.##........##.#";
	row14 = "#.##..m.....##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room21.set_room(roomtile);
	room room22;
	row1  = "################";
	row2  = "####........####";
	row3  = "#####......#####";
	row4  = "######....######";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#....m.....m...#";
	row8  = "#......##......#";
	row9  = "#......##......#";
	row10 = "#....m.....m...#";
	row11 = "##............##";
	row12 = "###..........###";
	row13 = "####........####";
	row14 = "#####......#####";
	row15 = "######....######";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room22.set_room(roomtile);
	room room23;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.#..#....#..#.#";
	row5  = "#..m...........#";
	row6  = "#.......m......#";
	row7  = "#..............#";
	row8  = "#..............#";
	row9  = "#........m.....#";
	row10 = "#....##..##....#";
	row11 = "#..m.##..##....#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room23.set_room(roomtile);
	room room24;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##........##.#";
	row4  = "#.##........##.#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#..............#";
	row8  = "#......mm......#";
	row9  = "#......mm......#";
	row10 = "#..............#";
	row11 = "#...m......m...#";
	row12 = "#..............#";
	row13 = "#.##........##.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "################";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room24.set_room(roomtile);
	room room25;
	row1  = "################";
	row2  = "#..............#";
	row3  = "#.##...##...##.#";
	row4  = "#.#..........#.#";
	row5  = "#..............#";
	row6  = "#..............#";
	row7  = "#.......B......#";
	row8  = "#.#..........#.#";
	row9  = "#.#..........#.#";
	row10 = "#..............#";
	row11 = "#..............#";
	row12 = "#..............#";
	row13 = "#.#..........#.#";
	row14 = "#.##........##.#";
	row15 = "#..............#";
	row16 = "#######==#######";
	roomtile = row1 + row2 + row3 + row4 + row5 + row6 + row7 + row8 + row9 + row10 + row11 + row12 + row13 + row14 + row15 + row16;
	room25.set_room(roomtile);
	//add all of the rooms to the map
	map game_map;
	game_map.addto_map(room1);
	game_map.addto_map(room2);
	game_map.addto_map(room3);
	game_map.addto_map(room4);
	game_map.addto_map(room5);
	game_map.addto_map(room6);
	game_map.addto_map(room7);
	game_map.addto_map(room8);
	game_map.addto_map(room9);
	game_map.addto_map(room10);
	game_map.addto_map(room11);
	game_map.addto_map(room12);
	game_map.addto_map(room13);
	game_map.addto_map(room14);
	game_map.addto_map(room15);
	game_map.addto_map(room16);
	game_map.addto_map(room17);
	game_map.addto_map(room18);
	game_map.addto_map(room19);
	game_map.addto_map(room20);
	game_map.addto_map(room21);
	game_map.addto_map(room22);
	game_map.addto_map(room23);
	game_map.addto_map(room24);
	game_map.addto_map(room25);
	cout << "Generating map\n";
	game_map.generate_map();
	game_map.open_doors();
	game_map.solvable(22);
	cout << game_map.get_room(22).is_reachable();
	if (!game_map.get_room(22).is_reachable()) {
		game_map.reset();
		make_rooms();
	}
	return game_map;
}
