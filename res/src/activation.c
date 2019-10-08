#include "ud_math.h"

float   ud_math_sigmoid(float x)
{
    return 1 / (1 + ud_math_exp(-x));
}

float   ud_math_relu(float x)
{
    return ud_math_max(0, x);
}

float   ud_math_lrelu(float x)
{
    return ud_math_max(0.1 * x, x);
}

float   ud_math_tanh(float x)
{
    return 1 - (2 / (ud_math_exp(2 * x) + 1));
}

ud_arr*   ud_math_softmax(ud_arr* x)
{
    float sum = 0;
    ud_arr* y;

    y = ud_arr_init(sizeof(float), x->len);
    size_t y_len = y->len;
    float *y_a = (float*)y->val;
    float *x_a = (float*)x->val;
    for (size_t i = 0; i < y_len; i++)
    {
        y_a[i] = ud_math_exp(x_a[i]);
        sum += y_a[i];
    }
    for (size_t i = 0; i < y_len; i++)
        y_a[i] /= sum;
    return y;
}