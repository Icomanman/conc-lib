#pragma once
#include "Material.h"

struct rebar
{
    Material &material;

    float cover;
    float diameter;
    char *name;
    float spacing;
};

struct rebars
{
    rebar &bottom;
    rebar &top;
};

struct sectionProps
{
    float Ag = 0.0;
    double Ig = 0.0;
};

class Section
{
public:
    Section();
    virtual ~Section();

    const bool compressionTop();
    void updateCompressionTop(bool compressionTop);

private:
    bool compressionTop_;
};

class ConcreteSection : public Section
{
public:
    ConcreteSection(Concrete &concrete);
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

    const Concrete &concrete();
    const float d();
    const float n();
    const float n1();

    double crackingMoment();

private:
    Concrete concrete_;
    float d_;
    float n_;
    float n1_;
};

class SteelSection : public Section
{
    // TODO
};