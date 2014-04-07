<?PHP
$i = 0;
mkdir("../private");
if ($_POST["login"] !== "" && $_POST["passwd"] !== "")
{
	$pwd_ser = file_get_contents("../private/passwd");
	if ($pwd_ser)
	{
		$pwd_tab = unserialize($pwd_ser);
		foreach ($pwd_tab as $login => $currlog)
		{
			if ($currlog['login'] === $_POST["login"])
			{
				echo "ERROR\n";
				$i = 1;
			}
		}
	}
	if ($i == 1)
		break;
	$pwd_hash = hash("whirlpool", $_POST["passwd"]);
	$pwd_tab[] = array("login" => $_POST["login"], "passwd" => $pwd_hash);
	file_put_contents("../private/passwd", serialize($pwd_tab));
	echo "OK\n";
}
else
	echo "ERROR\n";
?>
