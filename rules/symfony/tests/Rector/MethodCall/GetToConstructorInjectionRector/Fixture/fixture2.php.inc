<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Fixture;

use Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\Anything;
use Rector\Symfony\Tests\Rector\Source\SymfonyController;

class Fixture2
{
    public function render()
    {
        $this->renderTwig([
            'posts' => $this->get(\Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\Something::class)->callMe(),
            'comments' => $this->get(Anything::class)->callMe(),
        ]);
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Fixture;

use Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\Anything;
use Rector\Symfony\Tests\Rector\Source\SymfonyController;

class Fixture2
{
    private \Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\Something $something;
    private \Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\Anything $anything;
    public function __construct(\Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\Something $something, \Rector\Symfony\Tests\Rector\MethodCall\GetToConstructorInjectionRector\Source\Anything $anything)
    {
        $this->something = $something;
        $this->anything = $anything;
    }
    public function render()
    {
        $this->renderTwig([
            'posts' => $this->something->callMe(),
            'comments' => $this->anything->callMe(),
        ]);
    }
}

?>
