#pragma once

namespace conc_utils
{
    const float ZERO = 0.000001;
    const float FCK_CONSTANT = 0.816; // cube to cylinder strength conversion factor

    inline float fcu_to_fcyl(const float fcu)
    {
        return FCK_CONSTANT * fcu;
    }

    inline float fcyl_to_fcm(const float fcyl)
    {
        return fcyl + 8.0;
    }

    inline float fcm_to_Ecm(const float fcm)
    {
        return 22.0 * pow(0.10 * fcm, 0.3);
    }

    inline float fcyl_to_fctm(const float fcyl, const float fcm)
    {
        if (fcyl <= 50)
        {
            const float exp_ = 2.0 / 3.0;
            return 0.30 * pow(fcyl, exp_);
        }
        else
        {
            return 2.12 * log(1 + (0.10 * fcm));
        }
    }

    inline float bcc_t(const float s, const float t)
    {
        // EC2 coefficient which depends on the age of concrete
        const float t_ = t < ZERO ? ZERO : t;
        return exp(s * (1 - pow(28 / t_, 0.5)));
    }

    inline float fcm_t(const float fctm, const float t)
    {
        // mean compressive strength at age t in days
        // s, coefficient which depends on the type of cement: s = 0.25 for normal and rapid hardening
        const float s = 0.25;
        const float bcct = bcc_t(s, t);
        return bcct * fctm;
    }

    inline float const fctm_to_fct5(const float fctm)
    {
        // EC2, 5th fractile
        return 0.7 * fctm;
    }

    inline float const ecm_to_eceff(const float ecm, const float cc)
    {
        // EC2
        // cc, creep coefficient
        return ecm / (1 + cc);
    }

    inline float ecm_t(const float fcm_3, const float fcm, const float Ecm)
    {
        // returns modulus of elasticity at age t in days
        return Ecm * pow(fcm_3 / fcm, 0.3);
    }

    inline float fck_to_fcu(const float fck)
    {
        // convert mean strength to cube strength
        return fck / FCK_CONSTANT;
    }
}