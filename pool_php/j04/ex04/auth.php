<?PHP
function auth($login, $passwd)
{
	$pwd_ser = file_get_contents("../private/passwd");
	if ($login !== "" && $passwd !== "" && $pwd_ser)
	{
		$pwd_tab = unserialize($pwd_ser);
		$hash_pw = hash("whirlpool", $passwd);
		foreach ($pwd_tab as $log => $currlog)
		{
			if ($currlog["login"] === $login && $hash_pw == $currlog["passwd"])
				return TRUE;
		}
	}
	return FALSE;
}
?>
