#include "core/Analysis.h"
#include "core/Material.h"
#include "core/Properties.h"
#include "core/Rebar.h"
#include "core/Section.h"
#include <map>

Section::Section() {
};

// const bool Section::compressionTop()
// {
//     return compressionTop_;
// };

// void Section::updateCompressionTop(bool compressionTop)
// {
//     compressionTop_ = compressionTop;
// };

ConcreteSection::ConcreteSection(const Concrete &concrete, const props &propSet, const std::map<const char *, Rebar *> &rebars)
    : concrete_(concrete), props_(propSet), rebars_(rebars) {
      };

const Uncracked &ConcreteSection::uncracked()
{
    return uncracked_;
};

const Cracked &ConcreteSection::cracked()
{
    return cracked_;
};

const Concrete &ConcreteSection::concrete()
{
    return concrete_;
};

const props ConcreteSection::getProps()
{
    return props_;
};

const std::map<const char *, Rebar *> ConcreteSection::rebars()
{
    return rebars_;
};

const char *ConcreteSection::state()
{
    return state_;
};

void ConcreteSection::updateState(float M, float N) {
    // TODO
    // run Uncracked Analysis
    // Check status and stresses
};

float ConcreteSection::calculateRf()
{
    float fs;
    double I2;
    // Calculate Rf
    if (this->state() == "Uncracked")
    {
        // Uncracked state
        fs = 0.0;
        I2 = 0.0;
    }
    else
    {
        // fs = max fstop and fsbot
        // I2 = section I2 at the given state
        fs = 0.0;
        I2 = 0.0;
    }

    return 0.0;
};

double ConcreteSection::crackingMoment()
{
    // TODO
    // Calculate cracking moment
    return 0.0;
};
