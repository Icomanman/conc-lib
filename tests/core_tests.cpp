#include <gtest/gtest.h>
#include "core/Analysis.h"
#include "core/Material.h"
#include "core/Rebar.h"
#include "core/Section.h"

const int fc = 30;
const int Ec = 30000;
const float cThexp = 0.000011;
const float v = 0.17;
const char *concreteName = "fc30";

TEST(ConcreteTest, Fc)
{
    Concrete concrete(fc, concreteName, Ec, cThexp, v);
    EXPECT_EQ(concrete.fc(), fc);
    EXPECT_EQ(concrete.modulus(), Ec);
    EXPECT_EQ(concrete.thermalExpansion(), cThexp);
    EXPECT_EQ(concrete.poisonRatio(), v);
    EXPECT_EQ(concrete.getName(), concreteName);
}
