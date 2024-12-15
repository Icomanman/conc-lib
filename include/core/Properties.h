#pragma once
#include "Material.h"

struct sectionProps
{
    float Ag = 0.0;
    double Ig = 0.0;
};

struct props : sectionProps
{
    float Ast = 0.0;
    float Asb = 0.0;
    float Ad = 0.0;
    float b = 0.0;
    float db = 0.0;
    float dt = 0.0;
    float Ec = 0.0;
    float Es = 0.0;
    float h = 0.0;
};