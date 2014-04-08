<?php
Class Vertex
{
	private $_x;
	private $_y;
	private $_z;
	private $_color;
	private $_w;
	public static $verbose = 0;
	public static function doc()
	{
		return file_get_contents("Vertex.doc.txt");
	}
	public function __construct(array $kwargs)
	{
		$this->_x = floatval($kwargs['x']);
		$this->_y = floatval($kwargs['y']);
		$this->_z = floatval($kwargs['z']);
		if (array_key_exists('w', $kwargs))
			$this->_w = floatval($kwargs['w']);
		else
			$this->_w = 1.0;
		if (array_key_exists('color', $kwargs))
			$this->_color = $kwargs['color'];
		else
			$this->_color = new Color( array('red' => 255, 'green' => 255, 'blue' => 255));
		if (self::$verbose)
			printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) ) constructed\n",$this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue);
		return;
	}
	public function getx() { return $this->_x; }
	public function gety() { return $this->_y; }
	public function getz() { return $this->_z; }
	public function getw() { return $this->_w; }
	public function getcolor() { return $this->_color; }
	public function setx($v) { $this->_x = $v; return; }
	public function sety($v) { $this->_y = $v; return; }
	public function setz($v) { $this->_z = $v; return; }
	public function setw($v) { $this->_w = $v; return; }
	public function setcolor($v) { $this->_color = $v; }
	public function __destruct()
	{
		if (self::$verbose)
			printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) ) destructed\n",$this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue);
		return;
	}
	public function __tostring()
	{
		if (!self::$verbose)
			return sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )",$this->_x, $this->_y, $this->_z, $this->_w);
		else
			return sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) )",$this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue);
	}
}
?>
