<?php
require_once "Ship.class.php"

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
			$this->_coordX += $move;
		if ($direction == "S")
			$this->_coordX -= $move;
		if ($direction == "E")
			$this->_coordY -= $move;
		if ($direction == "W")
			$this->_coordY += $move;
		$this->dir = $direction;
	}
}

?>