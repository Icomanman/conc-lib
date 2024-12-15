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
    const std::map<const char *, rebar> state;
    ConcreteSection(const Concrete &concrete, const props &propSet, const std::map<const char *, Rebar *> &rebars);

    const Uncracked &uncracked();
    const Cracked &cracked();
    const Concrete &concrete();
    const props getProps();
    const std::map<const char *, Rebar *> rebars();
    const char *state();

    float calculateRf();
    void updateState(float M, float N);

private:
    Uncracked uncracked_;
    Cracked cracked_;

    Concrete concrete_;
    props props_;
    std::map<const char *, Rebar *> rebars_;
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