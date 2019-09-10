<?php declare(strict_types=1);

namespace Rector\Php\Tests\Rector\Property\TypedPropertyRector;

use Rector\Php\Rector\Property\TypedPropertyRector;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;

final class TypedPropertyRectorTest extends AbstractRectorTestCase
{
    public function test(): void
    {
        $this->doTestFiles([
            __DIR__ . '/Fixture/property.php.inc',
            __DIR__ . '/Fixture/skip_invalid_property.php.inc',
            __DIR__ . '/Fixture/bool_property.php.inc',
            __DIR__ . '/Fixture/class_property.php.inc',
            __DIR__ . '/Fixture/nullable_property.php.inc',
            __DIR__ . '/Fixture/static_property.php.inc',
            __DIR__ . '/Fixture/default_values_for_nullable_iterables.php.inc',
            __DIR__ . '/Fixture/default_values.php.inc',
            __DIR__ . '/Fixture/match_types.php.inc',
            __DIR__ . '/Fixture/match_types_parent.php.inc',
            __DIR__ . '/Fixture/static_analysis_based.php.inc',
        ]);
    }

    public function getRectorClass(): string
    {
        return TypedPropertyRector::class;
    }
}
