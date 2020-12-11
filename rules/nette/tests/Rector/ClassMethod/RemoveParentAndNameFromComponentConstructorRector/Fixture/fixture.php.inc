<?php

namespace Rector\Nette\Tests\Rector\ClassMethod\RemoveParentAndNameFromComponentConstructorRector\Fixture;

use Nette\Application\UI\Control;
use Nette\ComponentModel\IContainer;

class Fixture
{
    public function __construct(IContainer $parent = null, $name = null, int $value)
    {
        parent::__construct($parent, $name);
        $this->value = $value;
    }
}

?>
-----
<?php

namespace Rector\Nette\Tests\Rector\ClassMethod\RemoveParentAndNameFromComponentConstructorRector\Fixture;

use Nette\Application\UI\Control;
use Nette\ComponentModel\IContainer;

class Fixture
{
    public function __construct(int $value)
    {
        $this->value = $value;
    }
}

?>
