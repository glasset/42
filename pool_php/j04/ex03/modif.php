<?PHP
session_start();
$i = 0;
$X = 0;
if ($_POST["login"] !== "" && $_POST["oldpw"] !== "" && $_POST["newpw"] !== "")
{
	$pwd_ser = file_get_contents("../private/passwd");
	if ($pwd_ser)
	{
		$pwd_tab = unserialize($pwd_ser);
		foreach ($pwd_tab as $login => $currlog)
		{
			if ($currlog["login"] === $_POST["login"])
			{
				$i = 1;
				break;
			}
			$X++;
		}
	}
	$old_pw = hash("whirlpool", $_POST["oldpw"]);
	if ($old_pw == $currlog["passwd"] && $i == 1)
	{
		$new_pw = hash("whirlpool", $_POST["newpw"]);
		$pwd_tab[$X] = array("login" => $currlog["login"], "passwd" => $new_pw);
		file_put_contents("../private/passwd", serialize($pwd_tab));
		echo "OK\n";
	}
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
