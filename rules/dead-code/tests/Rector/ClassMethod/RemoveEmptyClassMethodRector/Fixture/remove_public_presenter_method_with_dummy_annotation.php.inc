<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Nette\Application\UI\Presenter;

final class RemovePublicPresenterMethodWithDummyAnnotation extends Presenter
{
    /**
     * @param int $one
     */
    public function letItGo($one)
    {
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Nette\Application\UI\Presenter;

final class RemovePublicPresenterMethodWithDummyAnnotation extends Presenter
{
}

?>
