<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class StockRepository
{
    public function filter(Stock\Query $query)
    {
        /** @var Stock\Query $query */
        $query = 5;

        if (!($query instanceof Stock\Querying\Query)) {
            throw new \InvalidArgumentException('Wrong query provided');
        }

        /** @var Querying\Query $query */
        $builder = $this->createBuilder();
        $query->build($builder);
    }

    public function multiDoc()
    {
        /** @var \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Connection $connection */
        $connection = $this->registry->getConnection();

        /** @var \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Connection $connection */
        $connection = $this->registry->getConnection();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Stock\Query;
use InvalidArgumentException;
final class StockRepository
{
    public function filter(Query $query)
    {
        /** @var Query $query */
        $query = 5;

        if (!($query instanceof Stock\Querying\Query)) {
            throw new InvalidArgumentException('Wrong query provided');
        }

        /** @var Querying\Query $query */
        $builder = $this->createBuilder();
        $query->build($builder);
    }

    public function multiDoc()
    {
        /** @var Connection $connection */
        $connection = $this->registry->getConnection();

        /** @var Connection $connection */
        $connection = $this->registry->getConnection();
    }
}

?>
