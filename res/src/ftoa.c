#include "ud_math.h"

static size_t   ud_math_long_long_len(long long n)
{
    size_t len = 0;
    if (n < 0)
    {
        n *= -1;
        ++len;
    }
    for (; n >= 10; ++len) n /= 10;
    return len + 1;
}

static void ud_math_ftoa_rec(long long n, char *str)
{
	if (n >= 10) ud_math_ftoa_rec(n / 10, str - 1);
    *str = (n % 10) + '0';
}

char    *ud_math_ftoa_prec(double n, size_t prec)
{
    prec = ud_math_min(prec, 37);
    double   round = prec ? 5 / ud_math_pow(10, prec + 1) : 0;
    n += round;

    // extract integer part
    long long integer_part = (long long)n;
    if (integer_part == -9223372036854775807) return ud_str_dup("-9223372036854775807");
    char *res;
    size_t len = ud_math_long_long_len(integer_part);
    ud_ut_prot_malloc(res = ud_ut_malloc((len + prec + 2) * sizeof(char)));
    if (integer_part < 0)
    {
        integer_part *= -1;
        *res = '-';
    }
    char *l_res = &res[len];
    *l_res = '.';
    ud_math_ftoa_rec(integer_part, l_res - 1);

    // extract decimal part
    n -= integer_part;
    char buf[prec + 1];
    buf[prec] = '\0';
    for (ud_ut_count i = 0; i < prec; ++i)
    {
        n *= 10.0f;
        buf[i] = (unsigned int)n + '0';
        n -= (unsigned int)n;
    }
    
    ud_mem_cpy(&res[len + 1], buf, prec + 1);
    return res;
}