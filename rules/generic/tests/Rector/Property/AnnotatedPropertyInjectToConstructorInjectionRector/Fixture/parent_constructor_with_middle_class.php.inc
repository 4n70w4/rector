<?php

namespace Rector\Generic\Tests\Rector\Property\AnnotatedPropertyInjectToConstructorInjectionRector\Fixture;

class ParentConstructorWithMiddleClass
{
    /**
     * @var \DateTimeInterface
     * @inject
     */
    public $dateTime;
}

class ClassWithInjects10Parent extends ParentConstructorWithMiddleClass
{
}

class ClassWithInjects10 extends ClassWithInjects10Parent
{
    /**
     * @var \stdClass
     * @inject
     */
    public $property;
}

?>
-----
<?php

namespace Rector\Generic\Tests\Rector\Property\AnnotatedPropertyInjectToConstructorInjectionRector\Fixture;

class ParentConstructorWithMiddleClass
{
    /**
     * @var \DateTimeInterface
     */
    private $dateTime;
    public function __construct(\DateTimeInterface $dateTime)
    {
        $this->dateTime = $dateTime;
    }
}

class ClassWithInjects10Parent extends ParentConstructorWithMiddleClass
{
}

class ClassWithInjects10 extends ClassWithInjects10Parent
{
    /**
     * @var \stdClass
     */
    private $property;
    public function __construct(\DateTimeInterface $dateTime, \stdClass $property)
    {
        $this->property = $property;
        parent::__construct($dateTime);
    }
}

?>
