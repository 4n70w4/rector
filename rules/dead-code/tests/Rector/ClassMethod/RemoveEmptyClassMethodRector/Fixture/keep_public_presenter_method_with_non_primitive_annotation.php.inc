<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Nette\Application\UI\Presenter;

final class KeepPublicPresenterMethodWithoutPrimitiveAnnotation extends Presenter
{
    /**
     * @User(secured)
     */
    public function keep()
    {
    }
}
