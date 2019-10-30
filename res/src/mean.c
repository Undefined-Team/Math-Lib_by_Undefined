#include "ud_math.h"

float ud_math_mean(float *x, size_t len)
{
    if (!x || !len) return 0;
    float sum = 0;
    for (size_t i = 0; i < len; i++)
        sum += x[i];
    return sum / len;
}