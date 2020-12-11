<?php

namespace Rector\Symfony\Tests\Rector\ClassMethod\ActionSuffixRemoverRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\AbstractSymfonyController;

class Fixture2
{
    public function indexAction()
    {
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\ClassMethod\ActionSuffixRemoverRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\AbstractSymfonyController;

class Fixture2
{
    public function index()
    {
    }
}

?>
