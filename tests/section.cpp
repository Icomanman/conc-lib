
#include <gtest/gtest.h>
#include <iostream>
#include <math.h>

#include "core/Material.h"
#include "core/Properties.h"
#include "core/Rebar.h"
#include "core/Section.h"

#include "utils/conc_utils.h"

class SectionTest : public ::testing::Test
{
private:
    float cc_, Ecm_, fcm_, fctm28_, fctm_, fct5_, t_;
    ConcreteProps misc_;

protected:
    const float fc = 30.2;
    const float fcu = 37.0;
    const float Ec = 30000;
    const float cThexp = 0.000011;
    const float v = 0.17;
    const char *concreteName = "fc30";
    const float diameter = 20;
    const float spacing = 100;
    const float b = 1000;
    const float h = 450;

    Concrete fc30;
    Steel fy500;
    Rebar rebar;
    concreteSectionProps props;
    std::map<const char *, Rebar *> rebarMap;

    float Eceff_;

    SectionTest() : fc30(fc, concreteName, Ec, cThexp, v),
                    fy500(500, "fy500", 198000, 0.000012, 0.3),
                    rebar(fy500, diameter, spacing, "bottom")
    {
        rebarMap = {{"bottom", &rebar}};

        misc_ = fc30.misc();

        cc_ = misc_.creepCoefficient;
        t_ = misc_.t0;

        fcm_ = conc_utils::fcyl_to_fcm(fc);
        fctm28_ = conc_utils::fcyl_to_fctm(fc, fcm_);
        fctm_ = conc_utils::fcm_t(fctm28_, t_);
        fct5_ = conc_utils::fctm_to_fct5(fctm_);

        Ecm_ = conc_utils::fcm_to_Ecm(fcm_);
        Eceff_ = conc_utils::ecm_to_eceff(Ecm_, cc_);

        props = {
            .compressionTop = false,
            .Ast = rebar.calcArea(),
            .Asb = rebar.calcArea(),
            .b = b,
            .db = diameter,
            .dt = diameter,
            .Ec = Ecm_,
            .Es = fy500.modulus(),
            .h = h,
            .fctm = fctm_,
            .fct5 = fct5_,
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
    printf("fc: %f\n", fc);
    printf("fctm: %f\n", props.fctm);
    printf("fct5: %f\n", props.fct5);
    printf("Ecm: %f\n", props.Ec);
    printf("Eceff: %f\n", Eceff_);
};