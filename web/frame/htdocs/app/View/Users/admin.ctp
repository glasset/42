<?php echo $this->Html->image('accessibility.png'); echo $this->Html->link(' Add user', array('action'=>'add', 'controller'=>'users')); ?>
<center>
<h1>Users Data</h1>
</center>
<table>
<tbody><tr>
<th>Id</th>
<th>Login</th>
<th>E-mail</th>
<th>Pass</th>
<th>Group</th>
<th>Actions</th>
</tr>
    <?php foreach ($users as $user): ?>
<tr>
<td><?php echo $user['User']['id']; ?></td>
<td><?php echo $user['User']['username']; ?></td>
<td><?php echo $user['User']['mail']; ?></td>
<td><?php echo $user['User']['password']; ?></td>
<td><?php echo $user['User']['group_']; ?></td>
<td>
<?php echo $this->Html->link('Edit', array('action'=>'editad', $user['User']['id']));?> |
<?php echo $this->Html->link('Delete', array('action' => 'delete', $user['User']['id']), null, 'Are you sure?' )?>
</td>
</tr>
    <?php endforeach; ?>
</tbody></table> 
