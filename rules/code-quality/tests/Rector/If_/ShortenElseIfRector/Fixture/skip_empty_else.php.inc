<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipEmptyElse
{
    /**
     * @var bool
     */
    private $cond1;

    public function run()
    {
        if ($this->cond1) {
            return 1;
        } else {
            // some comment
            [];
        }
    }
}
