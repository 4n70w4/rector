<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipDoubleMethodSameVariable
{
    public function run()
    {
        $method = 'you';

        return $method;
    }

    public function go()
    {
        $method = 'me';

        return $method;
    }
}
