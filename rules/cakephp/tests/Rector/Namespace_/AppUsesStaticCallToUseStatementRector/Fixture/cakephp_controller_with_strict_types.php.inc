<?php

declare(strict_types=1);

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

\App::uses('Component', 'Controller');

class CakeControllerWithStrictTypes
{
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Cake\Controller\Component;

class CakeControllerWithStrictTypes
{
}

?>
