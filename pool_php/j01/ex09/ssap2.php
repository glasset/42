#!/usr/bin/php
<?PHP
for ($i = 1; $i < $argc; $i++)
{
	$string = trim($argv[$i], " ");
	$m_t = preg_split('/[\s]+/', $string);
	foreach($m_t as $elem)
	{
		$asc = ord($elem);
		if (is_numeric($elem))
			$my_num[] = $elem;
		else if ($asc < 65 || $asc > 90 && $asc < 97)
			$my_uk[] = $elem;
		else
			$my_tb[] = $elem;
	}
}
natcasesort($my_tb);
foreach($my_tb as $elem)
	echo $elem."\n";
sort($my_num, SORT_STRING);
foreach($my_num as $elem)
	echo $elem."\n";
sort($my_uk);
foreach($my_uk as $elem)
	echo $elem."\n";
?>
