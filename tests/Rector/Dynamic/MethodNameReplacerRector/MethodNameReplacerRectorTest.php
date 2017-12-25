<?php declare(strict_types=1);

namespace Rector\Tests\Rector\Dynamic\MethodNameReplacerRector;

use Rector\Rector\Dynamic\MethodNameReplacerRector;
use Rector\Testing\PHPUnit\AbstractConfigurableRectorTestCase;

final class MethodNameReplacerRectorTest extends AbstractConfigurableRectorTestCase
{
    public function test(): void
    {
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong.php.inc',
            __DIR__ . '/correct/correct.php.inc'
        );
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong2.php.inc',
            __DIR__ . '/correct/correct2.php.inc'
        );
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong3.php.inc',
            __DIR__ . '/correct/correct3.php.inc'
        );
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong4.php.inc',
            __DIR__ . '/correct/correct4.php.inc'
        );
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong5.php.inc',
            __DIR__ . '/correct/correct5.php.inc'
        );
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong6.php.inc',
            __DIR__ . '/correct/correct6.php.inc'
        );
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/SomeClass.php',
            __DIR__ . '/correct/SomeClass.php'
        );
    }

    /**
     * @return string[]
     */
    protected function getRectorClasses(): array
    {
        return [MethodNameReplacerRector::class];
    }

    protected function provideConfig(): string
    {
        return __DIR__ . '/config/rector.yml';
    }
}
