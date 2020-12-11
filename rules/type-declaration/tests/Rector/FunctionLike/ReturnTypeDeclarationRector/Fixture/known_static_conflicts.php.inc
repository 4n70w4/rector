<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class KnownStaticConflicts
{
    public function getMoreWhatever()
    {
        if (true) {
            return false;
        }

        return [];
    }
}
