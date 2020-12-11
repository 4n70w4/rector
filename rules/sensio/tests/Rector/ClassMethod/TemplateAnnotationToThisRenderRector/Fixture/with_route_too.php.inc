<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Annotation\Route;

class WithRouteToo extends AbstractController
{
    /**
     * @Route("/change", name="facility_change")
     * @Template("PAPPUserBundle:Facility:facility.html.twig")
     */
    public function index()
    {
        return [];
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Annotation\Route;

class WithRouteToo extends AbstractController
{
    /**
     * @Route("/change", name="facility_change")
     */
    public function index(): \Symfony\Component\HttpFoundation\Response
    {
        return $this->render('PAPPUserBundle:Facility:facility.html.twig');
    }
}

?>
