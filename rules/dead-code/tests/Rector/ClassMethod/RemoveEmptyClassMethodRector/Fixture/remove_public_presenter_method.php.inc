<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Nette\Application\UI\Presenter;

final class RemovePublicPresenterMethod extends Presenter
{
    public function letItGo()
    {
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Nette\Application\UI\Presenter;

final class RemovePublicPresenterMethod extends Presenter
{
}

?>
