#include <stdio.h>
#include "core/Material.h"
#include "core/Material.h"

Material::Material(const char *name, float youngModulus, float thermalExpansion, float poissonRatio)
    : name(name),
      E(youngModulus),
      cThExp(thermalExpansion),
      poisson(poissonRatio)
{
}

Concrete::Concrete(const char *name, float fc, float youngModulus, float thermalExpansion, float poissonRatio)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      fc_(fc)
{
}

void Concrete::setMisc(const ConcreteProps &props)
{
    misc_ = props;
}

const ConcreteProps Concrete::misc()
{
    return misc_;
}
const float Concrete::fc()
{
    return fc_;
}

Steel::Steel(const char *name, float fy, float youngModulus, float thermalExpansion, float poissonRatio, float fu)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      fy_(fy)
{
}