<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Correction
 *
 * @ORM\Table(name="philemon_correction")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\CorrectionRepository")
 */
class Correction
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
     * @ORM\OneToOne(targetEntity="Activity")
     * @ORM\JoinColumn(name="activity_id", referencedColumnName="id")
     */
    private $activity;

    /**
     * @ORM\OneToOne(targetEntity="\philemon\UserBundle\Entity\User")
     * @ORM\JoinColumn(name="user_id", referencedColumnName="id")
     */
    private $user;

    /**
     * @ORM\OneToOne(targetEntity="\philemon\UserBundle\Entity\User")
     * @ORM\JoinColumn(name="corrector_id", referencedColumnName="id")
     */
    private $corrector;

    /**
     * @var float
     *
     * @ORM\Column(name="score", type="float")
     */
    private $score;


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
     * @param float $score
     * @return Correction
     */
    public function setScore($score)
    {
        $this->score = $score;

        return $this;
    }

    /**
     * Get score
     *
     * @return float 
     */
    public function getScore()
    {
        return $this->score;
    }

    /**
     * Set activity
     *
     * @param \philemon\ModuleBundle\Entity\Activity $activity
     * @return Correction
     */
    public function setActivity(\philemon\ModuleBundle\Entity\Activity $activity = null)
    {
        $this->activity = $activity;

        return $this;
    }

    /**
     * Get activity
     *
     * @return \philemon\ModuleBundle\Entity\Activity 
     */
    public function getActivity()
    {
        return $this->activity;
    }

    /**
     * Set user
     *
     * @param \philemon\UserBundle\Entity\User $user
     * @return Correction
     */
    public function setUser(\philemon\UserBundle\Entity\User $user = null)
    {
        $this->user = $user;

        return $this;
    }

    /**
     * Get user
     *
     * @return \philemon\UserBundle\Entity\User 
     */
    public function getUser()
    {
        return $this->user;
    }

    /**
     * Set corrector
     *
     * @param \philemon\UserBundle\Entity\User $corrector
     * @return Correction
     */
    public function setCorrector(\philemon\UserBundle\Entity\User $corrector = null)
    {
        $this->corrector = $corrector;

        return $this;
    }

    /**
     * Get corrector
     *
     * @return \philemon\UserBundle\Entity\User 
     */
    public function getCorrector()
    {
        return $this->corrector;
    }
}
