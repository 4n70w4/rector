<?php

namespace Rector\Sensio\Tests\Rector\ClassMethod\TemplateAnnotationToThisRenderRector\Fixture;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

class EmptyBody
{
    /**
     * @Template
     */
    public function indexAction()
    {
    }
}

?>
-----
<?php

namespace Rector\Sensio\Tests\Rector\ClassMethod\TemplateAnnotationToThisRenderRector\Fixture;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

class EmptyBody
{
    public function indexAction(): \Symfony\Component\HttpFoundation\Response
    {
        return $this->render('@App/Empty_Body/index.html.twig');
    }
}

?>
