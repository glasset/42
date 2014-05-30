<?php

namespace philemon\HomeBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use JMS\SecurityExtraBundle\Annotation\Secure;

class HomeController extends Controller
{
    public function indexAction()
    {
        return $this->render('philemonHomeBundle:Home:index.html.twig');
    }
}
