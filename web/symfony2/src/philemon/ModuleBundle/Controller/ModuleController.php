<?php

namespace philemon\ModuleBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use philemon\ModuleBundle\Entity\ModuleLogin as ModuleLogin;
use philemon\ModuleBundle\Entity;
use philemon\ModuleBundle\Entity\ActivityLogin as ActivityLogin;
use CCDNForum\ForumBundle\Entity\Category as CCDNCategory;

class ModuleController extends Controller
{
    public function indexAction()
	{
 		$user = $this->getUser();
		$mod = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Module');
		$m = $mod->findAll();
        return $this->render('philemonModuleBundle:Module:index.html.twig', array('mods' => $m, 'users' => $user));
	}

	public function showAction($id)
	{
 		$user = $this->getUser();
		$repa = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Activity');
		$activities = $repa->findBy(array('module' => $id));
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Module');
		$mod = $rep->find($id);
		$register = $this->getDoctrine()
                         ->getManager()
                         ->getRepository('philemonModuleBundle:ModuleLogin')
						 ->isRegister($user->getId(), $id);
		$current = $this->getDoctrine()
						->getRepository('philemonModuleBundle:ModuleLogin');
		$curPlace = $current->findBy(array('module' => $id));
		$count = count($curPlace);
		$percent = $count * 100 / $mod->getMaxPlace();
        return $this->render('philemonModuleBundle:Module:show.html.twig', array('register' => $register, 'mod' => $mod, 'act' => $activities, 'percent' => $percent, 'current' => $count));
	}

	public function registerAction($module_id)
	{
		$mod = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Module');
		$ml = new ModuleLogin();
		$ml->setModule($mod->find($module_id));
		$ml->setUser($this->getUser());
		$ml->setGrade('None');
		$ml->setAverage(0);
		$em = $this->getDoctrine()->getManager();
		$em->persist($ml);
		$em->flush();
		return $this->redirect($this->generateUrl('philemon_module_show', array('id' => $module_id)));
	}

	public function unregisterAction($module_id)
	{
 		$user = $this->getUser();
		$mod = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Module');
		$ml = $this->getDoctrine()
			->getRepository('philemonModuleBundle:ModuleLogin');
		$em = $this->getDoctrine()->getManager();
		$em->remove($ml->findOneBy(array('module' => $mod->find($module_id), 'user' => $user)));
		$em->flush();
		return $this->redirect($this->generateUrl('philemon_module_show', array('id' => $module_id)));
	}

	public function activityAction($activity_id)
	{
 		$user = $this->getUser();
		$rep = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Activity');
		$a = $rep->find($activity_id);
		$register = $this->getDoctrine()
                         ->getManager()
                         ->getRepository('philemonModuleBundle:ActivityLogin')
						 ->isRegister($user->getId(), $activity_id);
		$current = $this->getDoctrine()
						->getRepository('philemonModuleBundle:ActivityLogin');
		$curPlace = $current->findBy(array('activity' => $activity_id));
		$count = count($curPlace);
		$percent = $count * 100 / $a->getMaxPlace();
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Activity');
		$act = $rep->find($activity_id);
		$repa = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Learning');
		$learnings = $repa->findByActivity($act);
		if (strstr($this->getRequest()->getUri(), "Resume")) {
			return $this->render('philemonModuleBundle:Module:activityResume.html.twig', array('register' => $register, 'activity' => $a, 'current' => $count, 'percent' => $percent, 'learnings' => $learnings));
		} else {
			return $this->render('philemonModuleBundle:Module:activity.html.twig', array('register' => $register, 'activity' => $a, 'current' => $count, 'percent' => $percent, 'learnings' => $learnings));
		}
	}

	public function register_activityAction($activity_id)
	{
		$act = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Activity');
		$al = new ActivityLogin();
		$al->setActivity($act->find($activity_id));
		$al->setUser($this->getUser());
		$al->setScore(0);
		$em = $this->getDoctrine()->getManager();
		$em->persist($al);
		$em->flush();
		return $this->redirect($this->generateUrl('philemon_activity_show', array('activity_id' => $activity_id)));
	}

	public function unregister_activityAction($activity_id)
	{
 		$user = $this->getUser();
		$act = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Activity');
		$al = $this->getDoctrine()
			->getRepository('philemonModuleBundle:ActivityLogin');
		$em = $this->getDoctrine()->getManager();
		$em->remove($al->findOneBy(array('activity' => $act->find($activity_id), 'user' => $user)));
		$em->flush();
		return $this->redirect($this->generateUrl('philemon_activity_show', array('activity_id' => $activity_id)));
	}

