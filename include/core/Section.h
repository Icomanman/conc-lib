#pragma once
#include "Material.h"

struct SectionProps
{
    float b = 300.0;
    float h = 500.0;
    float cover = 0.0;
    float Ast = 0.0;
    float Asb = 0.0;
};

class Section
{
public:
    Section(SectionProps &props, Concrete &concrete, Steel &steel);

    bool compressionTop();
    SectionProps &props();
    Concrete &concrete();
    Steel &steel();

    void updateCompressionTop(bool compressionTop);
    void updateProps(SectionProps &props);

private:
    bool _compressionTop;
    SectionProps _props;
    Concrete _concrete;
    Steel _steel;
};

class ConcreteSection : public Section
{
};

class SteelSection : public Section
{
};