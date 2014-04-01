#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	$i = 1;
	$string = trim($argv[1], " ");
	$m_t = preg_split('/[\s]+/', $string);
	while($m_t[$i])
	{
		echo $m_t[$i]." ";
		$i++;
	}
	echo $m_t[0]."\n";
}
?>
