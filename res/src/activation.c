#include "ud_math.h"

float*   ud_math_softmax(float *x, size_t len)
{
    float sum = 0;
    float *y;

    ud_ut_prot_malloc(y = ud_ut_malloc(sizeof(float) * len));
    for (size_t i = 0; i < len; i++)
    {
        y[i] = ud_math_exp(x[i]);
        sum += y[i];
    }
    for (size_t i = 0; i < len; i++)
        y[i] /= sum;
    return y;
}