<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;
use Doctrine\Common\Collections\ArrayCollection;

/**
 * Activity
 *
 * @ORM\Table(name="philemon_activities")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\ActivityRepository")
 */
class Activity
{
	public function __construct()
	{
		$tmp = new \Datetime('NOW');
		$this->dateStartInscription = $tmp;
		$this->dateEndInscription = $tmp;
		$this->dateStart = $tmp;
		$this->dateEnd = $tmp;
		$this->baremes = new ArrayCollection();
	}
	public function __toString()
	{
		return ($this->name);
	}
    /**
     * @var integer
     *
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @ORM\ManyToOne(targetEntity="Module", inversedBy="activities")
     * @ORM\JoinColumn(name="module_id", referencedColumnName="id")
     */
     private $module;
	
	/**
    * @ORM\OneToMany(targetEntity="Bareme", mappedBy="activity", cascade={"persist", "remove"}, orphanRemoval=true)
    */
    private $baremes;

	/**

    /**
     * @var string
     *
     * @ORM\Column(name="name", type="string", length=255)
     */
    private $name;

    /**
     * @var string
     *
     * @ORM\Column(name="description", type="string", length=1024)
     */
    private $description;

    /**
     * @var string
     *
     * @ORM\Column(name="subject", type="string", length=255)
     */
    private $subject;

    /**
     * @var integer
     *
     * @ORM\Column(name="max_place", type="integer")
     */
    private $maxPlace;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_start_inscription", type="datetime")
     */
    private $dateStartInscription;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_end_inscription", type="datetime")
     */
    private $dateEndInscription;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_start", type="datetime")
     */
    private $dateStart;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_end", type="datetime")
     */
    private $dateEnd;

     //* @ORM\Column(name="type", type="string", columnDefinition="enum('Project', 'TP', 'Exam')")
    /**
     * @var string
     *
     * @ORM\Column(name="type", type="string", length=255)
     */
    private $type;

	public function setModule($module)
	{
		$this->module = $module;
	}

	public function getModule()
	{
		return $this->module;
	}

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
     * Set name
     *
     * @param string $name
     * @return Activity
     */
    public function setName($name)
    {
        $this->name = $name;

        return $this;
    }

    /**
     * Get name
     *
     * @return string 
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * Set description
     *
     * @param string $description
     * @return Activity
     */
    public function setDescription($description)
    {
        $this->description = $description;

        return $this;
    }

    /**
     * Get description
     *
     * @return string 
     */
    public function getDescription()
    {
        return $this->description;
    }

    /**
     * Set subject
     *
     * @param string $subject
     * @return Activity
     */
    public function setSubject($subject)
    {
        $this->subject = $subject;

        return $this;
    }

    /**
     * Get subject
     *
     * @return string 
     */
    public function getSubject()
    {
        return $this->subject;
    }

    /**
     * Set maxPlace
     *
     * @param integer $maxPlace
     * @return Activity
     */
    public function setMaxPlace($maxPlace)
    {
        $this->maxPlace = $maxPlace;

        return $this;
    }

    /**
     * Get maxPlace
     *
     * @return integer 
     */
    public function getMaxPlace()
    {
        return $this->maxPlace;
    }

    /**
     * Set dateStartInscription
     *
     * @param \DateTime $dateStartInscription
     * @return Activity
     */
    public function setDateStartInscription($dateStartInscription)
    {
        $this->dateStartInscription = $dateStartInscription;

        return $this;
    }

    /**
     * Get dateStartInscription
     *
     * @return \DateTime 
     */
    public function getDateStartInscription()
    {
        return $this->dateStartInscription;
    }

    /**
     * Set dateEndInscription
     *
     * @param \DateTime $dateEndInscription
     * @return Activity
     */
    public function setDateEndInscription($dateEndInscription)
    {
        $this->dateEndInscription = $dateEndInscription;

        return $this;
    }

    /**
     * Get dateEndInscription
     *
     * @return \DateTime 
     */
    public function getDateEndInscription()
    {
        return $this->dateEndInscription;
    }

    /**
     * Set dateStart
     *
     * @param \DateTime $dateStart
     * @return Activity
     */
    public function setDateStart($dateStart)
    {
        $this->dateStart = $dateStart;

        return $this;
    }

    /**
     * Get dateStart
     *
     * @return \DateTime 
     */
    public function getDateStart()
    {
        return $this->dateStart;
    }

    /**
     * Set dateEnd
     *
     * @param \DateTime $dateEnd
     * @return Activity
     */
    public function setDateEnd($dateEnd)
    {
        $this->dateEnd = $dateEnd;

        return $this;
    }

    /**
     * Get dateEnd
     *
     * @return \DateTime 
     */
    public function getDateEnd()
    {
        return $this->dateEnd;
    }

    /**
     * Set type
     *
     * @param string $type
     * @return Activity
     */
    public function setType($type)
    {
        $this->type = $type;

        return $this;
    }

    /**
     * Get type
     *
     * @return string 
     */
    public function getType()
    {
        return $this->type;
    }

    /**
     * Add baremes
     *
     * @param \philemon\ModuleBundle\Entity\Bareme $baremes
     * @return Activity
     */
    public function addBareme(\philemon\ModuleBundle\Entity\Bareme $baremes)
    {
        $this->baremes[] = $baremes;

        return $this;
    }

    /**
     * Remove baremes
     *
     * @param \philemon\ModuleBundle\Entity\Bareme $baremes
     */
    public function removeBareme(\philemon\ModuleBundle\Entity\Bareme $baremes)
    {
        $this->baremes->removeElement($baremes);
    }

    /**
     * Get baremes
     *
     * @return \Doctrine\Common\Collections\Collection 
     */
    public function getBaremes()
    {
        return $this->baremes;
    }
}
