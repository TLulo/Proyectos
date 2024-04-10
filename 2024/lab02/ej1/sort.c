#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void insert(int a[], unsigned int i)
{
    while (i > 0 && goes_before(a[i],a[i-1]))
    {
        swap(a,i,i-1);
        i--;
    }
}   

void insertion_sort(int a[], unsigned int length)
{
    for (unsigned int i = 1u; i < length; ++i)
    {
        /* needs implementation */
        insert(a, i);
        assert(array_is_sorted(a,i));
    }
}
