<?php declare (strict_types=1);

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

final class RemoveEmptyTemplateWithThisRenderController extends AbstractController
{
    /**
     * @Template()
     */
    public function indexAction()
    {
        return $this->render('AppBundle:ClassWithNamedService25:index.html.twig');
    }
}

?>
-----
<?php declare (strict_types=1);

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

final class RemoveEmptyTemplateWithThisRenderController extends AbstractController
{
    public function indexAction(): \Symfony\Component\HttpFoundation\Response
    {
        return $this->render('AppBundle:ClassWithNamedService25:index.html.twig');
    }
}

?>
