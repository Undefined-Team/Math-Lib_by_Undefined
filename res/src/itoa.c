#include "ud_math.h"

static void		ud_math_itoa_rec(long long n, char *str)
{
	if (n >= 10) ud_math_itoa_rec(n / 10, str - 1);
    *str = (n % 10) + '0';
}

char *ud_math_itoa_l(long long n, size_t *len)
{
    char *res;
    size_t n_len = ud_math_int_len(n);
    if (len) *len = n_len;
    if (n == -2147483648) return ud_str_dup("-2147483648");
    UD_UT_PROT_MALLOC(res = ud_ut_malloc(sizeof(char) * (n_len + 1)));
    if (n < 0)
    {
        n *= -1;
        *res = '-';
    }
    char *l_res = &res[n_len];
    *l_res = '\0';
	ud_math_itoa_rec(n, l_res - 1);
    return res;
}