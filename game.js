var game = document.getElementById("game");
var map = document.getElementById("map");
var start = document.getElementById("start");

start.addEventListener("click", load());
function load () {
	console.log("start");
	game.innerHTML = "";
	for (var i = 0; i < 16; i++) {
		for (var j = 0; j < 16; j++) {
			var tile = document.createElement("div");
			tile.setAttribute("class", "tile");
			tile.setAttribute("id", "gameTile"+(i*16+j));
			game.appendChild(tile);
		}
	}
	for (var i = 0; i < 25; i++) {
		//make roomTile, put 9 tiles into it
		//repeat 25 times
		var roomTile = document.createElement("div");
		roomTile.setAttribute("class","roomTile");
		roomTile.setAttribute("id","roomTile"+(25-i));
		map.appendChild(roomTile);
		for (var j = 0; j < 9; j++) {
			var tile = document.createElement("div");
			tile.setAttribute("class","tile");
			tile.setAttribute("id", "mapTile"+j);
			roomTile.appendChild(tile);
		}
	}

	document.addEventListener("keypress", function () {
		runGameLoop(event.key.charCodeAt(0));
	});
	//console.log("loadrun");
	//runGameLoop(" ");
};

function runGameLoop(ch) {
	var gameTiles = game.children;
	//calls gameLoop and converts Cstring to a Javascrpt String
	var getGame = UTF8ToString(__Z8gameLoopi(ch));
	//Splits string baised on Spaces put in when rendering
	var split = getGame.split(" ");
	var size = parseInt(split.length);
	for (var line in split) {
		for (var row in split[line]) {
			//setup parsing string to tiles	
			var tileid = ((line)*(size))+parseInt(row);
			gameTiles[tileid].setAttribute("class", "tile "+ chartoClass(split[line].charAt(row)));
		}
	}
	showMap();
}
function showMap() {
	var map = document.getElementById("map");
	var mapTiles = map.children;

	var getMap = UTF8ToString(__Z10getGameMapv());
	var rowIt = 5;

	for (var i = 0; i < 25; i++) {
		var currentRoom = document.getElementById("roomTile"+((rowIt)-i));
		currentRoom = currentRoom.children;
		if (i%5 == 4) rowIt += 10;
		for (var j = 0; j < 9; j++) {
			var tileType = chartoClass(getMap.charAt(i*9+j));
			currentRoom[j].setAttribute("class", "tile " + tileType); 
		}
	}
}
function chartoClass(char) {
	var className = "";
	//parse to check what is in that tile
	if (char == ".") { //OPEN
		className = "open";
	} else if (char == "#") { //WALL
		className = "wall";
	} else if (char == "=") { //DOOR
		className = "door";
	} else if (char == "M") { //MONSTER
		className = "mobs";
	} else if (char == "P") { //PLAYER
		className = "play";
	}
	return className;
}
