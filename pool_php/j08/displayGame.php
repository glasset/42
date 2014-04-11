<html>
<head>
<meta charset="utf-8">
<link href="style.css">
<title>W40K</title>
<body bgcolor="AAAAAA">

</head>

<body>
<div>
    <canvas id="my_canvas" width="1500" height="1000" style="border: 20px solid grey; background-image:url(stars.jpeg)">
	 Your broswer cant display html canvas. Sorry.
    </canvas>
</div>
	 <p><h2><?php session_start(); echo "Player: ".$_SESSION["turn"]." pv1 = ".$_SESSION["pv1"]." pv2 = ".$_SESSION["pv2"]; ?> </h2></ br></p>
<form id="move" method="POST" action="game.php">
	 Number of move: <input type="text" name="move" value=""/>
    <br />
	 Direction (N, S, E or W): <input type="text" name="direction" value=""/>
    <br />
    <input type="submit" name="submit_move" value="Move">
</form>
<form id="fire" method="POST" action="game.php">
    <input type="submit" name="submit_fire" value="Fire">
</form>
<form id="end" method="POST" action="game.php">
    <input type="submit" name="submit_end" value="End of turn">
</form>
</body>
</html>

<script language="javascript" type="text/javascript">
function drawShip(frontX, frontY, height, frontDir, color) {

	height = parseInt(height) * gridSize;
	//Compute Coordonate
	pen.beginPath();
	pen.fillStyle = "light"+color;
	if (frontDir == "S") {
		var backX = gridSize;
		var backY = height;
		var headX = parseInt(frontX) * gridSize;
		var headY = parseInt(frontY) * gridSize + (height - 10);
	}
	if (frontDir == "N") {
		var backX = gridSize;
		var backY = height;
		var headX = parseInt(frontX) * gridSize;
		var headY = parseInt(frontY) * gridSize;
	}
	if (frontDir == "W") {
		var backX = height;
		var backY = gridSize;
		var headX = parseInt(frontX) * gridSize;
		var headY = parseInt(frontY) * gridSize;
	}
	if (frontDir == "E") {
		var backX = height;
		var backY = gridSize;
		var headX = parseInt(frontX) * gridSize + (height - 10);
		var headY = parseInt(frontY) * gridSize;
	}
	//Draw Ship
	pen.fillRect(frontX * gridSize, frontY * gridSize, backX, backY);
	//Draw Head
	pen.fillStyle = color;
	pen.fillRect(headX, headY, gridSize, gridSize);	
	pen.fill();
}

board = document.getElementById("my_canvas");
pen = board.getContext("2d");
pen.lineWidth = 1;
gridSize = 10;
pen.strokeStyle = "black";
for (var h = gridSize; h < board.height; h += 10) {
	pen.moveTo(0, h);
	pen.lineTo(board.width, h);
}
for (var w = gridSize; w < board.width; w += 10) {
	pen.moveTo(w, 0);
	pen.lineTo(w, board.height);
}
pen.stroke();
drawShip(<?php echo $_SESSION["P1"]; ?>);
drawShip(<?php echo $_SESSION["P2"]; ?>);


</script>