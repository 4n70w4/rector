<?php declare(strict_types=1);

namespace Rector\BetterReflection\SourceLocator;

use Rector\BetterReflection\SourceLocator\Ast\Locator;
use Rector\BetterReflection\SourceLocator\Type\AggregateSourceLocator;
use Rector\BetterReflection\SourceLocator\Type\AutoloadSourceLocator;
use Rector\BetterReflection\SourceLocator\Type\ComposerSourceLocator;
use Rector\BetterReflection\SourceLocator\Type\EvaledCodeSourceLocator;
use Rector\BetterReflection\SourceLocator\Type\MemoizingSourceLocator;
use Rector\BetterReflection\SourceLocator\Type\PhpInternalSourceLocator;
use Rector\BetterReflection\SourceLocator\Type\SingleFileSourceLocator;
use Rector\BetterReflection\SourceLocator\Type\SourceLocator;
use Rector\Exception\FileSystem\FileNotFoundException;
use SplFileInfo;
use Symplify\PackageBuilder\Composer\AutoloadFinder;
use Symplify\PackageBuilder\Parameter\ParameterProvider;

final class SourceLocatorFactory
{
    /**
     * @var Locator
     */
    private $locator;

    /**
     * @var StubSourceLocator
     */
    private $stubSourceLocator;

    /**
     * @var ParameterProvider
     */
    private $parameterProvider;

    public function __construct(
        Locator $locator,
        StubSourceLocator $stubSourceLocator,
        ParameterProvider $parameterProvider
    ) {
        $this->locator = $locator;
        $this->stubSourceLocator = $stubSourceLocator;
        $this->parameterProvider = $parameterProvider;
    }

    public function create(): SourceLocator
    {
        return $this->wrapInMemoizinhSourceLocator($this->createCommonLocators());
    }

    public function createWithFile(SplFileInfo $fileInfo): SourceLocator
    {
        return $this->wrapInMemoizinhSourceLocator(
            array_merge($this->createCommonLocators(), [$this->createFileSourceLocator($fileInfo)])
        );
    }

    private function createFileSourceLocator(SplFileInfo $fileInfo): SingleFileSourceLocator
    {
        $this->ensureFileExists($fileInfo);

        return new SingleFileSourceLocator($fileInfo->getRealPath(), $this->locator);
    }

    /**
     * @return SourceLocator[]
     */
    private function createCommonLocators(): array
    {
        $locators = [
            new PhpInternalSourceLocator($this->locator),
            new EvaledCodeSourceLocator($this->locator),
            new AutoloadSourceLocator($this->locator),
            $this->stubSourceLocator,
        ];

        $source = $this->parameterProvider->provideParameter('source');
        if ($source) {
            $vendorAutoload = AutoloadFinder::findNearDirectories($source);
            if ($vendorAutoload !== null) {
                $vendorAutoload = require $vendorAutoload;
                $locators[] = new ComposerSourceLocator($vendorAutoload, $this->locator);
            }
        }

        return $locators;
    }

    /**
     * @param SourceLocator[] $sourceLocators
     */
    private function wrapInMemoizinhSourceLocator(array $sourceLocators): MemoizingSourceLocator
    {
        return new MemoizingSourceLocator(new AggregateSourceLocator($sourceLocators));
    }

    private function ensureFileExists(SplFileInfo $fileInfo): void
    {
        if (file_exists($fileInfo->getRealPath())) {
            return;
        }

        throw new FileNotFoundException(sprintf(
            'File "%s" not found in "%s".',
            $fileInfo->getRealPath(),
            __CLASS__
        ));
    }
}
