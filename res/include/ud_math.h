#ifndef UD_MATH_H
# define UD_MATH_H

// Lib
#include <stdint.h>
#include <ud_utils.h>
#include <ud_string.h>

// Macro
# define    ud_math_max(x, y)               (x > y ? x : y)
# define    ud_math_min(x, y)               (x < y ? x : y)
# define    ud_math_is_digit(c)             ((c) >= '0' && (c) <= '9')
# define    ud_math_is_white_space(c)       ((c) == ' ' || (c) == '\t')

# define    ud_math_sigmoid(x)              (1 / (1 + ud_math_exp(-x)))
# define    ud_math_relu(x)                 ud_math_max(0, x)
# define    ud_math_lrelu(x)                ud_math_max(0.1 * x, x)
# define    ud_math_tanh(x)                 (1 - (2 / (ud_math_exp(2 * x) + 1)))

# define    ud_math_si_sort(arr, len)       ud_math_merge_sort((size_t*)arr, 0, len - 1)
# define    ud_math_itoa(x)                 ud_math_itoa_l(x, NULL);
// Structures

// Prototypes
float*                                      ud_math_softmax(float* x, size_t len);
float                                       ud_math_atof(const char *p);
float                                       ud_math_exp(float x);
char                                        *ud_math_itoa_l(long long n, size_t *len);
float                                       ud_math_log(float x);
float                                       ud_math_mean(float *x, size_t len);
float                                       ud_math_pow(float x, float e);
float                                       ud_math_rand(float bound_a, float bound_b);
float                                       ud_math_sqrt(const float x);
float                                       ud_math_min_a(float *x, size_t len);
float                                       ud_math_max_a(float *x, size_t len);
void                                        ud_math_merge_sort(size_t *arr, size_t l, size_t r);
size_t		                                ud_math_int_len(int n);

#endif