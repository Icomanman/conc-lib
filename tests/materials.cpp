#include <gtest/gtest.h>
#include "core/Analysis.h"
#include "core/Material.h"
#include "core/Rebar.h"
#include "core/Section.h"

TEST(ConcreteMaterial, Constructor)
{
    const int fc = 30;
    const int Ec = 30000;
    const float cThexp = 0.000011;
    const float v = 0.17;
    const char *concreteName = "fc30";

    Concrete concrete(fc, concreteName, Ec, cThexp, v);
    EXPECT_EQ(concrete.fc(), fc);
    EXPECT_EQ(concrete.modulus(), Ec);
    EXPECT_EQ(concrete.thermalExpansion(), cThexp);
    EXPECT_EQ(concrete.poisonRatio(), v);
    EXPECT_EQ(concrete.getName(), concreteName);
};

TEST(SteelMaterial, Constructor)
{
    const float fy = 414;
    const float fu = 600;
    const float Es = 198;
    const float cThexp = 0.00011;
    const float poisson = 0.3;

    Steel steel(fy, "fy414", Es, cThexp, poisson, fu);
    EXPECT_EQ(steel.fy(), fy);
    EXPECT_EQ(steel.modulus(), Es);
    EXPECT_EQ(steel.thermalExpansion(), cThexp);
    EXPECT_EQ(steel.poisonRatio(), poisson);
};