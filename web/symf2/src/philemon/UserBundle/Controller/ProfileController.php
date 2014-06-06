<?php

namespace philemon\UserBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use philemon\UserBundle\Entity\User as User;

class ProfileController extends Controller
{
    public function showAction($slug)
    {
		$rep = $this->getDoctrine()
					->getRepository('philemonUserBundle:User');
		$use = $rep->findByUsername($slug);
		return $this->render('philemonUserBundle:Profile:show.html.twig', array ('use' => $use));
	}
}
