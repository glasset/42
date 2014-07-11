<?php

/* ::base.html.twig */
class __TwigTemplate_93c12844f7732829a80574bda6986300cef88991f5ea06bc12163273cdbe30e7 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'navigation' => array($this, 'block_navigation'),
            'body' => array($this, 'block_body'),
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        echo "<!DOCTYPE html>
<html lang=\"en\">
  <head>
    <meta charset=\"utf-8\">
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">
    <meta name=\"description\" content=\"\">
    <meta name=\"author\" content=\"\">

\t<title>";
        // line 9
        $this->displayBlock('title', $context, $blocks);
        echo "</title>

\t<link href=\"";
        // line 11
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/bootstrap.css"), "html", null, true);
        echo "\" type=\"text/css\" rel=\"stylesheet\">
    <link href=\"";
        // line 12
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/sb-admin.css"), "html", null, true);
        echo "\" rel=\"stylesheet\">
    <link rel=\"stylesheet\" href=\"";
        // line 13
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("font-awesome/css/font-awesome.min.css"), "html", null, true);
        echo "\">
  </head>

  <body>

    <div id=\"wrapper\">

    ";
        // line 20
        $this->displayBlock('navigation', $context, $blocks);
        // line 32
        echo "      ";
        $this->displayBlock('body', $context, $blocks);
        // line 34
        echo "      </div>
    </div>
    <script src=\"";
        // line 36
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("js/jquery-1.10.2.js"), "html", null, true);
        echo "\"></script>
    <script src=\"";
        // line 37
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("js/bootstrap.js"), "html", null, true);
        echo "\"></script>

  </body>
</html>
";
    }

    // line 9
    public function block_title($context, array $blocks = array())
    {
        echo "Recowin";
    }

    // line 20
    public function block_navigation($context, array $blocks = array())
    {
        // line 21
        echo "      <nav class=\"navbar navbar-inverse navbar-fixed-top\" role=\"navigation\">
        <div class=\"navbar-header\">
\t\t  <a class=\"navbar-brand\" href=\"";
        // line 23
        echo $this->env->getExtension('routing')->getPath("recowin_calendar_homepage");
        echo "\"><i class=\"fa fa-home\"></i> Recowin</a>
\t  </div>
\t\t\t<div class=\"collapse navbar-collapse navbar-ex1-collapse\">
\t\t\t\t<ul class=\"nav navbar-nav side-nav\">
\t\t\t\t\t<li><a href=\"";
        // line 27
        echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("recowin_calendar", array("years" => twig_date_format_filter($this->env, "now", "Y"), "month" => twig_date_format_filter($this->env, "now", "m"))), "html", null, true);
        echo "\"><i class=\"fa fa-calendar\"></i> Calendar</a></li>
\t\t\t\t</ul>
\t\t\t</div>
        </nav>
        ";
    }

    // line 32
    public function block_body($context, array $blocks = array())
    {
        // line 33
        echo "      ";
    }

    public function getTemplateName()
    {
        return "::base.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  109 => 33,  106 => 32,  97 => 27,  90 => 23,  86 => 21,  83 => 20,  77 => 9,  68 => 37,  64 => 36,  60 => 34,  57 => 32,  55 => 20,  45 => 13,  41 => 12,  37 => 11,  32 => 9,  22 => 1,);
    }
}
