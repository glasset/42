<?php

class Ship {

	protected $_name;
	protected $_size;
	static protected $_coordX;
	static protected $_coordY;
	static protected $_dir;
	protected $color;
	protected $_life = 2;
	protected $_move = 10;
	
	public function __toString() {
		return sprintf("%d, %d, %d, \"%c\", \"%s\"",
					   $this->_coordX, $this->_coordY, $this->_size, $this->_dir, $this->_color);
	}
}

?>