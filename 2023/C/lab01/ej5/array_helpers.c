#ifndef _MYBOOL_H_
#define _MYBOOL_H_

#include <stdio.h>
#include <assert.h>
#include "mybool.h"
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE*archivo;
    archivo = fopen(filepath,"r");

    fscanf(archivo , "%u", &max_size);

    for (unsigned int i = 0u; i < max_size; ++i)
    {
        fscanf(archivo , "%d" , &array[i]);
    }

    fclose(archivo);
    return max_size;
}

void array_dump(int a[], unsigned int length) {


    for (unsigned int i = 0; i < length; ++i)
    {
        printf("% d ",a[i]);
    }
    printf("\n");
}

int array_is_sorted(int array[], unsigned int length) {
    unsigned int i;
    mybool res;
    res = true;
    for (i=0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            res = true;
        }
    }
    

    return res;
}

#endif