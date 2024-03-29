#include "ud_math.h"

static float ud_fln(float x)
{
    union { float f; uint32_t i; } vx = { x };
    union { uint32_t i; float f; } mx = { (vx.i & 0x007FFFFF) | (0x7e << 23) };
    float y = vx.i;
    y *= 1.0 / (1 << 23);
 
    return (y - 124.22544637f - 1.498030302f * mx.f - 1.72587999f / (0.3520887068f + mx.f));
}

float ud_math_ln(float x)
{
    if (x <= 0) return 0;
    return 0.69314718f * ud_fln(x);
}