#pragma once
#include <map>
#include "Material.h"

struct rebar
{
    Material &material;

    float cover;
    float diameter;
    char *name;
    float spacing;
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
    struct properties : sectionProps
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

    ConcreteSection(const Concrete &concrete, const properties &props, const std::map<const char *, rebar> &rebars);

    const Concrete &concrete();
    const properties props();
    const std::map<const char *, rebar> rebars();
    const float d();
    const float n();
    const float n1();
    const char *state();

    float calculateRf();
    void updateState(float M, float N);

private:
    Concrete concrete_;
    properties props_;
    std::map<const char *, rebar> rebars_;
    float d_;
    float n_;
    float n1_;

    char *state_;

    double crackingMoment();
};

class SteelSection : public Section
{
    // TODO
};