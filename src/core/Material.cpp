#include <stdio.h>
#include "core/Material.h"
#include "core/Material.h"

Material::Material(const char *name, float youngModulus, double thermalExpansion, float poissonRatio)
    : name(name),
      E(youngModulus),
      cThExp(thermalExpansion),
      poisson(poissonRatio)
{
}

Concrete::Concrete(const char *name, float youngModulus, double thermalExpansion, float poissonRatio, float fc)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      _fc(fc)
{
}

void Concrete::setMisc(const ConcreteProps &props)
{
    _misc = props;
}

const ConcreteProps Concrete::misc()
{
    return _misc;
}
const float Concrete::fc()
{
    return _fc;
}

Steel::Steel(const char *name, float youngModulus, double thermalExpansion, float poissonRatio, float fy, float fu)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      _fy(fy)
{
}