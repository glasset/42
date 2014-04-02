#!/usr/bin/php
<?PHP

if ($argc < 2)
	exit;

function max_case($str)
{
	$str[0] = preg_replace("/$str[1]/", strtoupper($str[1]), $str[0]);
	return ($str[0]);
}

$fd = fopen("$argv[1]", "r");
$str_file = file_get_contents("$argv[1]");
$test = preg_replace_callback("/title=\"(.+)\"/U", "max_case", $str_file);
$test = preg_replace_callback("/<a.*>(.+)</U", "max_case", $test);

echo $test;

?>
