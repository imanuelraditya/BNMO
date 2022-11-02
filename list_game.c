#include <stdio.h>
#include <stdlib.h>
#include "source/ADT/array/arraydin.h"

void ListGame (ArrayDin array) {
    int i;

    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 0; i < Length(array); i++) {
        printf("%d. %s\n", i+1, Get(array, i));
    }
}