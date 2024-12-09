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
    : concrete_(concrete), props_(props), rebars_(rebars) {};

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

const float ConcreteSection::d()
{
    return props_.h - props_.dt;
};

const float ConcreteSection::n()
{
    return props_.Es / props_.Ec;
};

const float ConcreteSection::n1()
{
    return (props_.Es / props_.Ec) - 1;
};
