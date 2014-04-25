<?php
class User extends AppModel{
	var $name = 'User';
	public $validate = array(
		'username' =>array(
			array('rule' => 'alphanumeric',
			'required' => true,
			'allowEmpty' => false,
			'message' => "Login invalide"),
			array(
				'rule' => 'isUnique',
				'message' => "Login deja pris")
			),
		'mail' =>array(
			array('rule' => 'email',
			'required' => true,
			'allowEmpty' => false,
			'message' => "email invalide"),
			array(
				'rule' => 'isUnique',
				'message' => "email deja pris")
			),
		'password' =>array(
			'rule' => 'notEmpty',
			'message' => "need password",
			'allowEmpty' => false)
		);
}
?>
