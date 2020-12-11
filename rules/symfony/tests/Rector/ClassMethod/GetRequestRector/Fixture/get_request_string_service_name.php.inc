<?php

namespace Rector\Symfony\Tests\Rector\ClassMethod\GetRequestRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\AbstractSymfonyController;

class GetRequestStringServiceName
{
    public function action()
    {
        $request = $this->get('request');
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\ClassMethod\GetRequestRector\Fixture;

use Rector\Symfony\Tests\Rector\Source\AbstractSymfonyController;

class GetRequestStringServiceName
{
    public function action(\Symfony\Component\HttpFoundation\Request $request)
    {
        $request = $request;
    }
}

?>
