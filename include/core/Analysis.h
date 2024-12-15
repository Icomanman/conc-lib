#pragma once

#include "Properties.h"

class Analysis
{
public:
    Analysis();
};

class Uncracked : public Analysis
{
public:
    Uncracked(); // default constructor
    Uncracked &run(const props &propSet, float M, float N);
};

class Cracked : public Analysis
{
public:
    Cracked(); // default constructor
    Cracked &run(const props &propSet, float M, float N);
};