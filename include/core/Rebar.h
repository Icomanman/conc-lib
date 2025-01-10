#pragma once
#include "Material.h"

const double PI = 3.14159265358979323846;

class Rebar
{

public:
    static const Steel defaultSteel;
    static const int defaultDiameters[];

    Rebar(const Steel &steel, float diameter, float spacing, const char *layer);

    const Steel &steel = defaultSteel;
    float diameter;
    float spacing;

    float calcArea(float b = 1000);
    float calcDepth();

    const char *getLayer();

private:
    const char *layer_;
};