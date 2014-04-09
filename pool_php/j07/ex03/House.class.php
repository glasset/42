<?php
Class House
{
	protected $tmp;
	public function __construct()
	{
		$this->tmp = ("House ".static::getHouseName()." of ".static::getHouseSeat()." : \"".static::getHouseMotto()."\"\n");
	}
	public function introduce()
	{
		print $this->tmp;
	}
}
?>
