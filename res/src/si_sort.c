#include "ud_math.h"

static void ud_math_merge(size_t *arr, size_t l, size_t m, size_t r) 
{ 
    size_t i, j;
    size_t n1 = m - l + 1; 
    size_t n2 =  r - m; 
    size_t L[n1], R[n2]; 
  
    size_t *L_tmp = L;
    size_t *R_tmp = R;
    size_t *arr_tmp = &arr[l];
    for (i = 0; i < n1; i++) *L_tmp++ = *arr_tmp++; 
    arr_tmp = &arr[m + 1];
    for (j = 0; j < n2; j++) *R_tmp++ = *arr_tmp++; 
    i = 0;
    j = 0;
    L_tmp = L;
    R_tmp = R;
    arr_tmp = &arr[1];
    while (i < n1 && j < n2) 
    { 
        if (*L_tmp <= *R_tmp) 
        {
            *arr_tmp++ = *L_tmp++; 
    	    ++i;
        }
        else
        {
            *arr_tmp++ = *R_tmp++; 
            ++j;
        }
    }
    for (; i < n1; ++i) *arr_tmp++ = *L_tmp++;
    for (; j < n2; ++j) *arr_tmp++ = *R_tmp++;
} 

void ud_math_merge_sort(size_t *arr, size_t l, size_t r) 
{ 
    if (l < r) 
    {
        size_t m = l+(r-l)/2; 
        ud_math_merge_sort(arr, l, m); 
        ud_math_merge_sort(arr, m+1, r); 
        ud_math_merge(arr, l, m, r); 
    } 
} 