<?PHP
$ac = $_GET["action"];
if ($ac === "set")
	setcookie($_GET["name"], $_GET["value"], time()+3600);
if ($ac === "get")
{
	$tmp = $_COOKIE[$_GET["name"]];
	if ($tmp)
		echo $_COOKIE[$_GET["name"]]."\n";
}
if ($ac === "del")
	setcookie($_GET["name"], null, -1);
?>
