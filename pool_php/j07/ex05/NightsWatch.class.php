<?php
Class NightsWatch implements IFighter
{
	public function fight()
	{
	}
	public function recruit($name)
	{
		if (is_subclass_of($name, 'IFighter'))
			$name->fight();
	}
}
?>
