#include "ud_math.h"

static void ud_math_merge(size_t *arr, size_t l, size_t m, size_t r) 
{ 
    size_t i, j, k; 
    size_t n1 = m - l + 1; 
    size_t n2 =  r - m; 
    size_t L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
            arr[k] = L[i++]; 
        else
            arr[k] = R[j++]; 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i++]; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j++]; 
        k++; 
    } 
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