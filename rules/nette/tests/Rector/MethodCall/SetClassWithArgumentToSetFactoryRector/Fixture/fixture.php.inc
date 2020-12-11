<?php

namespace Rector\Nette\Tests\Rector\MethodCall\SetClassWithArgumentToSetFactoryRector\Fixture;

use Nette\DI\ContainerBuilder;

class Fixture
{
    public function run(ContainerBuilder $containerBuilder)
    {
        $containerBuilder->addDefinition('...')
            ->setClass('Fixture', [1, 2]);
    }
}

?>
-----
<?php

namespace Rector\Nette\Tests\Rector\MethodCall\SetClassWithArgumentToSetFactoryRector\Fixture;

use Nette\DI\ContainerBuilder;

class Fixture
{
    public function run(ContainerBuilder $containerBuilder)
    {
        $containerBuilder->addDefinition('...')
            ->setFactory('Fixture', [1, 2]);
    }
}

?>
