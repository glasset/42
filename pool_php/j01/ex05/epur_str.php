#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$string = trim($argv[1], " ");
	$m_t = preg_split('/[\s]+/', $string);
	foreach($m_t as $elem)
		echo $elem." ";
	echo "\n";
}
?>
