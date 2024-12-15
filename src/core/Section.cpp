#include "core/Analysis.h"
#include "core/Section.h"
#include "core/Material.h"
#include <map>

const bool Section::compressionTop()
{
    return compressionTop_;
};

void Section::updateCompressionTop(bool compressionTop)
{
    compressionTop_ = compressionTop;
};

ConcreteSection::ConcreteSection(const Concrete &concrete, const properties &props, const std::map<const char *, rebar> &rebars)
    : concrete_(concrete), props_(props), rebars_(rebars) {
      };

const Uncracked &ConcreteSection::uncracked()
{
    return uncracked_;
};

// const Cracked *ConcreteSection::cracked()
// {
//     return cracked_;
// };

const Concrete &ConcreteSection::concrete()
{
    return concrete_;
};

const ConcreteSection::properties ConcreteSection::props()
{
    return props_;
};

const std::map<const char *, rebar> ConcreteSection::rebars()
{
    return rebars_;
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
