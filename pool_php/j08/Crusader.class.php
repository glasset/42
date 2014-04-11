<?php
require_once "Ship.class.php";

class Crusader extends Ship {

	public function __construct(array $kwargs) {

		$this->_name = $kwargs['name'];
		$this->_size = intval($kwargs['size']);
		$this->_coordX = $kwargs['coordX'];
		$this->_coordY = $kwargs['coordY'];
		$this->_dir = $kwargs['dir'];
		$this->_color = $kwargs['color'];

	}
	public function changeCoord($move, $direction) {
		if ($direction == "N")
		{
			$this->_coordY -= $move;
			if ($this->_dir == "E")
				$this->_coordX += $this->_size - 1;
		}
		if ($direction == "S")
		{
			$this->_coordY += $move;
			if ($this->_dir == "E")
			{
				$this->_coordY -= $this->_size - 1;
				$this->_coordX += $this->_size - 1;
			}
		}
		if ($direction == "E")
		{
			$this->_coordX += $move;
			if ($this->_dir == "S")
			{
				$this->_coordX -= $this->_size - 1;
				$this->_coordY += $this->_size - 1;
			}
		}
		if ($direction == "W")
		{
			$this->_coordX -= $move;
			if ($this->_dir == "S")
				$this->_coordY += $this->_size - 1;
		}
		$this->_dir = $direction;
	}

	public function getCoord() {
		return array("x" => $this->_coordX, 'y' => $this->_coordY, 'dir' => $this->_dir);
	}

	public function __toString() {
        return sprintf("%d, %d, %d, \"%s\", \"%s\"",
                       $this->_coordX, $this->_coordY, $this->_size, $this->_dir, $this->_color);
	}
}

?>