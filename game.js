var game = document.getElementById("game");
for (var i = 0; i < 16; i++) {
	for (var j = 0; j < 16; j++) {
		var tile = document.createElement("div");
		tile.setAttribute("class", "tile");
		tile.setAttribute("id", "tile"+(i*16+j));
		game.appendChild(tile);
		console.log(i*16+j);
	}
}
document.addEventListener("keypress", function () {
	var temp = event;
	console.log(event.key.charCodeAt(0));
	runGameLoop(event.key.charCodeAt(0));
});

function runGameLoop(ch) {
	var gameTiles = game.children;
	//calls gameLoop and converts Cstring to a Javascrpt String
	var test = UTF8ToString(__Z8gameLoopi(ch));
	//Splits string baised on Spaces put in when rendering
	var split = test.split(" ");
	var size = split.length;
	//for each in split paste string then <br>
	for (var line in split) {
		//game.innerHTML += split[line] + "<br>";
		for (var row in split[line]) {
			//setup parsing string to tiles	
			var tileid = ((line-1)*16)+parseInt(row);
			console.log((line-1) + " " + row + " " + tileid);

			//parse to check what is in that tile
			if (split[line].charAt(row) == ".") { //OPEN
				gameTiles[tileid].setAttribute("class", "tile open");
			} else if (split[line].charAt(row) == "#") { //WALL
				gameTiles[tileid].setAttribute("class", "tile wall");
			} else if (split[line].charAt(row) == "=") { //DOOR
				gameTiles[tileid].setAttribute("class", "tile door");
			} else if (split[line].charAt(row) == "M") { //MONSTER
				gameTiles[tileid].setAttribute("class", "tile door");
			} else if (split[line].charAt(row) == "P") { //PLAYER
				gameTiles[tileid].setAttribute("class", "tile door");
			}



		}
	}
 }
