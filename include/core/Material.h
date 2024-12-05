#pragma once

struct MaterialProps
{
    float E;
    double cThExp;
    float poisson;
};

struct ConcreteProps
{
    int t0 = 28;                     // 28 days
    float shrinkageStrain = 0.00025; // 250 microstrain
    float creepCoefficient = 1.5;
    float T1 = 20; // 20 degrees Celsius
    float T2 = 30; // 30 degrees Celsius
    float R1 = 0.5;
    float R2 = 0.5;
};

class Material
{
public:
    Material(const char *name, float youngModulus, double thermalExpansion, float poissonRatio);
    virtual ~Material();

    float poisonRatio();
    float modulus();
    double thermalExpansion();
    const char *getName();

protected:
    const char *name;
    float poisson;
    float E;
    double cThExp;
};

class Concrete : public Material
{
public:
    Concrete(const char *name, float youngModulus, double thermalExpansion, float poissonRatio, float fc);

    const float fc();
    const ConcreteProps misc();

    void setMisc(const ConcreteProps &props);

private:
    float _fc;
    ConcreteProps _misc;
};

class Steel : public Material
{
public:
    Steel(const char *name, float youngModulus, double thermalExpansion, float poissonRatio, float fy, float fu = 600);

    const float fy();
    const float fu();

private:
    float _fy;
    float _fu;
};