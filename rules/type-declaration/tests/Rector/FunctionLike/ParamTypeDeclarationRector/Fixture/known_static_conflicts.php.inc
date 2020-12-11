<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

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
