var game = document.getElementById("game");
var start = document.getElementById("start");
//runGameLoop(" ");
start.addEventListener("click", function () {
	console.log("start");
	game.innerHTML = "";
	for (var i = 0; i < 16; i++) {
		for (var j = 0; j < 16; j++) {
			var tile = document.createElement("div");
			tile.setAttribute("class", "tile");
			tile.setAttribute("id", "tile"+(i*16+j));
			game.appendChild(tile);
		}
	}
	document.addEventListener("keypress", function () {
		runGameLoop(event.key.charCodeAt(0));
	});
	runGameLoop(" ");
});

function runGameLoop(ch) {
	var gameTiles = game.children;
	//calls gameLoop and converts Cstring to a Javascrpt String
	var getGame = UTF8ToString(__Z8gameLoopi(ch));
	//Splits string baised on Spaces put in when rendering
	getGame = getGame.split("  ");
	var tiles = getGame[0];
	var map = getGame[1];
	var split = tiles.split(" ");
	var size = parseInt(split.length);
	//for each in split paste string then <br>
	for (var line in split) {
		//game.innerHTML += split[line] + "<br>";
		for (var row in split[line]) {
			//setup parsing string to tiles	
			var tileid = ((line)*(size))+parseInt(row);

			//parse to check what is in that tile
			if (split[line].charAt(row) == ".") { //OPEN
				gameTiles[tileid].setAttribute("class", "tile open");
			} else if (split[line].charAt(row) == "#") { //WALL
				gameTiles[tileid].setAttribute("class", "tile wall");
			} else if (split[line].charAt(row) == "=") { //DOOR
				gameTiles[tileid].setAttribute("class", "tile door");
			} else if (split[line].charAt(row) == "M") { //MONSTER
				gameTiles[tileid].setAttribute("class", "tile mobs");
			} else if (split[line].charAt(row) == "P") { //PLAYER
				gameTiles[tileid].setAttribute("class", "tile play");
			}

		}
	}
	showMap();
}
function showMap() {
}
