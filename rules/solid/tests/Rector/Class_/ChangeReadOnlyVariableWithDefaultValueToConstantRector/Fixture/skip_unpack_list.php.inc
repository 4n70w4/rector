<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipUnpackList
{
    public function refactor(Node $node)
    {
        if (is_array($useImportToRestore)) {
            list($import, $alias) = $useImportToRestore;
        } else {
            $alias = '';
        }

        return $this->addImportToNamespaceIfMissing($node, $import, $alias);
    }
}
