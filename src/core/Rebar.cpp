#include "Material.h"
#include "Rebar.h"

// static members
const Steel Rebar::defaultSteel = Steel("default", 414.0, 200.0, 414.0, 0.17);
const int Rebar::defaultDiameters[] = {6, 8, 10, 12, 16, 20, 25, 32};

Rebar::Rebar(const Steel &steel, float diameter, float spacing, char *layer)
    : steel(steel),
      diameter(diameter),
      spacing(spacing),
      layer_(layer)
{
}

float Rebar::calcArea()
{
    return 3.14159 * diameter * diameter / 4;
}

float Rebar::calcDepth()
{
    return diameter / 2;
}

const char *Rebar::getLayer()
{
    return layer_;
}

void Rebar::setLayer(char *layer)
{
    layer_ = layer;
}