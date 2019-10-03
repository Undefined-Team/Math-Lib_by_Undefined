#include "ud_math.h"

static ud_arr   *ud_get_number(int n, int div, int neg, int size)
{
    ud_arr  *nb;
    int     i;

    i = 0;
    if (neg == -1)
        size++;
    nb = ud_arr_init(sizeof(char), size + 2);
    char *nb_a = (char *)nb->val;
    if (neg == -1)
        nb_a[i++] = '-';
    while (div > 0)
    {
        nb_a[i++] = n / div + '0';
        n %= div;
        div /= 10;
    }
    nb_a[i] = '\0';
    return (nb);
}

static ud_arr   *ud_return_int_min(void)
{
    ud_arr  *int_min = ud_arr_init(sizeof(char), 11);
    ud_arr_val(int_min, sizeof(char), 11, (void *)"-2147483648");
    return (int_min);
}

ud_arr  *ud_math_itoa(int n)
{
    int     neg;
    int     div;
    int     size;

    size = 0;
    div = 1;
    neg = 1;
    if (n == -2147483648)
        return ud_return_int_min();
    if (n < 0)
    {
        neg = -1;
        n *= -1;
    }
    while (n / div > 9)
    {
        size++;
        div *= 10;
    }
    return ud_get_number(n, div, neg, size);
}