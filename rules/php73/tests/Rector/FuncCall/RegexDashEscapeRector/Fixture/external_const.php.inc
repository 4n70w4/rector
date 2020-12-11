<?php

namespace Rector\Php73\Tests\Rector\FuncCall\RegexDashEscapeRector\Fixture;

use Nette\Utils\Strings;

class ExternalConst
{
    const EXTERNAL_NON_COMPAT_PATTERN = '#[\w-()]#';
}

class AnotherExternalClass
{
    public function run()
    {
        Strings::match('...', ExternalConst::EXTERNAL_NON_COMPAT_PATTERN);
    }
}

?>
-----
<?php

namespace Rector\Php73\Tests\Rector\FuncCall\RegexDashEscapeRector\Fixture;

use Nette\Utils\Strings;

class ExternalConst
{
    const EXTERNAL_NON_COMPAT_PATTERN = '#[\w\-()]#';
}

class AnotherExternalClass
{
    public function run()
    {
        Strings::match('...', ExternalConst::EXTERNAL_NON_COMPAT_PATTERN);
    }
}

?>
