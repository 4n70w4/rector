<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Rector\PHPUnit\Tests\Rector\Class_\SelfContainerGetMethodCallFromTestToInjectPropertyRector\Source\RandomElasticClient;
use Rector\PHPUnit\Tests\Rector\Class_\SelfContainerGetMethodCallFromTestToInjectPropertyRector\Source\TestCaseWithGetContainer;

class FromSetUpToInject extends TestCaseWithGetContainer
{
    /**
     * @var RandomElasticClient
     */
    private $elasticsearchClient;

    protected function setUp(): void
    {
        $this->elasticsearchClient = $this->getContainer()->get(RandomElasticClient::class);
    }

    public function testSomething()
    {
        $this->elasticsearchClient->init();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Rector\PHPUnit\Tests\Rector\Class_\SelfContainerGetMethodCallFromTestToInjectPropertyRector\Source\RandomElasticClient;
use Rector\PHPUnit\Tests\Rector\Class_\SelfContainerGetMethodCallFromTestToInjectPropertyRector\Source\TestCaseWithGetContainer;

class FromSetUpToInject extends TestCaseWithGetContainer
{
    /**
     * @var RandomElasticClient
     * @inject
     */
    private $elasticsearchClient;

    protected function setUp(): void
    {
    }

    public function testSomething()
    {
        $this->elasticsearchClient->init();
    }
}

?>
