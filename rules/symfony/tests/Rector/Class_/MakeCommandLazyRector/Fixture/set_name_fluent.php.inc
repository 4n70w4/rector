<?php

namespace Rector\Symfony\Tests\Rector\Class_\MakeCommandLazyRector\Fixture;

class SetNameFluent
{
    public function configure()
    {
        $this->setName('some:command')
            ->setDescription('Description');
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\Class_\MakeCommandLazyRector\Fixture;

class SetNameFluent
{
    protected static $defaultName = 'some:command';
    public function configure()
    {
        $this->setDescription('Description');
    }
}

?>
