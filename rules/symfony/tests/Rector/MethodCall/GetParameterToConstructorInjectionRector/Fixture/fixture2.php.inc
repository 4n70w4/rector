<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\GetParameterToConstructorInjectionRector\Fixture;

use Rector\Symfony\Tests\Rector\MethodCall\GetParameterToConstructorInjectionRector\Source\DoctrineQuery;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class Fixture2
{
    public function render()
    {
        $value = $this->getParameter('some_parameter');

        $query = new DoctrineQuery();
        $queryId = $query->getParameter('id');
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\GetParameterToConstructorInjectionRector\Fixture;

use Rector\Symfony\Tests\Rector\MethodCall\GetParameterToConstructorInjectionRector\Source\DoctrineQuery;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class Fixture2
{
    private string $someParameter;
    public function __construct(string $someParameter)
    {
        $this->someParameter = $someParameter;
    }
    public function render()
    {
        $value = $this->someParameter;

        $query = new DoctrineQuery();
        $queryId = $query->getParameter('id');
    }
}

?>
