#include <stdlib.h>
#include <ud_math.h>
#include <math.h>

int lowerprec(float val, float example)
{
    float   prec = 3;
    float diff = val - example;
    return (diff < prec && diff > -prec);
}

int lowprec(float val, float example)
{
    float   prec = 0.02;
    float diff = val - example;
    return (diff < prec && diff > -prec);
}

int prec(float val, float example)
{
    float   prec = 0.002;
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
    
    ud_ut_test(!ud_str_cmp(ud_math_itoa(1), "1"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(-1), "-1"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(0), "0"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(2), "2"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(10), "10"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(4545), "4545"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(19789), "19789"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(2147483647), "2147483647"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(-2147483648), "-2147483648"));
    ud_ut_test(!ud_str_cmp(ud_math_itoa(-51568), "-51568"));
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
    ud_ut_test(prec(ud_math_exp(0), exp(0)));
    ud_ut_test(prec(ud_math_exp(1), exp(1)));
    ud_ut_test(prec(ud_math_exp(5), exp(5)));
    ud_ut_test(lowerprec(ud_math_exp(10), exp(10)));
    ud_ut_test(lowerprec(ud_math_exp(11), exp(11)));
    ud_ut_test(lowerprec(ud_math_exp(12.32), exp(12.32)));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa(1), "1.00000"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa(2), "2.00000"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa(0.1), "0.10000"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa(0.0001), "0.00010"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa_prec(0.00000000000001, 14), "0.00000000000001"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa_prec(0.214, 3), "0.214"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa(0.124129014832948239041241312), "0.12413"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa_prec(1.2, 1), "1.2"));
    ud_ut_test(!ud_str_cmp(ud_math_ftoa(2134123.2351351345431), "2134123.23514"));
    ud_ut_test(prec(ud_math_ln(0.138), log(0.138)));
    ud_ut_test(prec(ud_math_ln(0.250), log(0.25)));
    ud_ut_test(prec(ud_math_ln(1), log(1)));
    ud_ut_test(prec(ud_math_ln(2), log(2)));
    ud_ut_test(prec(ud_math_ln(3), log(3)));
    ud_ut_test(prec(ud_math_ln(5), log(5)));
    ud_ut_test(prec(ud_math_ln(8), log(8)));
    ud_ut_test(prec(ud_math_ln(10), log(10)));
    ud_ut_test(prec(ud_math_ln(1467), log(1467)));
    ud_ut_test(prec(ud_math_ln(-321), 0));
    ud_ut_test(prec(ud_math_ln(0), 0));
    ud_ut_test(prec(ud_math_log(0.138), log10(0.138)));
    ud_ut_test(prec(ud_math_log(0.250), log10(0.25)));
    ud_ut_test(prec(ud_math_log(1), log10(1)));
    ud_ut_test(prec(ud_math_log(2), log10(2)));
    ud_ut_test(prec(ud_math_log(3), log10(3)));
    ud_ut_test(prec(ud_math_log(5), log10(5)));
    ud_ut_test(prec(ud_math_log(8), log10(8)));
    ud_ut_test(prec(ud_math_log(10), log10(10)));
    ud_ut_test(lowprec(ud_math_log(1467), log10(1467)));
    ud_ut_test(prec(ud_math_log(-321), 0));
    ud_ut_test(prec(ud_math_log(0), 0));
    ud_ut_test(ud_math_rand(0, 10) != ud_math_rand(0, 10));
    ud_ut_test(ud_math_rand(0, 1) != ud_math_rand(0, 1));
    ud_ut_test(ud_math_rand(10, 20) != ud_math_rand(10, 20));
    ud_ut_test(ud_math_rand(100, 1000) != ud_math_rand(100, 1000));
    ud_ut_test(ud_math_rand(1, 1) == ud_math_rand(1, 1));
    ud_ut_test(ud_math_rand(0, 0) == ud_math_rand(0, 0));
    ud_ut_test(ud_math_rand(10, 10) == ud_math_rand(10, 10));
    ud_ut_test(ud_math_rand(1, 1.00005) != ud_math_rand(1, 1.00005));
    ud_ut_test(ud_math_max_a((float[]){1,2,3,4,5}, 5) == 5);
    ud_ut_test(ud_math_max_a((float[]){1,2,5,3,4}, 5) == 5);
    ud_ut_test(ud_math_max_a((float[]){5,1,2,3,4}, 5) == 5);
    ud_ut_test(ud_math_max_a((float[]){4,1,2,3,5}, 4) == 4);
    ud_ut_test(ud_math_max_a((float[]){4,1,2,3,5}, 0) == 0);
    ud_ut_test(ud_math_max_a((float[]){4,1,2,3,5}, 1) == 4);
    ud_ut_test(ud_math_max_a(NULL, 0) == 0);
    ud_ut_test(ud_math_max_a(NULL, 10) == 0);
    ud_ut_test(ud_math_max_a((float[]){0,0,0,0,0}, 5) == 0);
    ud_ut_test(ud_math_min_a((float[]){1,2,3,4,5}, 5) == 1);
    ud_ut_test(ud_math_min_a((float[]){3,2,5,1,4}, 5) == 1);
    ud_ut_test(ud_math_min_a((float[]){5,2,3,4,1}, 5) == 1);
    ud_ut_test(ud_math_min_a((float[]){4,2,3,5,1}, 4) == 2);
    ud_ut_test(ud_math_min_a((float[]){4,1,2,3,5}, 0) == 0);
    ud_ut_test(ud_math_min_a((float[]){4,1,2,3,5}, 1) == 4);
    ud_ut_test(ud_math_min_a(NULL, 0) == 0);
    ud_ut_test(ud_math_min_a(NULL, 10) == 0);
    ud_ut_test(ud_math_min_a((float[]){0,0,0,0,0}, 5) == 0);
    ud_ut_test(ud_math_mean((float[]){0,1,2,3,4,5}, 6) == 2.5);
    ud_ut_test(ud_math_mean((float[]){2,2,2,2,2,2}, 6) == 2);
    ud_ut_test(prec(ud_math_mean((float[]){2,2,2,2,2,2.1}, 6), 2.016667));
    ud_ut_test(ud_math_mean((float[]){2,2,2,2,2,2.1}, 0) == 0);
    ud_ut_test(ud_math_mean(NULL, 0) == 0);
    ud_ut_test(ud_math_mean(NULL, 10) == 0);
    ud_ut_test(prec(ud_math_pow(2, 0), 1));
    ud_ut_test(prec(ud_math_pow(2, 1), 2));
    ud_ut_test(prec(ud_math_pow(2, 2), 4));
    ud_ut_test(prec(ud_math_pow(2, 3), 8));
    ud_ut_test(prec(ud_math_pow(2, 4), 16));
    ud_ut_test(prec(ud_math_pow(10, 2), 100));
    ud_ut_test(prec(ud_math_pow(0, 0), 1));
    ud_ut_test(prec(ud_math_pow(0, 10), 0));
    ud_ut_test(prec(ud_math_pow(1, 10000), 1));
    ud_ut_test(prec(ud_math_pow(1, -10), 1));
    ud_ut_test(prec(ud_math_pow(2, -10), 0.0009765625));
    ud_ut_test(prec(ud_math_pow(2, -15), 0.00003051757));
    ud_ut_test(prec(ud_math_pow(1, 0.15), 1));
    ud_ut_test(prec(ud_math_pow(2, 0.15), 1.10956947207));
    ud_ut_test(prec(ud_math_pow(12, 0.2), 1.64375182952));
    ud_ut_test(prec(ud_math_pow(25, -4), 0.00000256));
    ud_ut_test(prec(sqrt(0), 0));
    ud_ut_test(prec(sqrt(1), 1));
    ud_ut_test(prec(sqrt(25), 5));
    ud_ut_test(prec(sqrt(50), 7.07106781187));
    ud_ut_test(prec(sqrt(1054), 32.4653661615));
    ud_ut_test(prec(sqrt(4885), 69.89277502));
    ud_ut_test(prec(sqrt(3600), 60));
}