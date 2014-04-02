#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	if(date_default_timezone_set('Europe/Paris') == 0)
		date_default_timezone_set('UTC');
	$pat_day = array("[Ll]undi", "[Mm]ardi", "[Mm]ercredi", "[Jj]eudi", "[Vv]endredi", "[Ss]amedi", "[Dd]imanche");
	$pat_month = array("[Jj]anvier", "[Ff]evrier", "[Mm]ars", "[Aa]vril", "[Mm]ai", "[Jj]uin", "[Jj]uillet", "[Aa]out", "[Ss]eptembre", "[Oo]ctobre", "[Nn]ovembre", "[Dd]ecembre");
	$m_t = preg_split('/[\s]+/', $argv[1]);
	foreach($pat_day as $day)
	{
		$nb = preg_match("/$day/", $m_t[0]);
		if ($nb == 1)
			break;
	}
	if (!$nb)
	{
		echo "Wrong Format\n";
		exit;
	}
	$i = 0;
	while ($i < 12)
	{
		$nb = preg_match("/$pat_month[$i]/", $m_t[2]);
		if ($nb)
			break;
		$i++;
	}
	if (!$nb)
	{
		echo "Wrong Format\n";
		exit;
	}
	if (!is_numeric($m_t[1]) || (($m_t[1] < 0) || ($m_t[1] > 99)))
	{
		echo "Wrong Format\n";
		exit;
	}
	if (!is_numeric($m_t[3]) || (($m_t[3] < 1000) || ($m_t[3] > 9999)))
	{
		echo "Wrong Format\n";
		exit;
	}
	$i++;
	if (checkdate($i, $m_t[1], $m_t[3]))
		echo strtotime($m_t[3]."-".$i."-".$m_t[1]."T".$m_t[4]), "\n";
	else
		echo "Wrong Format\n";
}
?>
