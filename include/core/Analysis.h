#pragma once

#include "Properties.h"
#include "Section.h"

class Analysis
{
public:
    Analysis();
    virtual ~Analysis();
};

class Uncracked : public Analysis
{
public:
    Uncracked(); // default constructor
    Uncracked &run(const ConcreteSection &propSet, float M, float N);
};

class Cracked : public Analysis
{
public:
    Cracked(); // default constructor
    Cracked &run(const ConcreteSection &section, float M, float N);
};