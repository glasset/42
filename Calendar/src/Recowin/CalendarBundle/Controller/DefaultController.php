<?php

namespace Recowin\CalendarBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Recowin\CalendarBundle\Entity\Eventc as Eventc;
use Recowin\CalendarBundle\Entity;

class DefaultController extends Controller
{
    public function indexAction()
	{
        return $this->render('RecowinCalendarBundle:Default:index.html.twig');
	}

	public function showAction($years, $month){
		$days = array('Lundi', 'Mardi', 'Mercredi', 'Jeudi', 'Vendredi', 'Samedi', 'Dimanche');
		$months = array('01' => 'Janvier', '02' => 'Fevrier', '03' => 'Mars', '04' => 'Avril', '05' => 'Mai', '06' => 'Juin', '07' => 'Juillet', '08' => 'Aout', '09' => 'Septembre', '10' => 'Octobre', '11' => 'Novembre', '12' => 'Decembre');
		$cal = array();
		$notem = array();
		$date =  new \DateTime($years.'-'.$month.'-01');
		while ($date->format('n') <= $month && $date->format('Y') <= $years){
			$y = $date->format('Y');
			$m = $date->format('n');
			$d = $date->format('j');
			$w = str_replace('0', '7', $date->format('w'));
			$rep = $this->getDoctrine()
					->getRepository('RecowinCalendarBundle:Eventc');
			$res = $rep->findby(array('dates' => new \DateTime($y.'-'.$m.'-'.$d)));
			if(!empty($res)){ $notem[$d] = 1;
			}
			else { $notem[$d] = 0;}
			$cal[$y][$m][$d] = $w;
			$date->add(new \DateInterval('P1D'));
		}
        return $this->render('RecowinCalendarBundle:Default:show.html.twig', array('cal' => $cal, 'days' => $days, 'months' => $months, 'my' => $years, 'mm' => $month, 'note' => $notem));
	}

	public function eventAction($years, $month, $day){
		$rep = $this->getDoctrine()
					->getRepository('RecowinCalendarBundle:Eventc');
		$res = $rep->findby(array('dates' => new \DateTime($years.'-'.$month.'-'.$day)));
		return $this->render('RecowinCalendarBundle:Default:event.html.twig', array('res' => $res, 'm' => $month, 'y' => $years, 'd' => $day));
	}

	public function addAction(){
		$form = $this->createFormBuilder();
		$form->add('description', 'textarea');
		$form->add('place', 'textarea');
		$form->add('name', 'textarea');
		$form->add('date', 'date');
		$form = $form->getForm();

		$request = $this->get('request');
		if ($request->getMethod() == 'POST') {
			$form->bind($request);
			if ($form->isValid()) {
				$ev = new eventc();
				$ev->setDescription($form->get('description')->getdata());
				$ev->setName($form->get('name')->getdata());
				$ev->setPlace($form->get('place')->getdata());
				$ev->setDates($form->get('date')->getdata());
				$em = $this->getDoctrine()->getManager();
				$em->persist($ev);
				$em->flush();
				$tmp = $form->get('date')->getdata();
				$res[0] = $tmp->format('Y');
				$res[1] = $tmp->format('n');
				$res[2] = $tmp->format('j');
				}
				return $this->redirect($this->generateUrl('recowin_event', array('years' => $res[0], 'month' => $res[1], 'day' => $res[2])));
			}
		return $this->render('RecowinCalendarBundle:Default:add.html.twig', array('form' => $form->createView()));
}
}
