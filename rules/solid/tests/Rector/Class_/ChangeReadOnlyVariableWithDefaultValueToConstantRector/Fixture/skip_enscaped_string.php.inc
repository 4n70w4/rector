<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipEnscapedString
{
    public function run()
    {
        $testsBaseDir = "{$this->testSuite->rootPath}/tests";

        return $testsBaseDir;
    }
}
