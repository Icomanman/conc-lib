#include <gtest/gtest.h>
#include "../include/core/Analysis.h"
#include "../include/core/Material.h"
#include "../include/core/Rebar.h"
#include "../include/core/Section.h"

TEST(ConcreteTest, Fc)
{
    Concrete concrete("Concrete", 30, 30000, 0.000011, 0.17);
    EXPECT_EQ(concrete.fc(), 30);
}
