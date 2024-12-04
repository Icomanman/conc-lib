#pragma once
#include "Material.h"

struct SectionProps
{
    double b;
    double h;
    double cover;
};

class Section
{
public:
    Section(SectionProps &props, Concrete &concrete, Steel &steel);
    ~Section();
    // void setSectionName(const char *name);
    // void setSectionSize(int size);
    // void setSectionData(const char *data);
    // const char *getSectionName();
    // int getSectionSize();
    // const char *getSectionData();
};