#include <iostream>
#include "core/Analysis.h"
#include "core/Material.h"
#include "core/Properties.h"
#include "core/Rebar.h"
#include "core/Section.h"

int main(void)
{
    MaterialProps concreteProps = {25000, 0.00001, 0.2};
    MaterialProps steelProps = {200000, 0.00001, 0.2};
    sectionProps props = {350, 500};

    const Concrete fc27("fc27", 27.0, concreteProps.E, concreteProps.cThExp, concreteProps.poisson);
    const Steel fy400("fy400", 400.0, steelProps.E, steelProps.cThExp, steelProps.poisson);
    Rebar typicalBar(fy400, 20.0, 150.0, "bottom");

    std::map<const char *, Rebar *> rebars;
    rebars["bottom"] = &typicalBar;

    // ConcreteSection section(fc27, props, rebars);

    return 1;
}