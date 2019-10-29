#include <stdlib.h>
#include <ud_math.h>

int prec(float val, float example)
{
    printf("%f\n%f\n\n", val, example);
    float   prec = 0.0001;
    float diff = val - example;
    return (diff < prec && diff > -prec);
}

int main(void)
{
    char    *one = "1";
    char    *two = "2";
    char    *dec1 = "0.1";
    char    *dec1000 = "0.0001";
    char    *dec2 = "0.00000000000001";
    char    *dec3 = "0.214";
    char    *dec4 = "0.124129014832948239041241312";
    char    *int_dec = "1.2";
    char    *int_dec2 = "2134123.2351351345431";
    char    *big = "1294302481254901357134905.5314593405134905134513451";
    
    ud_ut_test(prec(ud_math_atof(one), 1));
    ud_ut_test(prec(ud_math_atof(two), 2));
    ud_ut_test(prec(ud_math_atof(dec1), 0.1));
    ud_ut_test(prec(ud_math_atof(dec1000), 0.0001));
    ud_ut_test(prec(ud_math_atof(dec2), 0.00000000000001));
    ud_ut_test(prec(ud_math_atof(dec3), 0.214));
    ud_ut_test(prec(ud_math_atof(dec4), 0.124129014832948239041241312));
    ud_ut_test(prec(ud_math_atof(int_dec), 1.2));
    ud_ut_test(prec(ud_math_atof(int_dec2), 2134123.2351351345431));
    ud_ut_test(prec(ud_math_atof(big), 1294302481254901357134905.5314593405134905134513451));
    ud_ut_test(prec(exp(0), 1));
    ud_ut_test(prec(exp(1), 2.7182));
    ud_ut_test(prec(exp(23.21), 12021950210.2));
}