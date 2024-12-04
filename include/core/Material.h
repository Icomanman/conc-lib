#pragma once

struct MaterialProps
{
    double E;
    double cThExp;
    double poisson;
};

class Material
{
public:
    Material(const char *name, double youngModulus, double thermalExpansion, double poissonRatio);
    virtual ~Material();

    double poisonRatio();
    double modulus();
    double thermalExpansion();
    char *getName();

protected:
    char *name;
    double poisson;
    double E;
    double cThExp;
};

class Concrete : public Material
{
public:
    Concrete(const char *name, double poissonRatio, double youngModulus, double thermalExpansion, double fc);

    double fc();

private:
    double _fc;
};

class Steel : public Material
{
public:
    Steel(const char *name, double poissonRatio, double youngModulus, double thermalExpansion, double fy);

    double fy();

private:
    double _fy;
};