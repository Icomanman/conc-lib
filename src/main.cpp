#include <iostream>
#include "core/Material.h"
#include "core/Section.h"

int main(void)
{
    MaterialProps concreteProps = {25000, 0.00001, 0.2};
    MaterialProps steelProps = {200000, 0.00001, 0.2};
    SectionProps props = {350, 500, 50};

    Concrete concrete("fc27", concreteProps.E, concreteProps.cThExp, concreteProps.poisson, 27.0);
    Steel steel("G400", steelProps.E, steelProps.cThExp, steelProps.poisson, 400.0);

    Section section(props, concrete, steel);

    std::cout << "Section name: " << concrete.getName() << std::endl;
    return 1;
}