	public function CorrAction($activity_id)
	{
		$user = $this->getUser();
		$corr = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Bareme');
		$c = $corr->findBy(array('activity' => $activity_id));
		if (!$c){
			return $this->redirect($this->generateUrl('philemon_home_homepage'));}
		$corr = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Activity');
		$name = $corr->findOneBy(array('id' => $activity_id));
		foreach ($c as $elem){
			$t[] = $elem->getCheckbox();
		}
		$i = 0;
		$form = $this->createFormBuilder();
		foreach($t as $elem){
			$check = split(';', $elem);
			foreach($check as $elem){
			$tab[$elem] = $elem ;
			}
			$form->add('notes'.$i, 'choice', array('choices' =>  $tab));
			$form->add('comment'.$i++, 'textarea');
		unset($tab);
		}
		$form = $form->getForm();

		$request = $this->get('request');
		if ($request->getMethod() == 'POST') {
			$form->bind($request);
			if ($form->isValid()) {
				$em = $this->getDoctrine()->getManager();
			    $score = $em->getRepository('philemonModuleBundle:Correction')->findOneby(array('corrector' => $user->getId(), 'activity' => $activity_id));
				if ($score->getScore() == NULL){
				$value = 0;
				for ($res = 0; $res < $i; $res++){
					$value += $form->get('notes'.$res)->getdata();
					$tabrate[] = $form->get('notes'.$res)->getdata();
					$tabcomment[] = $form->get('comment'.$res)->getdata();
				}
				$tc = implode(';', $tabcomment);
				$tr = implode(';', $tabrate);
				$score->setScore($value);
				$score->setComment($tc);
				$score->setRatescore($tr);
				$em->flush();
				}
				return $this->redirect($this->generateUrl('philemon_home_homepage'));
			}
		}
		return $this->render('philemonModuleBundle:Correction:Corr.html.twig', array('cor' => $c,'form' => $form->createView(), 'name' => $name));
	}

	public function RateAction($activity_id, $corrector)
	{
		$user = $this->getUser();
		$corr = $this->getDoctrine()
			->getRepository('philemonModuleBundle:Correction');
		$c = $corr->findOneBy(array('activity' => $activity_id, 'user' => $user->getId(), 'corrector' => $corrector ));
		if (!$c){
			return $this->redirect($this->generateUrl('philemon_home_homepage'));}
		$comment = split(';', $c->getComment());
		$rate = split(';', $c->getRatescore());
		$fin = array_combine($rate, $comment);
		$form = $this->createFormBuilder();
		$form->add('notes', 'choice', array('choices' => array('1'=> '1', '2' => '2', '3'=> '3', '4' =>'4', '5'=>'5')));
		$form->add('comment', 'textarea');
		$form = $form->getForm();

		$request = $this->get('request');
		if ($request->getMethod() == 'POST') {
			$form->bind($request);
			if ($form->isValid()) {
				$em = $this->getDoctrine()->getManager();
			    $rate = $em->getRepository('philemonModuleBundle:Correction')->findOneBy(array('activity' => $activity_id, 'user' => $user->getId(), 'corrector' => $corrector ));
				if ($rate->getRate() == NULL){
					$val = $form->get('notes')->getdata();
					$com = $form->get('comment')->getdata();
				$rate->setRate($val);
				$rate->setRatetext($com);
				$em->flush();
				}
				return $this->redirect($this->generateUrl('philemon_home_homepage'));
			}
		}
		if ($c->getRate() == NULL){
		return $this->render('philemonModuleBundle:Correction:rate.html.twig', array('res' => $fin, 'form' => $form->createView(), 'all' => $c));}
		return $this->render('philemonModuleBundle:Correction:rateb.html.twig', array('res' => $fin, 'form' => $form->createView(), 'all' => $c));

	}

	public function RatevAction($activity_id, $use){
		$user = $this->getUser();
		$corr = $this->getDoctrine()
					 ->getRepository('philemonModuleBundle:Correction');
		$c = $corr->findOneBy(array('activity' => $activity_id, 'user' => $use, 'corrector' => $user->getId()));
		return $this->render('philemonModuleBundle:Correction:ratev.html.twig', array('all' => $c));
	}
}
