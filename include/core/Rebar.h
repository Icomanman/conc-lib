#pragma once
#include "Material.h"

class Rebar
{

public:
    static const Steel defaultSteel;
    static const int defaultDiameters[];

    Rebar(const Steel &steel, float diameter, float spacing, const char *layer);

    const Steel &steel = defaultSteel;
    float diameter;
    float spacing;

    float calcArea();
    float calcDepth();

    const char *getLayer();

private:
    const char *layer_;
};