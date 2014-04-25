<h1>Edit User</h1>
<?php
    echo $this->Form->create('User', array('action' => 'editad'));
    echo $this->Form->input('id', array('type'=>'hidden'));
    echo $this->Form->input('username');
    echo $this->Form->input('mail');
    echo $this->Form->input('group');
    echo $this->Form->end('Update User');
?> 
