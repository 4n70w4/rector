<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\CompleteVarDocTypePropertyRector\Fixture;

class AssignConflict
{

}

final class AssignConflict
{
    private $eventDispatcher;

    public function __construct(\EventDispatcher $eventDispatcher)
    {
        $this->eventDispatcher = $eventDispatcher;
    }

    public function run(AssignConflict $stdClass)
    {
        $this->eventDispatcher = $stdClass;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\CompleteVarDocTypePropertyRector\Fixture;

class AssignConflict
{

}

final class AssignConflict
{
    /**
     * @var \EventDispatcher|\Rector\TypeDeclaration\Tests\Rector\Property\CompleteVarDocTypePropertyRector\Fixture\AssignConflict
     */
    private $eventDispatcher;

    public function __construct(\EventDispatcher $eventDispatcher)
    {
        $this->eventDispatcher = $eventDispatcher;
    }

    public function run(AssignConflict $stdClass)
    {
        $this->eventDispatcher = $stdClass;
    }
}

?>
