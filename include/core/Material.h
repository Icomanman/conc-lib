#pragma once

struct ConcreteProps
{
    int t0 = 28;                     // 28 days
    float shrinkageStrain = 0.00025; // 250 microstrain
    float creepCoefficient = 1.5;
    float T1 = 20; // 20 degrees Celsius
    float T2 = 30; // 30 degrees Celsius
    float R1 = 0.5;
    float R2 = 0.4;
};

class Material
{
public:
    Material(const char *name, const float youngsModulus, const float thermalExpansion, const float poissonRatio);

    const float modulus();
    const float poisonRatio();
    const float thermalExpansion();
    const char *getName();

private:
    const char *name_;
    const float cThExp_;
    const float E_;
    const float poisson_;
};

class Concrete : public Material
{
public:
    Concrete(const float fc, const char *name, const float youngsModulus, const float thermalExpansion, const float poissonRatio);

    const float fc();
    const ConcreteProps misc();

    void setMisc(const ConcreteProps &props);

private:
    const float fc_;
    ConcreteProps misc_;
};

class Steel : public Material
{
public:
    Steel(const float fy, const char *name, const float youngsModulus, const float thermalExpansion, const float poissonRatio, const float fu = 600.0);

    const float fy();
    const float fu();

private:
    float fy_;
    float fu_;
};