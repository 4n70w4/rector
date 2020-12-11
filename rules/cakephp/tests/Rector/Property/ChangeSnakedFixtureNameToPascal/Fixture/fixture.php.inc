<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class ClassImportingFixturesWithSnakeCasedName
{
    protected $fixtures = [
        'app.users',
        'other_app.tags',
        'plugin.posts',
        'plugin.messages/deleted_messages',
    ];
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class ClassImportingFixturesWithSnakeCasedName
{
    protected $fixtures = [
        'app.Users',
        'other_app.Tags',
        'plugin.Posts',
        'plugin.Messages/DeletedMessages',
    ];
}

?>
