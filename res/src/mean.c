#include "ud_math.h"

float ud_math_mean(ud_arr *x)
{
    float sum = 0;
    size_t x_len = x->len;
    float* x_a = (float*)x->val;
    for (size_t i = 0; i < x_len; i++)
        sum += x_a[i];
    return sum / x_len;
}