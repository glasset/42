<?php
session_start();
require_once "Crusader.class.php";

if (isset($_POST["submit_start"]))
{
	$_SESSION["ship1"] = serialize(new Crusader(array('name' => 'BADRAINBOW', 'size' => 6, "coordX" => 50, "coordY" => 50, "dir" => "S", "color" => "blue")));
	$_SESSION["ship2"] = serialize(new Crusader(array('name' => 'DARKMOM', 'size' => 6, "coordX" => 50, "coordY" => 64, "dir" => "N", "color" => "green")));
	$_SESSION["P1"] = "50, 50, 6, \"S\", \"blue\"";
	$_SESSION["P2"] = "50, 64, 6, \"N\", \"green\"";
	header("Location: displayGame.php");
	$_SESSION["turn"] = 1;
	$_SESSION["pv1"] = 10;
	$_SESSION["pv2"] = 10;
}
else if (strlen($_POST["move"]))
{
	if ($_SESSION["move"] > 20 || $_SESSION["move"] < 0)
		break;
	if ($_SESSION["turn"] == 1)
	{
		$ship1 = unserialize($_SESSION["ship1"]);
		$ship1->changeCoord($_POST["move"], strtoupper($_POST["direction"]));
		$_SESSION["P1"] = $ship1->__toString();	
		$_SESSION["ship1"] = serialize($ship1);
	}
	else
	{
		$ship2 = unserialize($_SESSION["ship2"]);
		$ship2->changeCoord($_POST["move"], strtoupper($_POST["direction"]));
		$_SESSION["P2"] = $ship2->__toString();	
		$_SESSION["ship2"] = serialize($ship2);
	}
}
else if ($_POST["submit_fire"] == "Fire")
{
	$tmpship1 = unserialize($_SESSION["ship1"]);
	$tmpship2 = unserialize($_SESSION["ship2"]);
	$tmpship1 = $tmpship1->getCoord();
	$tmpship2 = $tmpship2->getCoord();
	if ($_SESSION["turn"] == 1)
	{
		if ($tmpship1['x'] == $tmpship2['x'])
		{
			if ($tmpship2['y'] > $tmpship1['y'] && $tmpship1['dir'] == "S")
				$_SESSION["pv2"] -= 1;
			else if ($tmpship2['y'] < $tmpship1['y'] && $tmpship1['dir'] == "N")
				$_SESSION["pv2"] -= 1;
		}
		if ($tmpship1['y'] == $tmpship2['y'])
		{
			if ($tmpship2['x'] > $tmpship1['x'] && $tmpship1['dir'] == "E")
				$_SESSION["pv2"] -= 1;
			else if ($tmpship2['x'] < $tmpship1['x'] && $tmpship1['dir'] == "W")
				$_SESSION["pv2"] -= 1;
		}
		$_SESSION["turn"] = 2;
	}
	else if ($_SESSION["turn"] == 2)
	{
		if ($tmpship1['x'] == $tmpship2['x'])
		{
			if ($tmpship1['y'] > $tmpship2['y'] && $tmpship2['dir'] == "S")
				$_SESSION["pv1"] -= 1;
			else if ($tmpship1['y'] < $tmpship2['y'] && $tmpship2['dir'] == "N")
				$_SESSION["pv1"] -= 1;
		}
		if ($tmpship1['y'] == $tmpship2['y'])
		{
			if ($tmpship1['x'] > $tmpship2['x'] && $tmpship2['dir'] == "E")
				$_SESSION["pv1"] -= 1;
			else if ($tmpship1['x'] < $tmpship2['x'] && $tmpship2['dir'] == "W")
				$_SESSION["pv1"] -= 1;
		}
		$_SESSION["turn"] = 1;
	}
	if ($_SESSION["pv1"] == 0 OR $_SESSION["pv2"] == 0)
	{
		header("Location: endGame.php");
		break;
	}
}
else if (isset($_POST["submit_end"]))
{
	if ($_SESSION["turn"] == 1)
		$_SESSION["turn"] = 2;
	else
		$_SESSION["turn"] = 1;
}
header("Location: displayGame.php");

?>