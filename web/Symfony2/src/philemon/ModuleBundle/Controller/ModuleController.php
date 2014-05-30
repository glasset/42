<?php

namespace philemon\ModuleBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class ModuleController extends Controller
{
    public function indexAction()
	{
 		$modules = $this->getDoctrine()
                         ->getManager()
                         ->getRepository('philemonModuleBundle:Module')
						 ->selectAll();
 		$user = $this->getUser();
        return $this->render('philemonModuleBundle:Module:index.html.twig', array('modules' => $modules, 'users' => $user));
	}

	public function showAction($slug)
	{
 		$modules = $this->getDoctrine()
                         ->getRepository('philemonModuleBundle:Module')
						 ->findOneByName($slug);
		$user = $this->getUser();
 		$modules_log = $this->getDoctrine()
                         	->getManager()
							->getRepository('philemonModuleBundle:ModuleLogin')
							->findAll();
        return $this->render('philemonModuleBundle:Module:all.html.twig', array('modules' => $modules, 'users' => $user, 'logs' => $modules_log));
	}

	public function registerAction()
	{
		$test = "worth";
		return $this->render('philemonModuleBundle:Module:register.html.twig', array('test' => $test));
	}
}
