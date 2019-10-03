#include <ud_utils.h>
#include <ud_array.h>
#include <ud_string.h>
#include <ud_math.h>
#include <assert.h>

int main(void)
{
    ud_arr  *nb_a = ud_arr_set(float, 10, 1,2,3,4,5,6,7,8,9,10);

    ud_ut_time("%s", "Starting tests...");
    //Basic tests
    assert(ud_math_sqrt(25) == 5);
    assert(ud_math_pow(10, 2) == 100);
    assert(!ud_str_cmp(ud_math_itoa(4354), ud_arr_set(char, 4, '4', '3', '5', '4')));
    assert(ud_math_mean(nb_a) == 5.5);
    assert(ud_math_rand(0, 10) != ud_math_rand(0, 10));
    assert(ud_math_atof("42.101") - 42.101f < 0.01);
    assert(ud_math_atof("-42.101") + 42.101f < 0.01);
    assert(ud_math_atof("0") - 0 < 0.01);
    assert(ud_math_atof("257272.5727425752") - 257272.5727425752f < 0.01);
    ud_ut_time("%s", "All tests passed.");
}