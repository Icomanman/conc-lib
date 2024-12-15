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

    const bool compressionTop();
    void updateCompressionTop(bool compressionTop);

private:
    bool compressionTop_;
};

class ConcreteSection : public Section
{

public:
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

    const char *state_ = "uninitialized";
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