<?php
Class Jaime extends Lannister
{
	public function sleepWith($t)
	{
		if (is_a($t, 'Tyrion'))
			print "Not even if I'm drunk !\n";
		if (is_a($t, 'Sansa'))
			print "Let's do this.\n";
		if (is_a($t, 'Cersei'))
			print "With pleasure, but only in a tower in Winterfell, then.\n";
	}

}
?>
