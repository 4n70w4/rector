<?php declare (strict_types=1);

namespace Rector\Symfony\Tests\Rector\ClassMethod\GetRequestRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\SymfonyController;

class Fixture
{
    public function someAction()
    {
        $this->getRequest()->getSomething();
    }
}

?>
-----
<?php declare (strict_types=1);

namespace Rector\Symfony\Tests\Rector\ClassMethod\GetRequestRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\SymfonyController;

class Fixture
{
    public function someAction(\Symfony\Component\HttpFoundation\Request $request)
    {
        $request->getSomething();
    }
}

?>
