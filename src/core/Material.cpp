#include <stdio.h>
#include "core/Material.h"
#include "core/Material.h"

Material::Material(const char *name, double youngModulus, double thermalExpansion, double poissonRatio)
    : name(name),
      E(youngModulus),
      cThExp(thermalExpansion),
      poisson(poissonRatio)
{
}

Material::~Material()
{
}

const char *Material::getName()
{
    return name;
}

Concrete::Concrete(const char *name, double poissonRatio, double youngModulus, double thermalExpansion, double fc)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      _fc(fc)
{
}

const double Concrete::fc()
{
    return _fc;
}

Steel::Steel(const char *name, double poissonRatio, double youngModulus, double thermalExpansion, double fy)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      _fy(fy)
{
}