<?php
Class Tyrion extends Lannister
{
	public function sleepWith($t)
	{
		if (is_a($t, 'Jaime'))
			print "Not even if I'm drunk !\n";
		if (is_a($t, 'Sansa'))
			print "Let's do this.\n";
		if (is_a($t, 'Cersei'))
			print "Not even if I'm drunk !\n";
	}
}
?>
