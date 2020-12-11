<?php

namespace Rector\CodingStyle\Tests\Rector\ClassMethod\YieldClassMethodToArrayClassMethodRector\Fixture;

use Rector\CodingStyle\Tests\Rector\ClassMethod\YieldClassMethodToArrayClassMethodRector\Source\EventSubscriberInterface;

class TypeDeclaration
{
    public static function getSubscribedEvents(): \Iterator
    {
        yield 'event' => 'callback';
    }
}

?>
-----
<?php

namespace Rector\CodingStyle\Tests\Rector\ClassMethod\YieldClassMethodToArrayClassMethodRector\Fixture;

use Rector\CodingStyle\Tests\Rector\ClassMethod\YieldClassMethodToArrayClassMethodRector\Source\EventSubscriberInterface;

class TypeDeclaration
{
    public static function getSubscribedEvents(): array
    {
        return ['event' => 'callback'];
    }
}

?>
