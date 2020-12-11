<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

\App::uses('NotificationListener', 'Event');

class SomeClass
{
    public function run()
    {
        $values = new NotificationListener();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Event\NotificationListener;

class SomeClass
{
    public function run()
    {
        $values = new NotificationListener();
    }
}

?>
