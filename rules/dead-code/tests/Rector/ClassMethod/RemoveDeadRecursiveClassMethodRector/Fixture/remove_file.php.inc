<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDeadRecursiveClassMethodRector\Fixture;

use Symplify\SmartFileSystem\SmartFileInfo;

class RemoveFile
{
    /**
     * @var SmartFileInfo[]
     */
    private $removedFiles;

    public function removeFile(SmartFileInfo $smartFileInfo): void
    {
        $this->removedFiles[$smartFileInfo->getRealPath()] = $smartFileInfo;
    }
}

abstract class AbstractClassUsingRemoveFile
{
    /**
     * @var RemoveFile
     */
    private $removeFile;

    protected function removeFile(SmartFileInfo $smartFileInfo): void
    {
        $this->removeFile->removeFile($smartFileInfo);
    }
}

class ClassExtendingClass extends AbstractClassUsingRemoveFile
{
    public function run($smartFileInfo)
    {
        $this->removeFile($smartFileInfo);
    }
}
