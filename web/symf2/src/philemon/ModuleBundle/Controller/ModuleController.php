<?php

namespace philemon\ModuleBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use philemon\ModuleBundle\Entity\ModuleLogin as ModuleLogin;
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
        return $this->render('philemonModuleBundle:Module:show.html.twig', array('register' => $register, 'mod' => $mod, 'act' => $activities));
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
        return $this->render('philemonModuleBundle:Module:activity.html.twig', array('register' => $register, 'activity' => $a));
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
}
