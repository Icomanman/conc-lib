#include <iostream>
#include "core/Analysis.h"
#include "core/Properties.h"

Analysis::Analysis() {
};

Uncracked::Uncracked() {
};

Uncracked &Uncracked::run(const props &propSet, float M, float N)
{
    printf("> run: Uncracked\n");
    return *this;
};

Cracked::Cracked() {
};

Cracked &Cracked::run(const props &propSet, float M, float N)
{
    return *this;
};