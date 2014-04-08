<?php
Class Vector
{
	private $_dest;
	private $_orig;
	private $_x;
	private $_y;
	private $_z;
	private $_w;
	public static $verbose = 0;
	public static function doc()
	{
		return file_get_contents("Vector.doc.txt");
	}
	public function __construct(array $kwargs)
	{
		$this->_dest = $kwargs['dest'];
		if (array_key_exists('orig', $kwargs))
			$this->_orig = $kwargs['orig'];
		else
			$this->_orig = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0 ) );
		$this->_x = $this->_dest->getx() - $this->_orig->getx();
		$this->_y = $this->_dest->gety() - $this->_orig->gety();
		$this->_z = $this->_dest->getz() - $this->_orig->getz();
		$this->_w = 0.0;
		if (self::$verbose)
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) constructed\n",$this->_x, $this->_y, $this->_z, $this->_w);
		return;
	}
	public function getvx() { return $this->_x; }
	public function getvy() { return $this->_y; }
	public function getvz() { return $this->_z; }
	public function getvw() { return $this->_w; }
	public function __destruct()
	{
		if (self::$verbose)
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) destructed\n",$this->_x, $this->_y, $this->_z, $this->_w);
		return;
	}
	public function __tostring()
	{
		return sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )",$this->_x, $this->_y, $this->_z, $this->_w);
	}
	public function magnitude()
	{
		return sqrt(pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2));
	}
	public function normalize()
	{
		$tmp = $this->magnitude();
		$vtmp = new Vertex( array('x' => ($this->_x / $tmp), 'y' => ($this->_y / $tmp), 'z' => ($this->_z / $tmp)));
		$vnew = new Vector( array ( 'dest' => $vtmp));
		return $vnew;
	}
	public function add($rhs)
	{
		$vtmp = new Vertex( array('x' => ($this->_x + $rhs->_x), 'y' => ($this->_y + $rhs->_y), 'z' => ($this->_z + $rhs->_z)));
		$vnew = new Vector( array ( 'dest' => $vtmp));
		return $vnew;
	}
	public function sub($rhs)
	{
		$vtmp = new Vertex( array('x' => ($this->_x - $rhs->_x), 'y' => ($this->_y - $rhs->_y), 'z' => ($this->_z - $rhs->_z)));
		$vnew = new Vector( array ( 'dest' => $vtmp));
		return $vnew;
	}
	public function opposite()
	{
		$vtmp = new Vertex( array('x' => ($this->_x / -1), 'y' => ($this->_y / -1), 'z' => ($this->_z / -1)));
		$vnew = new Vector( array ( 'dest' => $vtmp));
		return $vnew;
	}
	public function scalarProduct($k)
	{
		$vtmp = new Vertex( array('x' => ($this->_x * $k), 'y' => ($this->_y * $k), 'z' => ($this->_z * $k)));
		$vnew = new Vector( array ( 'dest' => $vtmp));
		return $vnew;
	}
	public function dotProduct($rhs)
	{
		return sprintf($this->_x * $rhs->_x + $this->_y * $rhs->_y + $this->_z * $rhs->_z);
	}
	public function crossProduct($rhs)
	{
		$vtmp = new Vertex( array('x' => ($this->_y * $rhs->_z - $this->_z * $rhs->_y), 'y' => ($this->_z * $rhs->_x - $this->_x * $rhs->_z), 'z' => ($this->_x * $rhs->_y - $this->_y * $rhs->_x)));
		$vnew = new Vector( array ( 'dest' => $vtmp));
		return $vnew;
	}
	public function cos($rhs)
	{
		return $this->dotProduct($rhs) / ($this->magnitude() *
			sqrt(pow($rhs->_x, 2) + pow($rhs->_y, 2) + pow($rhs->_z, 2)));
	}
}
?>
