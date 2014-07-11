<?php

/* RecowinCalendarBundle:Default:show.html.twig */
class __TwigTemplate_d70bb01c3ccc7e23edc3950749f39b8195e51908e1315d8ed79a58bdbb09722a extends Twig_Template
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
<div class=\"container\">
\t<div class=\"highlight\">
\t\t<center> <h1> 
\t\t\t<a href=\"";
        // line 8
        echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("recowin_calendar", array("years" => ((isset($context["my"]) ? $context["my"] : $this->getContext($context, "my")) - 1), "month" => (isset($context["mm"]) ? $context["mm"] : $this->getContext($context, "mm")))), "html", null, true);
        echo "\"<button type=\"button\" class=\"btn btn-primary btn-xs\"><i class=\"fa fa-arrow-left\"></i></button></a>
\t\t\t\t";
        // line 9
        echo twig_escape_filter($this->env, (isset($context["my"]) ? $context["my"] : $this->getContext($context, "my")), "html", null, true);
        echo "
<a href=\"";
        // line 10
        echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("recowin_calendar", array("years" => ((isset($context["my"]) ? $context["my"] : $this->getContext($context, "my")) + 1), "month" => (isset($context["mm"]) ? $context["mm"] : $this->getContext($context, "mm")))), "html", null, true);
        echo "\"<button type=\"button\" class=\"btn btn-primary btn-xs\"><i class=\"fa fa-arrow-right\"></i></button></a>
</h1></center>
<center><h5>|
";
        // line 13
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["months"]) ? $context["months"] : $this->getContext($context, "months")));
        foreach ($context['_seq'] as $context["key"] => $context["m"]) {
            // line 14
            if (((isset($context["mm"]) ? $context["mm"] : $this->getContext($context, "mm")) == (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")))) {
                echo "<u>";
            }
            // line 15
            echo "<a href=\"";
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("recowin_calendar", array("years" => (isset($context["my"]) ? $context["my"] : $this->getContext($context, "my")), "month" => (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")))), "html", null, true);
            echo "\">";
            echo twig_escape_filter($this->env, (isset($context["m"]) ? $context["m"] : $this->getContext($context, "m")), "html", null, true);
            echo "</a>";
            if (((isset($context["mm"]) ? $context["mm"] : $this->getContext($context, "mm")) == (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")))) {
                echo "</u> ";
            }
            echo " |
";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['key'], $context['m'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 17
        echo "</center></h5>
</br>
";
        // line 19
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["cal"]) ? $context["cal"] : $this->getContext($context, "cal")));
        foreach ($context['_seq'] as $context["key"] => $context["y"]) {
            // line 20
            echo "\t";
            $context['_parent'] = (array) $context;
            $context['_seq'] = twig_ensure_traversable((isset($context["y"]) ? $context["y"] : $this->getContext($context, "y")));
            foreach ($context['_seq'] as $context["key"] => $context["m"]) {
                // line 21
                echo "<table class=\"table table-bordered\">
<thead>
<tr class=\"info\">
";
                // line 24
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable((isset($context["days"]) ? $context["days"] : $this->getContext($context, "days")));
                foreach ($context['_seq'] as $context["_key"] => $context["d"]) {
                    // line 25
                    echo "<th> ";
                    echo twig_escape_filter($this->env, (isset($context["d"]) ? $context["d"] : $this->getContext($context, "d")), "html", null, true);
                    echo " </th>
";
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['_key'], $context['d'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 27
                echo "</tr>
</thead>
<tbody>
<tr>
\t\t";
                // line 31
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable((isset($context["m"]) ? $context["m"] : $this->getContext($context, "m")));
                foreach ($context['_seq'] as $context["key"] => $context["d"]) {
                    // line 32
                    echo "\t\t";
                    if ((((isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")) == 1) && (((isset($context["d"]) ? $context["d"] : $this->getContext($context, "d")) - 1) != 0))) {
                        echo " <td colspan=\"";
                        echo twig_escape_filter($this->env, ((isset($context["d"]) ? $context["d"] : $this->getContext($context, "d")) - 1), "html", null, true);
                        echo "\"></td>";
                    }
                    // line 33
                    echo "\t\t\t<td class=\"";
                    if ((twig_date_format_filter($this->env, "now", "Y-m-d") == (((((isset($context["my"]) ? $context["my"] : $this->getContext($context, "my")) . "-") . (isset($context["mm"]) ? $context["mm"] : $this->getContext($context, "mm"))) . "-") . (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key"))))) {
                        echo "warning";
                    } elseif (($this->getAttribute((isset($context["note"]) ? $context["note"] : $this->getContext($context, "note")), (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")), array(), "array") == 1)) {
                        echo "success";
                    }
                    echo "\"><a href =\"";
                    echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("recowin_event", array("years" => (isset($context["my"]) ? $context["my"] : $this->getContext($context, "my")), "month" => (isset($context["mm"]) ? $context["mm"] : $this->getContext($context, "mm")), "day" => (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")))), "html", null, true);
                    echo "\">";
                    echo twig_escape_filter($this->env, (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")), "html", null, true);
                    echo " ";
                    if (($this->getAttribute((isset($context["note"]) ? $context["note"] : $this->getContext($context, "note")), (isset($context["key"]) ? $context["key"] : $this->getContext($context, "key")), array(), "array") == 1)) {
                        echo "<i class=\"fa fa-file-text\"></i>";
                    }
                    echo "</a> </td>
\t\t";
                    // line 34
                    if (((isset($context["d"]) ? $context["d"] : $this->getContext($context, "d")) == 7)) {
                        echo " </tr><tr> ";
                    }
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['key'], $context['d'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 36
                echo "</tr>
</tbody>
<table>
";
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['key'], $context['m'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['key'], $context['y'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 41
        echo "<center><a href=\"";
        echo $this->env->getExtension('routing')->getPath("recowin_add");
        echo "\"><button type=\"button\" class=\"btn btn-primary btn-lg\">Add Event</button></a></center>
</br>
<h5>Legende:</h5>
<mark class=\"bg-warning\">Aujourd'hui</mark></br><mark class=\"bg-success\">Event</mark>
</br>
</div>
</div>
";
    }

    public function getTemplateName()
    {
        return "RecowinCalendarBundle:Default:show.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  160 => 41,  147 => 36,  139 => 34,  122 => 33,  115 => 32,  111 => 31,  105 => 27,  96 => 25,  92 => 24,  87 => 21,  82 => 20,  78 => 19,  74 => 17,  59 => 15,  55 => 14,  51 => 13,  45 => 10,  41 => 9,  37 => 8,  31 => 4,  28 => 3,);
    }
}
