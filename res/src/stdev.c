#include "ud_math.h"

float ud_math_stdev(float *arr, size_t len, float mean)
{
    float sum = 0;
    for (ud_ut_count i = 0; i < len; ++i)
        sum += ud_math_pow(*arr++ - mean, 2);
    return ud_math_sqrt(sum / len);
}