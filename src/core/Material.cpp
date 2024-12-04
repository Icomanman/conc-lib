#include <stdio.h>
#include "core/Material.h"
#include "core/Material.h"

Material::Material(const char *name, double youngModulus, double thermalExpansion, double poissonRatio)
    : E(youngModulus),
      cThExp(thermalExpansion),
      poisson(poissonRatio)
{
}

Material::~Material()
{
}

const char *Material::getName()
{
    printf("> From Material: %s", name);
    return name;
}

Concrete::Concrete(const char *name, double poissonRatio, double youngModulus, double thermalExpansion, double fc)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      _fc(fc)
{
  printf("> Passed named via constructor: %s\n", name);
}

Steel::Steel(const char *name, double poissonRatio, double youngModulus, double thermalExpansion, double fy)
    : Material(name, youngModulus, thermalExpansion, poissonRatio),
      _fy(fy)
{
}