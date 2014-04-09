<?php
abstract Class Fighter
{
	public function __construct($kw)
	{
		$this->tmp = $kw;
	}
	public abstract function fight($target);
}
?>
