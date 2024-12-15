#include <iostream>
#include "core/Analysis.h"
#include "core/Material.h"
#include "core/Section.h"

Uncracked &Uncracked::run(const ConcreteSection &section, float M, float N)
{
    printf("> run: Uncracked\n");
};

Cracked &Cracked::run(const ConcreteSection &section, float M, float N) {

    // TODO
};