
#include <gtest/gtest.h>

#include "core/Material.h"
#include "core/Section.h"

TEST(SectionTest, init)
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