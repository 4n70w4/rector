<?php

namespace Rector\Symfony\Tests\Rector\ClassMethod\ActionSuffixRemoverRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\SymfonyController;

class Fixture
{
    public function indexAction()
    {
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\ClassMethod\ActionSuffixRemoverRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\SymfonyController;

class Fixture
{
    public function index()
    {
    }
}

?>
