<?php

/* RecowinCalendarBundle:Default:event.html.twig */
class __TwigTemplate_a6fd007b47179b3eb7455be05416cb7b94bf0736bfaef646caaeccfaf7ecf3e1 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("::base.html.twig");

        $this->blocks = array(
            'body' => array($this, 'block_body'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "::base.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 3
    public function block_body($context, array $blocks = array())
    {
        // line 4
        echo "</br>
<center><h2>";
        // line 5
        echo twig_escape_filter($this->env, ((((("Le " . (isset($context["d"]) ? $context["d"] : $this->getContext($context, "d"))) . "/") . (isset($context["m"]) ? $context["m"] : $this->getContext($context, "m"))) . "/") . (isset($context["y"]) ? $context["y"] : $this->getContext($context, "y"))), "html", null, true);
        echo "</h2></center>
<div class=\"container\">
<div class=\"highlight\">
";
        // line 8
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["res"]) ? $context["res"] : $this->getContext($context, "res")));
        $context['_iterated'] = false;
        foreach ($context['_seq'] as $context["_key"] => $context["d"]) {
            // line 9
            echo "<h5>";
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["d"]) ? $context["d"] : $this->getContext($context, "d")), "name"), "html", null, true);
            echo " ";
            echo twig_escape_filter($this->env, (("(se deroule a " . $this->getAttribute((isset($context["d"]) ? $context["d"] : $this->getContext($context, "d")), "place")) . ")"), "html", null, true);
            echo "</h5>
<div class=\"highlight\">
<u><b>description</b></u>: ";
            // line 11
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["d"]) ? $context["d"] : $this->getContext($context, "d")), "description"), "html", null, true);
            echo "
</div>
";
            $context['_iterated'] = true;
        }
        if (!$context['_iterated']) {
            // line 14
            echo "<center><h6>Aucun event prevus pour ce jour la</h6></center>
";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['_key'], $context['d'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 16
        echo "<center><a href=\"";
        echo $this->env->getExtension('routing')->getPath("recowin_add");
        echo "\"><button type=\"button\" class=\"btn btn-primary btn-lg\">Add Event</button></a></center>
</div>
</div>
";
    }

    public function getTemplateName()
    {
        return "RecowinCalendarBundle:Default:event.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  68 => 16,  61 => 14,  53 => 11,  45 => 9,  40 => 8,  34 => 5,  31 => 4,  28 => 3,);
    }
}
