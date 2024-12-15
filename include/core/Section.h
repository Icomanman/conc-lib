#pragma once
#include <map>
#include "Analysis.h"
#include "Material.h"
#include "Properties.h"
#include "Rebar.h"

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
    const std::map<const char *, rebar> state;
    ConcreteSection(const Concrete &concrete, const properties &props, const std::map<const char *, rebar> &rebars);

    const Uncracked &uncracked();
    const Cracked &cracked();
    const Concrete &concrete();
    const properties props();
    const std::map<const char *, rebar> rebars();
    const char *state();

    float calculateRf();
    void updateState(float M, float N);

private:
    Uncracked uncracked_;
    Cracked cracked_;

    Concrete concrete_;
    properties props_;
    std::map<const char *, rebar> rebars_;
    float d_;
    float n_;
    float n1_;
    bool inTension_;

    double crackingMoment();
};

class SteelSection : public Section
{
    // TODO
};