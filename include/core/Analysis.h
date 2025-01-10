#pragma once

#include "Properties.h"

class Analysis
{
public:
    Analysis();
    bool isCompressionTop();
    void updateCompressionTop(bool compressionTop);

    double C;
    double fctop;
    double fcbot;
    double fstop;
    double fsbot;
    double etop;
    double ebot;
    double g;

private:
    bool compressionTop_ = true;
};

class Uncracked : public Analysis
{
public:
    static const char *Stype;
    Uncracked(const concreteSectionProps &propSet, const float M, const float N);
};

class Cracked : public Analysis
{
public:
    static const char *Stype;
    Cracked(const concreteSectionProps &propSet, const float M, const float N, const bool compressionTop);
};

class PureTension : public Analysis
{
public:
    static const char *Stype;
    PureTension(const concreteSectionProps &propSet, const float M, const float N, const bool compressionTop);
};