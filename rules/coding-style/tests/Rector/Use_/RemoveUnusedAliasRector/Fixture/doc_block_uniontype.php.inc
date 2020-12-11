<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use DateTime as PhpDateTime;
use DateTimeImmutable as PhpDateTimeImmutable;

class DocBlock
{
    /**
     * @var PhpDateTime|bool
     */
    protected $b;

    /**
     * @var PhpDateTimeImmutable
     */
    protected $a;
}
