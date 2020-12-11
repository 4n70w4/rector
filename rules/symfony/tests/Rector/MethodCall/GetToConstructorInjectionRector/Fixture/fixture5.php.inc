<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Fixture;

use Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\ParentClassWithGetTrait;

class Fixture5
{
    public function render()
    {
        $this->get('notfound');
    }
}

?>
