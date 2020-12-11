<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class EmptyReturnArray
{
    public function getList(): array
    {
        $values = [];
        if (!empty($this->getArray())) {
            $values['name'] = $this->getArray();
        }

        return $values;
    }

    public function getArray(): array
    {
        return [];
    }
}
