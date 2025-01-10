
#include <gtest/gtest.h>
#include <iostream>
#include <math.h>

#include "core/Material.h"
#include "core/Properties.h"
#include "core/Rebar.h"
#include "core/Section.h"

class SectionTest : public ::testing::Test
{
protected:
    const int fc = 30;
    const float Ec = 30000;
    const float cThexp = 0.000011;
    const float v = 0.17;
    const char *concreteName = "fc30";
    const float diameter = 20;
    const float spacing = 100;
    const float b = 300;
    const float h = 600;

    Concrete fc30;
    Steel fy414;
    Rebar rebar;
    concreteSectionProps props;
    std::map<const char *, Rebar *> rebarMap;

    SectionTest() : fc30(fc, concreteName, Ec, cThexp, v),
                    fy414(414, "fy414", 200000, 0.000012, 0.3),
                    rebar(fy414, diameter, spacing, "bottom")
    {
        rebarMap = {{"bottom", &rebar}};

        props = {
            .compressionTop = false,
            .Ast = rebar.calcArea(),
            .Asb = rebar.calcArea(),
            .b = b,
            .db = diameter,
            .dt = diameter,
            .Ec = fc30.modulus(),
            .Es = fy414.modulus(),
            .h = h,
            .fctm = fc30.fc(),
            .fct5 = fc30.fc(),
        };

        props.Ag = b * h;
        props.Ig = b * pow(h, 3) / 12;
    }
};

TEST_F(SectionTest, Constructor)
{
    ConcreteSection section(fc30, props, rebarMap);
};

TEST_F(SectionTest, Props_struct)
{
    printf("Ast: %f\n", props.Ast);
};