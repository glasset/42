#!/usr/bin/php
<?PHP

if ($argc != 2)
	exit;

$curl = curl_init($argv[1]);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
$web_str = curl_exec($curl);
$www = preg_replace("/http:\/\//", "", $argv[1]);
curl_close($curl);

preg_match("/<img\s*src=\"(.+)\" /", $web_str, $img_array);
unset($img_array[0]);
if (empty($img_array))
	exit;
mkdir($www);
foreach ($img_array as $img)
{
	$curl = curl_init($img);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
	$tmp_img = curl_exec($curl);
	curl_close($curl);
	$img = end(explode("/", $img));
	$fd = fopen($www."/".$img, 'w');
	fwrite($fd, $tmp_img);
	fclose($fd);
}

?>
