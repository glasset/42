<?PHP
$all_v = $_SERVER['QUERY_STRING'];
$ex = split("\&", $all_v);
foreach($ex as $elem)
{
	$tmp = split("=", $elem);
	echo $tmp[0].": ".$tmp[1]."\n";
}
?>
