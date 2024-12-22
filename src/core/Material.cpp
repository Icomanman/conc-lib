#include <stdio.h>

#include "core/Material.h"
#include "core/Material.h"

Material::Material(const char *name, float youngsModulus, float thermalExpansion, float poissonRatio)
    : name_(name),
      E_(youngsModulus),
      cThExp_(thermalExpansion),
      poisson_(poissonRatio)
{
}

const float Material::modulus()
{
    return E_;
}

const float Material::thermalExpansion()
{
    return cThExp_;
}

const float Material::poisonRatio()
{
    return poisson_;
}

const char *Material::getName()
{
    return name_;
}

Concrete::Concrete(const float fc, const char *name, const float youngsModulus, const float thermalExpansion, const float poissonRatio)
    : fc_(fc), Material(name, youngsModulus, thermalExpansion, poissonRatio)
{
}

void Concrete::setMisc(const ConcreteProps &props)
{
    misc_ = props;
}

const ConcreteProps Concrete::misc()
{
    return misc_;
};

const float Concrete::fc()
{
    return fc_;
}

Steel::Steel(const float fy, const char *name, const float youngsModulus, const float thermalExpansion, const float poissonRatio, const float fu)
    : fy_(fy),
      Material(name, youngsModulus, thermalExpansion, poissonRatio),
      fu_(fu)
{
}