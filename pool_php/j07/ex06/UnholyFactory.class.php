<?php
Class UnholyFactory
{
	public $tmp = array();
	public function absorb($k)
	{
		if (is_subclass_of($k, 'Fighter'))
		{
			if (!array_key_exists($k->tmp, $this->tmp))
			{
				print "(Factory absorbed a fighter of type ".$k->tmp.")\n";
				$this->tmp[$k->tmp] = $k->tmp;
			}
			else
				print "(Factory already absorbed a fighter of type foot soldier)\n";
		}
		else
			print "(Factory can't absorb this, it's not a fighter)\n";
	}
	public function fabricate($k)
	{
		if (array_key_exists($k,$this->tmp))
			print "(Factory fabricates a fighter of type $k)\n";
		else
			print "(Factory hasn't absorbed any fighter of type $k)\n";
		return ("Footsoldier");
	}
}
?>
