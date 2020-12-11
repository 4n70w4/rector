<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Nette\Utils\Strings;

class SkipShortStrings
{
    public function run($key, $items)
    {
        $inlined = Strings::replace($items, '#\s+#', ' ');
        $inlined = Strings::replace($items, '#\s+#', ' ');
        $inlined = Strings::replace($items, '#\s+#', ' ');
    }
}
