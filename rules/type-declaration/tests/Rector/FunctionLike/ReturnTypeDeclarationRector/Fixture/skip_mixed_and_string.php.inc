<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use stdClass;

class SkipMixedAndString
{
    /** @var mixed */
    protected $value;

    public function getValue()
    {
        if ($this->value instanceof stdClass) {
            return $this->getStringValue();
        }

        return $this->value;
    }

    public function getStringValue(): string
    {
        return 'abc';
    }
}
