<?PHP
header('WWW-Autenticate: Basic realm=\'\'Espace membres\'\'');
header('HTTP/1.0 401 Unauthorized');
$log = "zaz";
$pwd = "jaimelespetitsponeys";
$cl = $_SERVER['PHP_AUTH_USER'];
$cp = $_SERVER['PHP_AUTH_PW'];
if ($log === $cl && $pwd === $cp)
{
	echo "<html><body>\nBonjour Zaz"."<br />\n";
	$read = file_get_contents("../img/42.png");
	echo "<img src= 'data:image/png;base64,".base64_encode($read)."'>\n</body></html>\n";
}
else
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>"."\n";
?>
