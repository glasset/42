<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * BaremeCorrection
 *
 * @ORM\Table(name="philemon_bareme_correction")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\BaremeCorrectionRepository")
 */
class BaremeCorrection
{
    /**
     * @var integer
     *
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @ORM\OneToOne(targetEntity="Bareme")
     * @ORM\JoinColumn(name="bareme_id", referencedColumnName="id")
     */
    private $bareme;

    /**
     * @var integer
     *
     * @ORM\Column(name="score", type="integer")
     */
    private $score;

    /**
     * @var string
     *
     * @ORM\Column(name="comment", type="string", length=2048)
     */
    private $comment;


    /**
     * Get id
     *
     * @return integer 
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Set score
     *
     * @param integer $score
     * @return BaremeCorrection
     */
    public function setScore($score)
    {
        $this->score = $score;

        return $this;
    }

    /**
     * Get score
     *
     * @return integer 
     */
    public function getScore()
    {
        return $this->score;
    }

    /**
     * Set comment
     *
     * @param string $comment
     * @return BaremeCorrection
     */
    public function setComment($comment)
    {
        $this->comment = $comment;

        return $this;
    }

    /**
     * Get comment
     *
     * @return string 
     */
    public function getComment()
    {
        return $this->comment;
    }

    /**
     * Set bareme
     *
     * @param \philemon\ModuleBundle\Entity\Bareme $bareme
     * @return BaremeCorrection
     */
    public function setBareme(\philemon\ModuleBundle\Entity\Bareme $bareme = null)
    {
        $this->bareme = $bareme;

        return $this;
    }

    /**
     * Get bareme
     *
     * @return \philemon\ModuleBundle\Entity\Bareme 
     */
    public function getBareme()
    {
        return $this->bareme;
    }
}
