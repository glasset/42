<?php

/* RecowinCalendarBundle:Default:index.html.twig */
class __TwigTemplate_803555f2653f0b758c83e0e1665bbec845d72b416268c61360aa9785a5d33d15 extends Twig_Template
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
        echo "<center><h1> Welcome </h1></center>
<div class=\"highlight\">
<h5>Calendar Guillaume Lasset </h5>
</div>
";
    }

    public function getTemplateName()
    {
        return "RecowinCalendarBundle:Default:index.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  31 => 4,  28 => 3,);
    }
}
