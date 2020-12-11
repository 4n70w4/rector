<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipTrueFalseNullStrings
{
    public function run($key, $items)
    {
        if ($key === 'null') {
            return $items['null'];
        }

        return $items['null'];
    }

    public function runAgain($key, $items)
    {
        if ($key === 'true') {
            return $items['true'];
        }

        return $items['true'];
    }

    public function runOnceMore($key, $items)
    {
        if ($key === 'FALSE') {
            return $items['FALSE'];
        }

        return $items['FALSE'];
    }
}
