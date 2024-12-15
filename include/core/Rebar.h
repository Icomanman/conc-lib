#pragma once
#include "core/Material.h"

struct rebar
{
    Material &material;

    float layerDistance;
    float diameter;
    char *name;
    float spacing;
};

class Rebar
{

public:
    // name, fy, E, cThExp, poisson
    static const Steel defaultSteel;
    static const int defaultDiameters[];

    Rebar(const Steel &steel, float diameter, float spacing, char *layer = nullptr);

    const Steel &steel = defaultSteel;
    float diameter;
    float spacing;

    float calcArea();
    float calcDepth();

    const char *getLayer();
    void setLayer(char *layer);

private:
    char *layer_;
};