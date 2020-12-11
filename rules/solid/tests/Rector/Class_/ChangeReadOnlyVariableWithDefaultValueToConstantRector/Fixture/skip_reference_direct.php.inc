<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipReferenceDirect
{
    public function removeAndCollectFormerAssignedVariables(Class_ $class, bool $skipSetUpMethod = true): array
    {
        $formerVariablesByMethods = [];

        $this->callableNodeTraverser->traverseNodesWithCallable($class->stmts, function (Node $node) use (
            &$formerVariablesByMethods,
            $skipSetUpMethod
        ): ?PropertyFetch {
            $this->processAssign($node, $parentNode, $type, $formerVariablesByMethods);
        });
    }
}
