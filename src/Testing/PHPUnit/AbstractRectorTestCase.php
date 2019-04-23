<?php declare(strict_types=1);

namespace Rector\Testing\PHPUnit;

use Nette\Utils\FileSystem;
use Nette\Utils\Json;
use Nette\Utils\Strings;
use Rector\Application\FileProcessor;
use Rector\Configuration\Option;
use Rector\Exception\ShouldBeImplementedException;
use Rector\Exception\ShouldNotHappenException;
use Rector\HttpKernel\RectorKernel;
use Symfony\Component\Yaml\Yaml;
use Symplify\PackageBuilder\FileSystem\SmartFileInfo;
use Symplify\PackageBuilder\Parameter\ParameterProvider;
use Symplify\PackageBuilder\Tests\AbstractKernelTestCase;

abstract class AbstractRectorTestCase extends AbstractKernelTestCase
{
    /**
     * @var string
     */
    private const SPLIT_LINE = '#-----\n#';

    /**
     * @var FileProcessor
     */
    protected $fileProcessor;

    /**
     * @var ParameterProvider
     */
    protected $parameterProvider;

    /**
     * @var bool
     */
    private $autoloadTestFixture = true;

    protected function setUp(): void
    {
        $configFile = $this->provideConfig();

        if (! file_exists($configFile)) {
            throw new ShouldNotHappenException(sprintf(
                'Config "%s" for test "%s" was not found',
                $configFile,
                static::class
            ));
        }

        dump($configFile);

        $this->bootKernelWithConfigs(RectorKernel::class, [$configFile]);

        $this->fileProcessor = static::$container->get(FileProcessor::class);
        $this->parameterProvider = static::$container->get(ParameterProvider::class);
    }

    /**
     * @param mixed[] $files
     */
    public function doTestFilesWithoutAutoload(array $files): void
    {
        $this->autoloadTestFixture = false;
        $this->doTestFiles($files);
    }

    protected function provideConfig(): string
    {
        if ($this->getRectorClass() !== '') { // use local if not overloaded
            $fixtureHash = $this->createFixtureHash();
            $configFileTempPath = sprintf(sys_get_temp_dir() . '/rector_temp_tests/config_%s.yaml', $fixtureHash);

            // cache for 2nd run, similar to original config one
            if (file_exists($configFileTempPath)) {
                return $configFileTempPath;
            }

            $yamlContent = Yaml::dump([
                'services' => [
                    $this->getRectorClass() => $this->getRectorConfiguration() ?: null,
                ],
            ], Yaml::DUMP_OBJECT_AS_MAP);

            FileSystem::write($configFileTempPath, $yamlContent);

            return $configFileTempPath;
        }

        // to be implemented
        throw new ShouldBeImplementedException();
    }

    protected function getRectorClass(): string
    {
        // to be implemented
        return '';
    }

    /**
     * @return mixed[]
     */
    protected function getRectorConfiguration(): ?array
    {
        // to be implemented
        return null;
    }

    /**
     * @param string[] $files
     */
    protected function doTestFiles(array $files): void
    {
        // 1. original to changed content
        foreach ($files as $file) {
            $smartFileInfo = new SmartFileInfo($file);
            [$originalFile, $changedFile] = $this->splitContentToOriginalFileAndExpectedFile($smartFileInfo);
            $this->doTestFileMatchesExpectedContent($originalFile, $changedFile, $smartFileInfo->getRealPath());
        }

        $this->autoloadTestFixture = true;
    }

    protected function getTempPath(): string
    {
        return sys_get_temp_dir() . '/rector_temp_tests';
    }

    /**
     * @return string[]
     */
    private function splitContentToOriginalFileAndExpectedFile(SmartFileInfo $smartFileInfo): array
    {
        if (Strings::match($smartFileInfo->getContents(), self::SPLIT_LINE)) {
            // original → expected
            [$originalContent, $expectedContent] = Strings::split($smartFileInfo->getContents(), self::SPLIT_LINE);
        } else {
            // no changes
            $originalContent = $smartFileInfo->getContents();
            $expectedContent = $originalContent;
        }

        $originalFile = $this->createTemporaryPathWithPrefix($smartFileInfo, 'original');
        $expectedFile = $this->createTemporaryPathWithPrefix($smartFileInfo, 'expected');

        FileSystem::write($originalFile, $originalContent);
        FileSystem::write($expectedFile, $expectedContent);

        // file needs to be autoload PHPStan analyze
        if ($this->autoloadTestFixture) {
            require_once $originalFile;
        }

        return [$originalFile, $expectedFile];
    }

    private function doTestFileMatchesExpectedContent(
        string $originalFile,
        string $expectedFile,
        string $fixtureFile
    ): void {
        $this->parameterProvider->changeParameter(Option::SOURCE, [$originalFile]);

        $smartFileInfo = new SmartFileInfo($originalFile);

        // life-cycle trio :)
        $this->fileProcessor->parseFileInfoToLocalCache($smartFileInfo);
        $this->fileProcessor->refactor($smartFileInfo);
        $changedContent = $this->fileProcessor->printToString($smartFileInfo);

        $this->assertStringEqualsFile($expectedFile, $changedContent, 'Caused by ' . $fixtureFile);
    }

    private function createTemporaryPathWithPrefix(SmartFileInfo $smartFileInfo, string $prefix): string
    {
        $hash = Strings::substring(md5($smartFileInfo->getRealPath()), 0, 5);

        return sprintf($this->getTempPath() . '/%s_%s_%s', $prefix, $hash, $smartFileInfo->getBasename('.inc'));
    }

    private function createFixtureHash(): string
    {
        return Strings::substring(
            md5($this->getRectorClass() . Json::encode($this->getRectorConfiguration())),
            0,
            10
        );
    }
}
