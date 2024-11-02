#include "darray.h"

struct darray {
    int* data;
    size_t capacity;
    size_t size;
};

darray* da_create() {
    darray* array = malloc(sizeof(darray));
    if (array == NULL) {
        return NULL;
    }

    array->data = NULL;
    array->capacity = 0;
    array->size = 0;

    return array;
}

int* da_get(darray* array, size_t idx) {
    if (array == NULL || idx >= array->size) {
        return NULL;
    }

    return &(array->data[idx]);
}

int da_append(darray* array, int value) {
    if (array == NULL) {
        return 0;
    }

    if (array->size == array->capacity) {
        size_t new_capacity = array->capacity == 0 ? 1 : array->capacity * 2;
        int* new_data = realloc(array->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            return 0;
        }

        array->data = new_data;
        array->capacity = new_capacity;
    }

    array->data[array->size] = value;
    array->size++;

    return 1;
}

size_t da_size(darray* array) {
    if (array == NULL) {
        return 0;
    }

    return array->size;
}

void da_delete(darray* array) {
    if (array == NULL) {
        return;
    }

    free(array->data);
    free(array);
}
