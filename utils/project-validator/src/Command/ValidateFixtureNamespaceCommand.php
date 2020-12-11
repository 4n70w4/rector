<?php

declare(strict_types=1);

namespace Rector\Utils\ProjectValidator\Command;

use Nette\Utils\FileSystem;
use Nette\Utils\Strings;
use const PATHINFO_DIRNAME;
use Rector\Core\Configuration\Option;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;
use Symfony\Component\Console\Style\SymfonyStyle;
use Symfony\Component\Finder\Finder;
use Symplify\PackageBuilder\Console\ShellCode;
use Symplify\SmartFileSystem\Finder\FinderSanitizer;
use Symplify\SmartFileSystem\SmartFileInfo;
use Rector\PSR4\Composer\PSR4AutoloadPathsProvider;

final class ValidateFixtureNamespaceCommand extends Command
{
    /**
     * @var FinderSanitizer
     */
    private $finderSanitizer;

    /**
     * @var SymfonyStyle
     */
    private $symfonyStyle;

    /**
     * @var PSR4AutoloadPathsProvider
     */
    private $psr4AutoloadPathsProvider;

    public function __construct(FinderSanitizer $finderSanitizer, PSR4AutoloadPathsProvider $psr4AutoloadPathsProvider, SymfonyStyle $symfonyStyle)
    {
        $this->finderSanitizer = $finderSanitizer;
        $this->symfonyStyle = $symfonyStyle;
        $this->psr4AutoloadPathsProvider = $psr4AutoloadPathsProvider;

        parent::__construct();
    }

    protected function configure(): void
    {
        $this->addOption(Option::FIX, null, null, 'Fix found violations.');
        $this->setDescription('[CI] Validate tests fixtures namespace');
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $fixtureFiles = $this->getFixtureFiles();
        $incorrectNamespaceFiles = [];
        $incorrectNamespaces = [];
        $incorrectFileContents = [];

        $currentDirectory = getcwd();
        foreach ($fixtureFiles as $fixtureFile) {
            // 1. geting expected namespace ...
            [$directoryNamespace, $relativePath] = explode('/tests/', (string) $fixtureFile);
            if ($directoryNamespace !== getcwd()) {
                echo ltrim(substr($directoryNamespace, strlen($currentDirectory)) . '/tests', '/');die;
            }

            $relativePath = ltrim(pathinfo($relativePath, PATHINFO_DIRNAME), '\/');
            $backslashedPath = str_replace('/', '\\', $relativePath);
            $expectedNamespace = $this->getExpectedNamespace($backslashedPath);

            if ($expectedNamespace === null) {
                continue;
            }

            // 2. reading file contents
            $fileContent = (string) FileSystem::read((string) $fixtureFile);
            // @see https://regex101.com/r/5KtBi8/2
            $matchAll = Strings::matchAll($fileContent, '#^namespace (.*);$#msU');

            if ($matchAll === []) {
                continue;
            }

            if ($this->isFoundIncorrectNamespace($matchAll, $expectedNamespace)) {
                continue;
            }

            // 3. collect files with incorrect namespace
            $incorrectNamespaceFiles[] = (string) $fixtureFile;
            $incorrectNamespace = $this->getIncorrectNamespace($matchAll, $expectedNamespace);

            if ($input->getOption(Option::FIX)) {
                $this->fixNamespace((string) $fixtureFile, $incorrectNamespace, $fileContent, $expectedNamespace);
            }
        }

        if ($incorrectNamespaceFiles !== []) {
            $this->symfonyStyle->listing($incorrectNamespaceFiles);

            $message = sprintf(
                'Found %d fixture files with invalid namespace which not follow psr-4 defined in composer.json',
                count($incorrectNamespaceFiles)
            );

            if (! $input->getOption(Option::FIX)) {
                $message .= ', Just add "--fix" to console command and rerun to apply.';
                $this->symfonyStyle->error($message);
                return ShellCode::ERROR;
            }

            $this->symfonyStyle->success($message . ' and all fixtures are corrected', );
            return ShellCode::SUCCESS;
        }

        $this->symfonyStyle->success('All fixtures are correct');
        return ShellCode::SUCCESS;
    }

    private function fixNamespace(string $incorrectNamespaceFile, string $incorrectNamespace, string $incorrectFileContent, string $expectedNamespace)
    {
        $newContent = str_replace($incorrectNamespace, $expectedNamespace, $incorrectFileContent);
        FileSystem::write((string) $incorrectNamespaceFile, $newContent);
    }

    /**
     * @return SmartFileInfo[]
     */
    private function getFixtureFiles(): array
    {
        $finder = new Finder();
        $finder = $finder->files()
            ->name('#\.php\.inc$#')
            ->notName('#empty_file\.php\.inc$#')
            ->path('#/Fixture/#')
            ->notPath('#/blade-template/#')
            ->notPath('#bootstrap_names\.php\.inc#')
            ->in(__DIR__ . '/../../../../tests')
            ->in(__DIR__ . '/../../../../packages/*/tests')
            ->in(__DIR__ . '/../../../../rules/*/tests');

        return $this->finderSanitizer->sanitize($finder);
    }

    private function getExpectedNamespace(string $backslashedPath): ?string
    {
        if (strpos($backslashedPath, 'tests\\') === 0) {
            return 'Rector\Core\Tests' . Strings::substring($backslashedPath, 5);
        }

        if (strpos($backslashedPath, 'rules\\') === 0) {
            $namespaces = explode('\\', $backslashedPath);
            unset($namespaces[0]);
            $namespaces[1] = ucfirst($namespaces[1]);
            $namespaces[1] = Strings::replace($namespaces[1], '#-(\w)#', function ($value): string {
                if (is_array($value)) {
                    return strtoupper($value[1]);
                }

                return strtoupper($value);
            });
            $namespaces[2] = 'Tests';

            return 'Rector\\' . implode('\\', $namespaces);
        }

        return null;
    }

    /**
     * @param array<int, array<int, string>> $matchAll
     */
    private function isFoundIncorrectNamespace(array $matchAll, string $expectedNamespace): bool
    {
        $countMatchAll = count($matchAll);
        if ($countMatchAll === 1 && $matchAll[0][1] === $expectedNamespace) {
            return true;
        }

        return $countMatchAll === 2 && $matchAll[0][1] === $expectedNamespace && $matchAll[1][1] === $expectedNamespace;
    }

    private function getIncorrectNamespace(array $matchAll, string $expectedNamespace): string
    {
        $countMatchAll = count($matchAll);

        if ($countMatchAll === 1) {
            return $matchAll[0][1];
        }

        return $matchAll[0][1] !== $expectedNamespace
            ? $matchAll[0][1]
            : $matchAll[1][1];
    }
}
