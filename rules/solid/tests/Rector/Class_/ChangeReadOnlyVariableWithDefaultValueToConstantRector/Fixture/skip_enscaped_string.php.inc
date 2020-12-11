<?php

namespace Rector\Solid\Tests\Rector\Class_\ChangeReadOnlyVariableWithDefaultValueToConstantRector\Fixture;

class SkipEnscapedString
{
    public function run()
    {
        $testsBaseDir = "{$this->testSuite->rootPath}/tests";

        return $testsBaseDir;
    }
}
