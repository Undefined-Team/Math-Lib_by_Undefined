
#include <ud_math.h>


int main(void)
{
    // ud_arr  *nb_a = ud_arr_set(float, 10, 1,2,3,4,5,6,7,8,9,10);

    // ud_ut_time("%s", "Starting tests...");
    // //Basic tests
    // assert(ud_math_sqrt(25) == 5);
    // assert(ud_math_pow(10, 2) == 100);
    // assert(!ud_str_cmp(ud_math_itoa(4354), ud_arr_set(char, 4, '4', '3', '5', '4')));
    // assert(ud_math_mean(nb_a) == 5.5);
    // assert(ud_math_rand(0, 10) != ud_math_rand(0, 10));
    // assert(ud_math_atof("42.101") - 42.101f < 0.01);
    // assert(ud_math_atof("-42.101") + 42.101f < 0.01);
    // assert(ud_math_atof("0") - 0 < 0.01);
    // assert(ud_math_atof("257272.5727425752") - 257272.5727425752f < 0.01);
    // ud_ut_time("%s", "All tests passed.");

    // printf("%s\n", ud_math_itoa(56));
    // printf("%s\n", ud_math_itoa(-1));
    // printf("%s\n", ud_math_itoa(0));
    // printf("%s\n", ud_math_itoa(9));
    // printf("%s\n", ud_math_itoa(1));
    // printf("%s\n", ud_math_itoa(2147483647));
    // printf("%s\n", ud_math_itoa(-2147483648));
    
    size_t tata[] = {5, 3, 4, 9, 0, 1};
    ud_math_si_sort(tata, 6);
    for (size_t i = 0; i < 6; ++i)
    {
        printf("%zd\n", tata[i]);
    }
}