var game = document.getElementById("game");
document.addEventListener("keypress", function () {
	var temp = event;
	console.log(event.key.charCodeAt(0));
	runGameLoop(event.key.charCodeAt(0));
});
function runGameLoop(ch) {
	//calls gameLoop and converts Cstring to a Javascrpt String
	var test = UTF8ToString(__Z8gameLoopi(ch));
	//Splits string baised on Spaces put in when rendering
	var split = test.split(" ");
	//for each in split paste string then <br>
	game.innerHTML = "";
	for (var line in split) {
		game.innerHTML += split[line] + "<br>";
	}
 }
