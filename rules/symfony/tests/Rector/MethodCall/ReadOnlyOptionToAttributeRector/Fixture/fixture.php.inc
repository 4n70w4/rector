<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\FixtureRector\Fixture;

use Symfony\Component\Form\FormBuilder;

class Fixture
{
    function buildForm(FormBuilder $builder, array $options)
    {
        $builder->add('cuid', TextType::class, ['read_only' => true]);
    }
}

?>
-----
<?php

namespace Rector\Symfony\Tests\Rector\MethodCall\FixtureRector\Fixture;

use Symfony\Component\Form\FormBuilder;

class Fixture
{
    function buildForm(FormBuilder $builder, array $options)
    {
        $builder->add('cuid', TextType::class, ['attr' => ['readonly' => true]]);
    }
}

?>
