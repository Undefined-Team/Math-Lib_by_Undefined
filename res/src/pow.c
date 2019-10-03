#include "ud_math.h"

float ud_math_pow(float x, float e)
{
    float result = 1;

    if (e < 0 || e < 1 || e - (unsigned long)e != 0)
        return (ud_math_exp(e * ud_math_log(x)));
    unsigned long exp = e;
    while (1)
    {
        if (exp & 1)
            result *= x;
        exp >>= 1;
        if (!exp)
            break;
        x *= x;
    }
    return (result);
}