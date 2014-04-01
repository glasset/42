<?PHP
function ft_is_sort($my_tb)
{
	$i = 0;
	$x = 0;
	$cro = $my_tb;
	$dec = $my_tb;
	asort($cro);
	$cro = array_values($cro);
	arsort($dec);
	$dec = array_values($dec);
	while($cro[$i])
	{
		if (!strcmp($cro[$i], $my_tb[$i]))
			$x++;
		$i++;
	}
	if ($i == $x)
		return (TRUE);
	$i = 0;
	$x = 0;
	while($dec[$i])
	{
		if (!strcmp($dec[$i], $my_tb[$i]))
			$x++;
		$i++;
	}
	if ($i == $x)
		return (TRUE);
	return (FALSE);
}
?>
