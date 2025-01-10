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

const char *Uncracked::Stype = "Compressive_only";
Uncracked::Uncracked(const concreteSectionProps &propSet, const float M, const float N)
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
};

const char *Cracked::Stype = "Cracked_with_compression";
Cracked::Cracked(const concreteSectionProps &propSet, const float M, const float N, const bool compressionTop)
{
    float Acg2, A2, B2, Y2, y02, yna2, I2, Mcg2, ys2, fna2, fct2, fcb2, fsb2, fst2, est2, esb2, g2, eb2, et2, fsMax2;
    float d = compressionTop ? (propSet.h - propSet.db) : (propSet.h - propSet.dt);

    double nt = 0.0, nb = 0.0; // use for local modular ratio for top and bottom rebar
    // find C2 by binary iteration
    double C2start = propSet.h / 2; // for binary search, take half of search area
    double C2inc = C2start / 2;     // next increment
    double C2 = C2start;

    PureTension *pt = nullptr;
    if (compressionTop)
    {
        // compression in top fibre. C defined from top
        for (int i = 0; i < 21; ++i)
        {
            // modular ratio for transformed area to be adjusted (deduction of concrete area)
            if (C2 < propSet.dt)
            { // check if top rebar is in cracked zone. adjust modular ratio
                nt = propSet.Es / propSet.Ec;
                nb = nt;
            }
            else
            {
                nt = propSet.Es / propSet.Ec - 1; // top rebar in compression zone
                if (C2 < d)
                {
                    nb = propSet.Es / propSet.Ec; // bottom rebar in tension zone
                }
                else
                {
                    nb = propSet.Es / propSet.Ec - 1; // bottom in compression zone
                }
            }

            // much of this calcs can be refactored into helper function
            Acg2 = propSet.b * C2;
            A2 = Acg2 - propSet.Ad + nb * propSet.Asb + nt * propSet.Ast;
            B2 = Acg2 * C2 / 2 - propSet.Ad * propSet.h / 4 + nb * propSet.Asb * d + nt * propSet.Ast * propSet.dt;
            Y2 = B2 / A2;
            y02 = propSet.h / 2 - Y2;
            yna2 = C2 - Y2;
            I2 = propSet.b * pow(Y2, 3) / 3 + propSet.b * pow(yna2, 3) / 3 + nt * propSet.Ast * pow(Y2 - propSet.dt, 2) + nb * propSet.Asb * pow(d - Y2, 2) - propSet.Ad * pow(Y2 - propSet.h / 4, 2);
            Mcg2 = M + N * (y02 / 1000);
            fna2 = (N * 1000) / A2 + (Mcg2 * 1e6) / I2 * yna2;
            if (fna2 > 0)
                C2 = C2 - C2inc;
        }
        {
            C2 = C2 + C2inc;
        }
        C2inc = C2inc / 2;

        fct2 = N * 1000 / A2 - Mcg2 * 1e6 / I2 * Y2; // MPa, concrete stress at top fibre
        fcb2 = 0;                                    // cracked
        ys2 = d - Y2;
        // MPa, stress in bottom rebar
        fsb2 = propSet.ne() * (N * 1000 / A2 + Mcg2 * 1e6 / I2 * ys2);
        // MPa, stress in top rebar (tensile or compressive)
        fst2 = propSet.ne() * (N * 1000 / A2 - Mcg2 * 1e6 / I2 * (Y2 - propSet.dt));
        // strain at top rebar
        est2 = fst2 / (propSet.Es * 1e3);
        // strain at bottom rebar
        esb2 = fsb2 / (propSet.Es * 1e3);
        // slope of strain diagram: delta strain over dist between rebar
        g2 = (esb2 - est2) / (d - propSet.dt);
        eb2 = esb2 + g2 * propSet.db; // apparent surface strain, bottom
        et2 = est2 - g2 * propSet.dt; // apparent surface strain, top
        fsMax2 = fsb2;
        if (abs(fna2) > 0.00001)
        { // check for non-convergence
            PureTension pt(propSet, M, N, compressionTop);
        }
    }
    else
    {
        // compression in bottom fibre, C defined from bottom
        float d_bott = propSet.h - propSet.dt; // bottom up
        for (int i = 0; i < 21; ++i)
        {
            // modular ratio for transformed area to be adjusted (deduction of concrete area)
            if (C2 < propSet.db)
            { // check if bottom rebar is in cracked zone. adjust modular ratio
                nb = propSet.Es / propSet.Ec;
                nt = nt;
            }
            else
            {
                nb = propSet.Es / propSet.Ec - 1; // bottom rebar in compression zone
                if (C2 < d_bott)
                {
                    nt = propSet.Es / propSet.Ec; // top rebar in tension zone
                }
                else
                {
                    nt = propSet.Es / propSet.Ec - 1; // top in compression zone
                }
            }

            Acg2 = propSet.b * C2;
            A2 = Acg2 + nb * propSet.Asb + nt * propSet.Ast;
            B2 = Acg2 * C2 / 2 + nb * propSet.Asb * propSet.db + nt * propSet.Ast * d_bott; // ref bottom
            Y2 = B2 / A2;                                                                   // dist from bottom to CG
            y02 = propSet.h / 2 - Y2;
            yna2 = C2 - Y2;
            I2 = propSet.b * pow(Y2, 3) / 3 + propSet.b * pow(yna2, 3) / 3 + nt * propSet.Ast * pow(d_bott - Y2, 2) + nb * propSet.Asb * pow(Y2 - propSet.db, 2);
            Mcg2 = M - N * (y02 / 1000);
            fna2 = (N * 1000) / A2 + (-Mcg2 * 1e6) / I2 * yna2;

            if (fna2 > 0)
            {
                C2 = C2 - C2inc;
            }
            else
            {
                C2 = C2 + C2inc;
            }
            C2inc = C2inc / 2;
        }

        // MPa, concrete stress at bottom fibre
        fcb2 = N * 1000 / A2 + Mcg2 * 1e6 / I2 * Y2;
        fct2 = 0;
        ys2 = d_bott - Y2;

        // MPa, stress in top rebar (tensile)
        fst2 = propSet.ne() * (N * 1000 / A2 - Mcg2 * 1e6 / I2 * ys2);
        // MPa, stress in bottom rebar (tensile or compressive)
        fsb2 = propSet.ne() * (N * 1000 / A2 + Mcg2 * 1e6 / I2 * (Y2 - propSet.db));
        // strain at top rebar
        est2 = fst2 / (propSet.Es * 1e3);
        // strain at bottom rebar
        esb2 = fsb2 / (propSet.Es * 1e3);
        // slope of strain diagram: delta strain over dist between rebar
        g2 = (esb2 - est2) / (d_bott - propSet.db);
        et2 = est2 - g2 * propSet.dt; // apparent surface strain, top
        eb2 = esb2 + g2 * propSet.db; // apparent surface strain, bottom
        // check for non-convergence
        fsMax2 = fst2;
        if (abs(fna2) > 0.0001)
        {
            PureTension pt(propSet, M, N, compressionTop);
        }
    }

    if (pt)
    {
        this->C = pt->C;
        this->fctop = pt->fctop;
        this->fcbot = pt->fcbot;
        this->fstop = pt->fstop;
        this->fsbot = pt->fsbot;
        this->etop = pt->etop;
        this->ebot = pt->ebot;
        this->g = pt->g;
        this->Stype = PureTension::Stype;
    }
    else
    {
        this->C = C2;
        this->fctop = fct2;
        this->fcbot = fcb2;
        this->fstop = fst2;
        this->fsbot = fsb2;
        this->etop = et2;
        this->ebot = eb2;
        this->g = g2;
        this->Stype = "Cracked";
    }
};

const char *PureTension::Stype = "Tensile_only";
PureTension::PureTension(const concreteSectionProps &propSet, const float M, const float N, const bool compressionTop) {
    // this->run(propSet, M, N, compressionTop);
};