#ifndef UD_MATH_H
# define UD_MATH_H

// Lib
#include <stdint.h>
#include <ud_utils.h>
#include <ud_array.h>
#include <ud_string.h>

// Macro
# define    ud_math_max(x, y)   (x > y ? x : y)
# define    ud_math_min(x, y)   (x < y ? x : y)
# define    ud_is_digit(c)      ((c) >= '0' && (c) <= '9')
# define    ud_white_space(c)   ((c) == ' ' || (c) == '\t')

// Structures

// Prototypes
float       ud_math_sigmoid(float x);
float       ud_math_relu(float x);
float       ud_math_lrelu(float x);
float       ud_math_tanh(float x);
ud_arr*     ud_math_softmax(ud_arr* x);
float       ud_math_atof(const char *p);
float       ud_math_exp(float x);
ud_arr      *ud_math_itoa(int n);
float       ud_math_log(float x);
float       ud_math_mean(ud_arr *x);
float       ud_math_pow(float x, float e);
float       ud_math_rand(float bound_a, float bound_b);
void        ud_math_si_sort(ud_arr *arr);
float       ud_math_sqrt(const float x);
float       ud_math_min_a(ud_arr *x);
float       ud_math_max_a(ud_arr *x);

#endif