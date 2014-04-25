<?php
/**
 *
 *
 * CakePHP(tm) : Rapid Development Framework (http://cakephp.org)
 * Copyright (c) Cake Software Foundation, Inc. (http://cakefoundation.org)
 *
 * Licensed under The MIT License
 * For full copyright and license information, please see the LICENSE.txt
 * Redistributions of files must retain the above copyright notice.
 *
 * @copyright     Copyright (c) Cake Software Foundation, Inc. (http://cakefoundation.org)
 * @link          http://cakephp.org CakePHP(tm) Project
 * @package       app.View.Layouts
 * @since         CakePHP(tm) v 0.10.0.1076
 * @license       http://www.opensource.org/licenses/mit-license.php MIT License
 */

$cakeDescription = __d('My_web', 'Androdo: oid');
?>
<!DOCTYPE html>
<html>
<head>
	<?php echo $this->Html->charset(); ?>
	<title>
		<?php echo $cakeDescription ?>:
		<?php echo $title_for_layout; ?>
	</title>
	<?php
		echo $this->Html->meta('icon');

		echo $this->Html->css('cake.generic');

		echo $this->fetch('meta');
		echo $this->fetch('css');
		echo $this->fetch('script');
	?>
</head>
<body>
	<div id="container">
		<div id="header">
		<h1><?php echo $this->Html->image('home3.png'); echo $this->Html->link(' Home', '../index.php'); ?></h1>
		<h1><?php echo $this->Html->image('envelop.png'); echo $this->Html->link(' Forum', '../users/signup'); ?></h1>
		<h1><?php echo $this->Html->image('settings.png'); echo $this->Html->link(' My account', array('action'=>'edit', 'controller'=>'users')); ?></h1>
		<?php if(AuthComponent::user('id')): ?>
		<h1><?php echo $this->Html->image('switch.png'); echo $this->Html->link(' Logout', array('action'=>'logout', 'controller'=>'users')); ?></h1>
		<?php else: ?>
		<h1><?php echo $this->Html->image('enter.png'); echo $this->Html->link(' Sign up', array('action'=>'signup', 'controller'=>'users'));?></h1>
		<h1><?php echo $this->Html->image('switch.png'); echo $this->Html->link(' Login', array('action'=>'login', 'controller'=>'users')); ?></h1>
		<?php endif; ?>
		<?php if(AuthComponent::user('group_') == 'Admin'): ?>
		<h1><?php echo $this->Html->image('address-book.png'); echo $this->Html->link(' Members', array('action'=>'admin', 'controller'=>'users')); ?></h1>
		<?php endif; ?>
		</div>
		<div id="content">
			<?php echo $this->Session->flash(); ?>
			<?php echo $this->fetch('content'); ?>
		</div>
		<div id="footer">
			<?php echo $this->Html->link(
					$this->Html->image('cake.power.gif', array('alt' => $cakeDescription, 'border' => '0')),
					'http://www.cakephp.org/',
					array('target' => '_blank', 'escape' => false)
				);
			?>
		</div>
	</div>
	<?php //echo $this->element('sql_dump'); ?>
</body>
</html>
