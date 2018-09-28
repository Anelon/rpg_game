var playerLocation = 0;
var directionFacing = "up";
var game = document.getElementById("game");
var map = document.getElementById("map");
var start = document.getElementById("start");
var lore = document.getElementById("lore");
var bar = document.getElementById("bar");
var lyricDiv = document.getElementById("lyric");
var lyricDivText = document.getElementById("lyricText");
var loreSubText = document.createElement("p");
loreSubText.innerHTML = "Press Enter to Continue";
const faceUp = "faceUp";
const faceDown = "faceDown";
const faceLeft = "faceLeft";
const faceRight = "faceRight";
//charCodes
var up = 119;
var down = 115;
var left = 97;
var right = 100;
var pauseKey = 69;
var interact = 32;
var pause = true;
var hasSuica = false;
var gameOver = false;

var dialogues = [
	"Go to the top",
	"Gl HF",
	"Sorry, No speak English",
	"What is your favorite color?",
	"I have this song stuck in my head, it goes like:</br>'You know how people always say</br>Seize the moment</br>I dont know im kindof thinking its the other way around,</br>Like the moment seizes us'",
	"42"
];
var lyricPuzzle = [
	"Hello there, you look a little lost</br>Oh, I see your missing your Suica card</br>I can give you mine, but only if you help me first</br>",
	"You see, I have this song stuck in my head but I am missing one word: </br>'You know how people always say</br><input type='text' name='lyricSolution' id='lyricSolution'><button onclick='checkAnswer()'>Check</button></br>I dont know I'm kind of thinking.</br> It's the other way around,</br>Like the moment seizes us'",
	"Thanks so much for all of your help here is my Suica Card,</br> it should have enough to get you where you need to go",
	"Head to the train on the other end of the station from here."
];
var lyricPuzzlePart = 0;

var input = 0;
var depression = 15;

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
	showBar();

	document.addEventListener("keypress", function () {
		input = event.key.charCodeAt(0);
		console.log(input);
		if(input === pauseKey && !gameOver) {
			pause = !pause;
			if(!pause) lore.innerHTML = "";
			else showDialog("Paused");
			if(lyricDiv.style.display === "block") {
				lyricDiv.style.display = "none";
			}
		}
		//runGameLoop(event.key.charCodeAt(0));
	});
};

function runGameLoop() {
	//console.log(input);
	if(pause) {
		setTimeout(runGameLoop, 1000);
		return;
	}
	if(input != interact) {
		//change the directionFacing of the player
		if(input === up) directionFacing = faceUp;
		else if (input === down) directionFacing = faceDown;
		else if (input === left) directionFacing = faceLeft;
		else if (input === right) directionFacing = faceRight;
		var gameTiles = game.children;
		//calls gameLoop and converts Cstring to a Javascrpt String
		var getGame = UTF8ToString(__Z8gameLoopi(input));
		console.log(getGame);
		//Splits string baised on Spaces put in when rendering
		var split = getGame.split(" ");
		var size = parseInt(split.length);
		for (var line in split) {
			for (var row in split[line]) {
				//setup parsing string to tiles	
				var tileid = ((line)*(size))+parseInt(row);
				if(split[line].charAt(row) === "P") {
					playerLocation = tileid;
				}
				gameTiles[tileid].setAttribute("class", "tile "+ chartoClass(split[line].charAt(row)));
			}
		}
		showMap();
	} else if(input === interact) {
		var foundMob = false;
		var gameTiles = game.children;
		//calculate target baised on looking
		if(directionFacing === faceUp) var target = playerLocation - 16;
		if(directionFacing === faceDown) var target = playerLocation + 16;
		if(directionFacing === faceLeft) var target = playerLocation - 1;
		if(directionFacing === faceRight) var target = playerLocation + 1;

		if(gameTiles[target].classList.contains("mobs")) {
			showDialog(dialogues[Math.floor(Math.random() * dialogues.length)]);
			foundMob = true;
		} else if(gameTiles[target].classList.contains("boss")) {
			showLyricPuzzle();//open lyricPuzzle
			foundMob = true;
		} else if(gameTiles[target].classList.contains("goal")) {
			if(hasSuica) {
				lore.innerHTML = "<h2>Congrats!</br>You made it to your train</br>Thanks for playing.</br>Now go find your friend and try not to get seperated next time.</h2>";
				gameOver = true;
			} else {
				lore.innerHTML = "<h2>You need a Suica Card to get to the train</h2>";
			}
			foundMob = true;
		}
		if(foundMob) {
			//console.log("interact");//playerLocation check around for mobs
			pause = true;
			depression--;
			showBar();
		}
	}
	input = 0;//reset input to stop from walking
	setTimeout(runGameLoop, 100);
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
	} else if (char >= "0" && char <= "9") { //MONSTER
		className = "mobs";
	} else if (char == "P") { //PLAYER
		className = "play " + directionFacing;
	} else if (char == "~") { //LOCKED DOOR
		className = "locked";
	} else if (char == "$") { //PLACK
		className = "plack";
	} else if (char == "G") { //Goal
		className = "goal";
	} else if (char == "B") { //Helpful Squid
		className = "boss";
	}
	return className;
}
function showBar() {
	bar.innerHTML = "";
	if(depression === 10) {
		lore.innerHTML = "<h2>You're starting to loose hope at ever finding your friend</h2>";
	}
	if(depression) {
		for (var i = 0; i < depression; i++) {
			var barBlock = document.createElement("div");
			barBlock.setAttribute("class","barBlock");
			bar.appendChild(barBlock);
		}
	} else {
		gameOver = true;
		lore.innerHTML = "<h2>You loose hope at ever finding</br>your way back to your friend.</br>Game Over.</h2>";
	}
}
function showLyricPuzzle() {
	lyricDivText.innerHTML = lyricPuzzle[lyricPuzzlePart];
	if(lyricPuzzlePart === 0) lyricPuzzlePart++;
	lyricDiv.style.display = "block";
}
function checkAnswer() {
	var lyricSolution = document.getElementById("lyricSolution");
	//console.log("checking answer");
	//console.log(lyricSolution.value.toUpperCase());
	if(lyricSolution) {
		if(lyricSolution.value.toUpperCase() === "SEIZE THE MOMENT") {
			//console.log("solved");
			lyricPuzzlePart++;
			lyricDivText.innerHTML = lyricPuzzle[lyricPuzzlePart];
			hasSuica = true;
			lyricPuzzlePart++;
		}
	}
}
function showDialog(text) {
	loreText = document.createElement("h3"); //create element and put text into it
	//loreText.innerHTML = dialogues[Math.floor(Math.random() * dialogues.length)];
	loreText.innerHTML = text;
	lore.appendChild(loreText); 
	lore.appendChild(loreSubText);
}
