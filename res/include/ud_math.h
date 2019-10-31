#ifndef UD_MATH_H
# define UD_MATH_H

// Lib
#include <stdint.h>
#include <ud_utils.h>
#include <ud_string.h>

// Macro
# define    ud_math_max(_x, _y)             ({ __auto_type _xt = _x; __auto_type _yt = _y; (_xt > (typeof(_xt))_yt ? _xt : (typeof(_xt))_yt); })
# define    ud_math_min(_x, _y)             ({ __auto_type _xt = _x; __auto_type _yt = _y; (_xt < (typeof(_xt))_yt ? _xt : (typeof(_xt))_yt); })
# define    ud_math_is_digit(_c)            ({ __auto_type _ct = _c; ((_ct) >= '0' && (_ct) <= '9'); })
# define    ud_math_is_white_space(_c)      ({ __auto_type _ct = _c; ((_ct) == ' ' || (_ct) == '\t'); })

# define    ud_math_sigmoid(_x)             (1 / (1 + ud_math_exp(-_x)))
# define    ud_math_relu(_x)                ud_math_max(0, _x)
# define    ud_math_lrelu(_x)               ({ __auto_type _xt = _x; ud_math_max(0.1 * _xt, _xt); })
# define    ud_math_tanh(_x)                (1 - (2 / (ud_math_exp(2 * _x) + 1)))

# define    ud_math_si_sort(_arr, _len)     ud_math_merge_sort((size_t*)_arr, 0, _len - 1)
# define    ud_math_itoa(_x)                ud_math_itoa_l(_x, NULL)

# define    ud_math_ftoa(_n)                ud_math_ftoa_prec(_n, 5)

// Structures

// Prototypes
float*                                      ud_math_softmax(float* x, size_t len);
float                                       ud_math_atof(const char *p);
char                                        *ud_math_ftoa_prec(double n, size_t prec);
float                                       ud_math_exp(float x);
char                                        *ud_math_itoa_l(long long n, size_t *len);
float                                       ud_math_log(float x);
float                                       ud_math_ln(float x);
float                                       ud_math_mean(float *x, size_t len);
float                                       ud_math_pow(float x, float e);
float                                       ud_math_rand(float bound_a, float bound_b);
float                                       ud_math_sqrt(const float x);
float                                       ud_math_min_a(float *x, size_t len);
float                                       ud_math_max_a(float *x, size_t len);
void                                        ud_math_merge_sort(size_t *arr, size_t l, size_t r);
size_t		                                ud_math_int_len(int n);

#endif