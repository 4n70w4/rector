<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\RedirectToRouteRector\Fixture;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class Fixture3
{
    public function someAction()
    {
        return $this->redirect($this->generateUrl('something', ['id' => $id]), 301);
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\RedirectToRouteRector\Fixture;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class Fixture3
{
    public function someAction()
    {
        return $this->redirectToRoute('something', ['id' => $id], 301);
    }
}

?>
