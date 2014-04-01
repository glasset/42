#!/usr/bin/php
<?PHP
if ($argc == 4)
{
	$nb = trim($argv[2]);
	if(!is_numeric(trim($argv[1])))
	{
		echo "Incorrect Parameters\n";
		break;
	}
	if(!is_numeric(trim($argv[3])))
	{
		echo "Incorrect Parameters\n";
		break;
	}
	$nb = ord($nb);
	if ($nb == 43)
		echo $argv[1] + $argv[3]."\n";
	else if ($nb == 45)
		echo $argv[1] - $argv[3]."\n";
	else if ($nb == 42)
		echo $argv[1] * $argv[3]."\n";
	else if ($nb == 47)
		echo $argv[1] / $argv[3]."\n";
	else if ($nb == 37)
		echo $argv[1] % $argv[3]."\n";
	else
		echo "Incorrect Parameters\n";
}
else
	echo "Incorrect Parameters\n";
?>
