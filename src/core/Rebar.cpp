#include <math.h>

#include "core/Material.h"
#include "core/Rebar.h"

// static members
const Steel Rebar::defaultSteel(414.0, "default", 200.0, 0.00011, 0.17);
const int Rebar::defaultDiameters[] = {6, 8, 10, 12, 16, 20, 25, 32};

Rebar::Rebar(const Steel &steel, float diameter, float spacing, const char *layer)
    : steel(steel),
      diameter(diameter),
      spacing(spacing),
      layer_(layer)
{
}

float Rebar::calcArea(float b)
{
    return 0.25 * PI * pow(diameter, 2) * b / spacing;
}

float Rebar::calcDepth()
{
    return diameter / 2;
}

const char *Rebar::getLayer()
{
    return layer_;
}