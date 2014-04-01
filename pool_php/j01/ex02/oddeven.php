#!/usr/bin/php
<?PHP
$i = 1;
$fd = fopen('php://stdin', 'r');
while ($i)
{
	echo "Entrez un nombre: ";
	$fd = fopen('php://stdin', 'r');
	$line = trim(fgets($fd, 1024));
	if (feof($fd))
		$i = 0;
	else
	{
		$line = trim($line, " ");
		preg_match("/([^0-9-])/", $line, $result);
		if (!empty($result))
		{
			echo "'$line' n'est pas un chiffre\n";
		}
		else
		{
			if (($line % 2) == 0)
				echo "Le chiffre $line est pair\n";
			else
				echo "Le chiffre $line est impair\n";
		}
	}
}
echo "\n";
?>
