<?php declare(strict_types=1);

namespace Rector\Console;

use Jean85\PrettyVersions;
use Symfony\Component\Console\Application as SymfonyApplication;
use Symfony\Component\Console\Input\InputDefinition;
use Symfony\Component\Console\Input\InputOption;
use function Safe\getcwd;

final class Application extends SymfonyApplication
{
    /**
     * @var string
     */
    private const NAME = 'Rector';

    public function __construct()
    {
        parent::__construct(self::NAME, PrettyVersions::getVersion('rector/rector')->getPrettyVersion());
    }

    protected function getDefaultInputDefinition(): InputDefinition
    {
        $defaultInputDefinition = parent::getDefaultInputDefinition();

        $this->removeUnusedOptions($defaultInputDefinition);
        $this->addCustomOptions($defaultInputDefinition);

        return $defaultInputDefinition;
    }

    private function removeUnusedOptions(InputDefinition $inputDefinition): void
    {
        $options = $inputDefinition->getOptions();

        unset($options['quiet'], $options['version'], $options['no-interaction']);

        $inputDefinition->setOptions($options);
    }

    private function addCustomOptions(InputDefinition $inputDefinition): void
    {
        $inputDefinition->addOption(new InputOption(
            'config',
            'c',
            InputOption::VALUE_REQUIRED,
            'Path to config file.',
            getcwd() . '/rector.yml'
        ));

        $inputDefinition->addOption(new InputOption(
            'level',
            'l',
            InputOption::VALUE_REQUIRED,
            'Finds config by shortcut name.'
        ));
    }
}
