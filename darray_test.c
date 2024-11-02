#include <stdio.h>
#include "darray.h"

int main() {
    darray* array = da_create();

    // Test appending elements
    for (int i = 0; i < 10; ++i) {
        da_append(array, i);
    }

    // Test getting elements
    for (int i = 0; i < da_size(array); ++i) {
        printf("%d ", *da_get(array, i));
    }
    printf("\n");

    // Test deleting the array
    da_delete(array);

    return 0;
}
