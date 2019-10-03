#include "ud_math.h"

float   ud_math_max_a(ud_arr *x)
{
    float min;
    ud_bool ftime = false;

    size_t x_len = x->len;
    float *x_a = (float*)x->val;
    for (size_t i = 0; i < x_len; i++)
    {
        if (!ftime || min < x_a[i])
        {
            ftime = true;
            min = x_a[i];
        }
    }
    return ftime ? min : 0;
}