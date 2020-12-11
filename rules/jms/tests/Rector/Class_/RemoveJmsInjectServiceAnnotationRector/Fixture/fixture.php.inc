<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use JMS\DiExtraBundle\Annotation as DI;

/**
 * @DI\Service("email.web.services.subscribe_token", public=true)
 */
class SomeClass
{
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use JMS\DiExtraBundle\Annotation as DI;

class SomeClass
{
}

?>
