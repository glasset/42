#!/usr/bin/php
<?PHP
$my_tb = array();
$x = 0;
for ($i = 1; $i < $argc; $i++)
{
	$string = trim($argv[$i], " ");
	$m_t = preg_split('/[\s]+/', $string);
	foreach($m_t as $elem)
		$my_tb[$x++] = $elem;
}
sort($my_tb);
foreach($my_tb as $elem)
	echo $elem."\n";
?>
