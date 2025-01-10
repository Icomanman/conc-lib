#pragma once

#include <map>
#include <optional>

#include "Analysis.h"
#include "Material.h"
#include "Properties.h"
#include "Rebar.h"

enum SectionState
{
    UNINITIALISED,
    UNCRACKED,
    CRACKED,
    PURETENSION
};

class Section
{
public:
    Section();
};

class ConcreteSection : public Section
{

public:
    ConcreteSection(const Concrete &concrete, const concreteSectionProps &propSet, const std::map<const char *, Rebar *> &rebars);

    const Uncracked &uncracked();
    const Cracked &cracked();
    const Concrete &concrete();
    const concreteSectionProps getProps();
    const std::map<const char *, Rebar *> rebars();
    // const char *state();
    const SectionState state();

    const bool inTension();
    const bool fctmExceeded();
    const bool fctminExceeded();

    float calculateRf();
    void updateState(float M, float N);

private:
    std::optional<Uncracked> uncracked_;
    std::optional<Cracked> cracked_;

    Concrete concrete_;
    concreteSectionProps props_;
    std::map<const char *, Rebar *> rebars_;

    // char *state_ = "uninitialized";
    SectionState state_ = UNINITIALISED;
    float d_;
    float n_;
    float n1_;
    bool inTension_ = false;
    bool fctmExceeded_ = false;
    bool fctminExceeded_ = false;

    double crackingMoment();
};

class SteelSection : public Section
{
    // TODO
};