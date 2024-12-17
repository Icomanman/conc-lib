#pragma once

#include "Properties.h"

class Analysis
{
public:
    Analysis();
    bool isCompressionTop();
    void updateCompressionTop(bool compressionTop);

private:
    bool compressionTop_;
};

class Uncracked : public Analysis
{
public:
    Uncracked(); // default constructor
    Uncracked &run(const props &propSet, float M, float N);

    double C;
    double fctop;
    double fcbot;
    double fstop;
    double fsbot;
    double etop;
    double ebot;
    double g;
    char *Stype;
};

class Cracked : public Analysis
{
public:
    Cracked(); // default constructor
    Cracked &run(const props &propSet, float M, float N);
};