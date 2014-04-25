<h1>Add New User</h1>
<?php
echo $this->Form->create('User');
echo $this->Form->input('username');
echo $this->Form->input('mail');
echo $this->Form->input('password');
echo $this->Form->input('group');
echo $this->Form->end('Save New User');
?>
