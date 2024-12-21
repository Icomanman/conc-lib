#pragma once

#include "Properties.h"

class Analysis
{
public:
    Analysis();
    bool isCompressionTop();
    void updateCompressionTop(bool compressionTop);

private:
    bool compressionTop_ = true;
};

class Uncracked : public Analysis
{

public:
    static const char *Stype;
    Uncracked(); // default constructor
    Uncracked &run(const props &propSet, const float M, const float N);

    double C;
    double fctop;
    double fcbot;
    double fstop;
    double fsbot;
    double etop;
    double ebot;
    double g;
};

class Cracked : public Analysis
{

public:
    static const char *Stype;
    Cracked(); // default constructor
    Cracked &run(const props &propSet, const float M, const float N, const bool compressionTop);

    double C;
    double fctop;
    double fcbot;
    double fstop;
    double fsbot;
    double etop;
    double ebot;
    double g;
};

class PureTension : public Analysis
{

public:
    static const char *Stype;
    PureTension(const props &propSet, const float M, const float N, const bool compressionTop);

    double C;
    double fctop;
    double fcbot;
    double fstop;
    double fsbot;
    double etop;
    double ebot;
    double g;
};