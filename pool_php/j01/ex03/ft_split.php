<?PHP
function ft_split($str)
{
$string = $str;
$tmp = trim($string, " ");
$m_t = preg_split('/[\s]+/', $tmp);
print_r($m_t);
}
?>
