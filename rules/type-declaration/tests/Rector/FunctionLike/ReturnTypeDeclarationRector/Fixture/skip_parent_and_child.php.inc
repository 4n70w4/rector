<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class SkipParentAndChild
{
}

final class RedirectSkipParentAndChild extends SkipParentAndChild
{
}

final class SkipParentAndChild
{
    public function run(bool $response): SkipParentAndChild
    {
        if ($response) {
            return new RedirectSkipParentAndChild;
        }

        return new SkipParentAndChild;
    }
}
