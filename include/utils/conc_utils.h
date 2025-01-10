#pragma once

namespace conc_utils
{
    const float FCK_CONSTANT = 0.816;
    inline float fctm(const float fc)
    {
        return 0.3;
    }

    inline float fct5(const float fc)
    {
        return 0.3;
    }
}

/*

def fcu_to_fck_cyl(fcu) -> float:
    # convert cube strength to cylinder strength
    return FCK_CONSTANT * fcu


# **************************************************
# These functions are from direct conversion from VB
# **************************************************
def fck_to_fcm(fck) -> float:
    # EC2
    # convert 5th perc characteristic to mean
    return fck + 8


def fcm_to_Ecm(fcm) -> float:
    # EC2
    # get mean modulus of concrete from mean compressive cylinder strength
    return 22 * (fcm / 10) ** 0.3


def fck_to_fctm(fck, fcm) -> float:
    # EC2
    if fck <= 50:
        return 0.3 * fck ** (2 / 3)
    else:
        return 2.12 * math.log(1 + (fcm / 10))


def fctm_t(fctm, t) -> float:
    # returns fct,eff at age t in days.
    # use t = t0 = age at first loading
    bcct = Bcc_t(0.25, t)
    if t < 28:
        a = 1
    else:
        a = 0.66667
    return bcct ** a * fctm


def Bcc_t(s, t) -> float:
    # returns coefficient which depends on age of concrete
    # t=age of concrete in days
    # s=coefficient which depends on type of cement: s=0.25 for normal and rapid hardening
    # ref EC2 3.1.2

    # e ^ x
    # patch: 21 Nov 2024
    t: float = max(t, ZERO)
    return math.exp(s * (1 - (28 / t) ** 0.5))


def fcm_t(fcm, t) -> float:
    # returns mean compressive strength at age t in days
    bcct = Bcc_t(0.25, t)
    return bcct * fcm


def fctm_to_fct5(fctm) -> float:
    # EC2
    # 5th fractile
    return 0.7 * fctm


def Ecm_to_Eceff(Ecm, CC) -> float:
    # EC2
    return Ecm / (1 + CC)


# MISSING FUNCTION FROM VB.NET
def Ecm_t(fcm_3, fcm, Ecm) -> float:
    # returns modulus of elasticity at age t in days
    return Ecm * (fcm_3 / fcm) ** 0.3


def fck_to_fcu(fck) -> float:
    # convert mean strength to cube strength
    return fck / FCK_CONSTANT

*/