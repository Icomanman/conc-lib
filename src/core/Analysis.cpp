#include <iostream>
#include <cmath>
#include "core/Analysis.h"
#include "core/Properties.h"

Analysis::Analysis() {
};

bool Analysis::isCompressionTop()
{
    return compressionTop_;
};

void Analysis::updateCompressionTop(bool compressionTop)
{
    compressionTop_ = compressionTop;
};

Uncracked::Uncracked() {
};

Uncracked &Uncracked::run(const props &propSet, float M, float N)
{
    bool fgExtremeCompTop;
    float Acg, A1, B1, Y1, y01, yb1, I1, Mcg1, ys1, fcb1, fct1, fsb1, fst1, et1, eb1, g1, C1;
    float d = propSet.h - propSet.db; // mm, dist from top to rebar

    Acg = propSet.b * propSet.h; // mm2, gross area
    // mm2, transformed area
    A1 = Acg - propSet.Ad + propSet.n1() * (propSet.Ast + propSet.Asb);
    // mm3, transformed 1st moment of area, ref top
    B1 = Acg * propSet.h / 2 - propSet.Ad * propSet.h / 4 + propSet.n1() * propSet.Asb * d +
         propSet.n1() * propSet.Ast * propSet.dt;
    Y1 = B1 / A1;               // mm, dist from top to CG
    y01 = (propSet.h / 2) - Y1; // mm, dist from CL to CG
    yb1 = propSet.h - Y1;       // mm, dist from CG to extreme bottom fibre
    I1 = (propSet.b * pow(Y1, 3) / 3 + propSet.b * pow(yb1, 3) / 3 + propSet.n1() * propSet.Ast * pow(Y1 - propSet.dt, 2) +
          propSet.n1() * propSet.Asb * pow(d - Y1, 2) - propSet.Ad * pow(Y1 - propSet.h / 4, 2)); // transformed 2nd moment of area, ref CG
    // kNm, adjusted, effective moment, ref N at CG
    Mcg1 = M + N * (y01 / 1000);
    ys1 = d - Y1;
    // MPa, stress at bottom fibre
    fcb1 = N * 1000 / A1 + Mcg1 * 1e6 / I1 * yb1;
    // MPa, stress at top fibre
    fct1 = N * 1000 / A1 - Mcg1 * 1e6 / I1 * Y1;
    // MPa, stress in bottom rebar
    fsb1 = propSet.ne() * (N * 1000 / A1 + Mcg1 * 1e6 / I1 * ys1);
    // MPa, stress in top rebar (tensile or compressive)
    fst1 = propSet.ne() * (N * 1000 / A1 - Mcg1 * 1e6 / I1 * (Y1 - propSet.dt));
    et1 = fct1 / (propSet.Ec * 1e3); // strain at top fibre
    eb1 = fcb1 / (propSet.Ec * 1e3); // strain at bottom fibre
    // slope of strain diagram: delta strain over h
    g1 = (fcb1 - fct1) / (propSet.Ec * 1e3) / propSet.h;

    if (g1 == 0)
    {
        g1 = 0.0000001; // avoid division by zero
    }

    // redefine dist to NA from extreme compressive face:
    if (g1 > 0)
    {                            // test slope of strain
        fgExtremeCompTop = true; // set flag
        C1 = -et1 / g1;          // depth to NA from top face
    }
    else
    {
        fgExtremeCompTop = false;
        C1 = -eb1 / -g1; // depth to NA from bottom face
    }

    this->C = C1;
    this->fctop = fct1;
    this->fcbot = fcb1;
    this->fstop = fst1;
    this->fsbot = fsb1;
    this->etop = et1;
    this->ebot = eb1;
    this->g = g1;
    this->Stype = "Compressive_only";

    // update state
    (*this).updateCompressionTop(fgExtremeCompTop);
    return *this;
};

Cracked::Cracked() {
};

Cracked &Cracked::run(const props &propSet, float M, float N)
{
    return *this;
};