#include <map>
#include <optional>
#include <stdexcept>

#include "core/Analysis.h"
#include "core/Material.h"
#include "core/Properties.h"
#include "core/Rebar.h"
#include "core/Section.h"

Section::Section() {
};

ConcreteSection::ConcreteSection(const Concrete &concrete, const props &propSet, const std::map<const char *, Rebar *> &rebars)
    : concrete_(concrete), props_(propSet), rebars_(rebars) {
      };

const Uncracked &ConcreteSection::uncracked()
{
    if (uncracked_.has_value())
    {
        return *uncracked_;
    }
    else
    {
        throw std::runtime_error("Uncracked analysis not available");
    }
};

const Cracked &ConcreteSection::cracked()
{
    if (cracked_.has_value())
    {
        return *cracked_;
    }
    else
    {
        throw std::runtime_error("Cracked analysis not available");
    }
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

// const char *ConcreteSection::state()
const SectionState ConcreteSection::state()
{
    return state_;
};

const bool ConcreteSection::inTension()
{
    return inTension_;
};

const bool ConcreteSection::fctmExceeded()
{
    return fctmExceeded_;
};

const bool ConcreteSection::fctminExceeded()
{
    return fctminExceeded_;
};

void ConcreteSection::updateState(float M, float N)
{
    // Check status and stresses

    // run Uncracked Analysis
    // (*this).uncracked_ = Uncracked(props_, M, N);
    this->uncracked_ = Uncracked(props_, M, N);

    if (this->uncracked().fcbot > 0 || this->uncracked().fctop > 0)
    {
        this->state_ = SectionState::CRACKED;

        // TODO: set the fctm and fct5 boolean flags: 10 January 2025
    }
}

float ConcreteSection::calculateRf()
{
    float fs;
    double I2;
    // Calculate Rf
    if (this->state() == SectionState::UNCRACKED)
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
