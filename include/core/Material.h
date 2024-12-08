#pragma once

struct MaterialProps
{
    float cThExp;
    float E;
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
    Material(const char *name, float youngModulus, float thermalExpansion, float poissonRatio);

    float modulus();
    float poisonRatio();
    float thermalExpansion();
    const char *getName();

protected:
    const char *name;
    float cThExp;
    float E;
    float poisson;
};

class Concrete : public Material
{
public:
    Concrete(const char *name, float fc, float youngModulus, float thermalExpansion, float poissonRatio);

    const float fc();
    const ConcreteProps misc();

    void setMisc(const ConcreteProps &props);

private:
    float fc_;
    ConcreteProps misc_;
};

class Steel : public Material
{
public:
    Steel(const char *name, float fy, float youngModulus, float thermalExpansion, float poissonRatio, float fu = 600.0);

    const float fy();
    const float fu();

private:
    float fy_;
    float fu_;
};