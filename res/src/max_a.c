#include "ud_math.h"

float   ud_math_max_a(float *x, size_t len)
{
    if (!x || !len) return 0;
    float min;
    ud_bool ftime = false;
    for (size_t i = 0; i < len; i++)
    {
        if (!ftime || min < x[i])
        {
            ftime = true;
            min = x[i];
        }
    }
    return ftime ? min : 0;
}