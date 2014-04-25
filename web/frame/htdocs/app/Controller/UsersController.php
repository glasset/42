<?php
class UsersController extends AppController{
	var $name = 'Users';
	function signup(){
		if ($this->request->is('post')){
			$d = $this->request->data;
			$d['User']['id'] = null;
			if (!empty($d['User']['password'])){
				$d['User']['password'] = Security::hash($d['User']['password'], null, true);
			}
			if ($this->User->save($d, true, array('username', 'password', 'mail'))){
				$this->Session->setFlash("Votre compte a bien ete cree", "notif");
			}
			else{
				$this->Session->setFlash("Votre compte n'a pas pue etre cree", "notif", array('type'=>'error'));
			}
		}
	}
	function login(){
		if($this->request->is('post')){
			if($this->Auth->login()){
				$this->Session->setFlash("Vous etes connecte", "notif");
				$this->redirect('/');
			}
			else{
				$this->Session->setFlash("identifiant incorrect", "notif", array('type'=>'error'));
			}
		}
	}
	function logout(){
		$this->Auth->logout();
		$this->redirect('/');
	}
	function edit(){
		$user_id = $this->Auth->user('id');
		if(!$user_id){
			$this->redirect('/');
			die();
		}
		$this->User->id = $user_id;
		$passError = false;
		if($this->request->is('put') || $this->request->is('post')){
			$d = $this->request->data;
			$d['User']['id'] = $user_id;
			if(!empty($d['User']['pass1'])){
				if($d['User']['pass1'] == $d['User']['pass2']){
					$d['User']['password'] = Security::hash($d['User']['pass1'], null, true);
				}else{
					$passError = true;
				}
			}
			if($this->User->save($d, true, array('username', 'mail', 'password'))){
				$this->Session->setFlash("Profil update", "notif");
			}else{
				$this->Session->setFlash("Profil no update", "notif", array('type'=>'error'));
			}
			if ($passError){
				$this->User->validationErrors['pass2'] = array('wrong password');}
		}else{
			$this->request->data = $this->User->read();
		}
		$this->request->data['User']['pass1'] = $this->request->data['User']['pass2'] = '';
	}
	function admin(){
		$user_ad = $this->Auth->user('group_');
		if($user_ad != "Admin"){
				$this->redirect('/');
			die();
		}
		$this->set('users', $this->User->find('all'));
	}
	function add(){
		$user_ad = $this->Auth->user('group_');
		if($user_ad != "Admin"){
				$this->redirect('/');
			die();
		}
		if ($this->request->is('post')){
			$d = $this->request->data;
			$d['User']['id'] = null;
			if (!empty($d['User']['password'])){
				$d['User']['password'] = Security::hash($d['User']['password'], null, true);
			}
			if ($this->User->save($d, true, array('username', 'password', 'mail'))){
				$this->Session->setFlash('Your user data has been saved.');
				$this->redirect(array('action' => 'admin'));
			}
		}
	}
	function editad($id = null) {
		$user_ad = $this->Auth->user('group_');
		if($user_ad != "Admin"){
				$this->redirect('/');
			die();
		}
		$this->User->id = $id;
		if (empty($this->data)){
			$this->data = $this->User->read();
		}else{
			if ($this->User->save($this->data)){
				$this->Session->setFlash('Your user with id: '.$id.' has been updated.');
				$this->redirect(array('action' => 'admin'));
			}
		}
	}
	function delete($id)
	{
		$user_ad = $this->Auth->user('group_');
		if($user_ad != "Admin"){
				$this->redirect('/');
			die();
		}
		$this->User->delete($id);
		$this->Session->setFlash('The user with id: '.$id.' has been deleted.');
		$this->redirect(array('action'=>'admin'));
	}
}
?>
