<?php

namespace Rector\Phpunit\Tests\Rector\Class_\AddSeeTestAnnotationRector\Fixture;

/**
 * This is here
 */
class AddToDocBlock
{
}

class AddToDocBlockTest extends \PHPUnit\Framework\TestCase
{
}

?>
-----
<?php

namespace Rector\Phpunit\Tests\Rector\Class_\AddSeeTestAnnotationRector\Fixture;

/**
 * This is here
 * @see \Rector\Phpunit\Tests\Rector\Class_\AddSeeTestAnnotationRector\Fixture\AddToDocBlockTest
 */
class AddToDocBlock
{
}

class AddToDocBlockTest extends \PHPUnit\Framework\TestCase
{
}

?>
