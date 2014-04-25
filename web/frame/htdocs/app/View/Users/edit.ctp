<?php echo $this->Form->create('User'); ?>
<?php echo $this->Form->input('username', array('label'=>"login: ")); ?>
<?php echo $this->Form->input('mail', array('label'=>"e-mail: ")); ?>
<?php echo $this->Form->input('pass1', array('type' =>'password','label'=>"new password: ")); ?>
<?php echo $this->Form->input('pass2', array('type'=>'password', 'label'=>"confirm password: ")); ?>
<?php echo $this->Form->end("Modifier"); ?>
