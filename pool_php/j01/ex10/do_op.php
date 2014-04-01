#!/usr/bin/php
<?PHP
if ($argc == 4)
{
	$nb = trim($argv[2]);
	$nb = ord($nb);
	if ($nb == 43)
		echo $argv[1] + $argv[3]."\n";
	else if ($nb == 45)
		echo $argv[1] - $argv[3]."\n";
	else if ($nb == 100)
		echo $argv[1] * $argv[3]."\n";
	else if ($nb == 47)
		echo $argv[1] / $argv[3]."\n";
	else if ($nb == 37)
		echo $argv[1] % $argv[3]."\n";
}
else
	echo "Incorrect Parameters\n";
?>
