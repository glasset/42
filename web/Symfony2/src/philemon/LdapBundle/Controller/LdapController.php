<?php

namespace philemon\LdapBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class LdapController extends Controller
{
    public function indexAction()
    {
        return $this->render('philemonLdapBundle:Ldap:index.html.twig');
	}

	public function contactsAction()
	{
		//$tab = array("cn", "uid", "birth-date", "picture", "mobile-phone");
		//$array = $this->filter("&(uid=*)", $tab);
		return $this->render('philemonLdapBundle:Ldap:contacts.html.twig');
	}

	public function filter($filter, $field = array())
	{
		$ldaptree  = 'dc=42,dc=fr';
		$result = ldap_search($this->_ldapconn, $ldaptree, "(".$filter.")", $field) or die ("Error in search query: ".ldap_error($this->_ldapconn));
		$data = ldap_get_entries($this->_ldapconn, $result);
		$tmp = array();
		$result = array();
		for ($i = 0; $i < $data['count']; $i++)
		{
			foreach ($field as $t)
			{
				if (isset($data[$i][$t][0]))
					$tmp[$t] = $data[$i][$t][0];
				else
					$tmp[$t] = "(null)";
			}
			$result[] = $tmp;
		}
		return $result;
	}
}
