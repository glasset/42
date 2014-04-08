<?
Class Color
{
	private $red = 0;
	private $green = 0;
	private $blue = 0;
	public static $verbose = 0;
	public function __construct(array $kwargs)
	{
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = intval(($kwargs['rgb'] >> 16) % 256);
			$this->green = intval(($kwargs['rgb'] >> 8) % 256);
			$this->blue = intval($kwargs['rgb'] % 256);
		}
		else
		{
			if (array_key_exists('red', $kwargs))
				$this->red = intval($kwargs['red']);
			if (array_key_exists('green', $kwargs))
				$this->green = intval($kwargs['green']);
			if (array_key_exists('blue', $kwargs))
				$this->blue = intval($kwargs['blue']);
		}
		if (self::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n",$this->red, $this->green, $this->blue);
		return;
	}
	public function add(Color $value)
	{
		return $new_color = new Color(array('red' => ($this->red + $value->red),
			'green' => ($this->green + $value->green),
			'blue' => ($this->blue + $value->blue)));
	}
	public function sub(Color $value)
	{
		return $new_color = new Color(array('red' => ($this->red - $value->red),
			'green' => ($this->green - $value->green),
			'blue' => ($this->blue - $value->blue)));
	}
	public function mult($value)
	{
		return $new_color = new Color(array('red' => ($this->red * $value),
			'green' => ($this->green * $value),
			'blue' => ($this->blue * $value)));
	}
	public function __destruct()
	{
		if (self::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n",$this->red, $this->green, $this->blue);
		return;
	}
	public function __tostring()
	{
		return sprintf('Color( red: %3d, green: %3d, blue: %3d )',$this->red, $this->green, $this->blue);
	}
	public static function doc()
	{
		return file_get_contents("Color.doc.txt");
	}
}
?>
