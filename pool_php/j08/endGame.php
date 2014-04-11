<html>
<head>
<meta charset="utf-8">
<link href="style.css">
<title>W40K</title>
<body bgcolor="444444">

</head>

<body>
<div><center><h1>Welcome to battle</h1><div>
<hr />
<form id="start" method="POST" action="game.php">
	
    <input type="submit" name="submit_start" value="Start Game">
</form>
</ br>
	 <h1><?php session_start(); if($_SESSION["pv1"] == 0) {echo "Player 2 win !";} if($_SESSION["pv2"] == 0) {echo "Player 1 win !";} ?></h1>
</center>
</body>
</html>
