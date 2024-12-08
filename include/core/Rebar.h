#pragma once
#include "core/Material.h"

class Rebar
{

public:
    // name, fy, E, cThExp, poisson
    static const Steel defaultSteel;
    static const int defaultDiameters[];

    Rebar(const Steel &steel = defaultSteel, float diameter, float spacing, char *layer = nullptr);

    const Steel &steel;
    float diameter;
    float spacing;

    float calcArea();
    float calcDepth();

    const char *getLayer();
    void setLayer(char *layer);

private:
    char *layer_;
};