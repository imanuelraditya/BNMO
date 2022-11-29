# include <stdio.h>
# include <stdlib.h>
# include "arraymap.h"
#include "../mesinkata/mesinkata.h"

int main() {
    ArrayMap test;
    Map M;
    int Mike;
    CreateMapEmpty(&M);
    Insert(&M, stringToWord("Aku Bahagia"), 1);
    Insert(&M, stringToWord("Aku Sedih"), 2);
    Insert(&M, stringToWord("Aku Senyum"), 3);
    test = MakeArrayMap();
    InsertMapLast(&test, M);
    if (IsArrayMapEmpty(test) == true) {
        Mike = 2;
    }
    else {
        Mike = 1;
    }

    if (Mike = 1) {
        Mike = LengthMap(test);
    }

    if (LengthMap(test) < 5) {
        Mike = GetMapCapacity(test);
    }

    if (Mike >= 0) {
        DeleteMapFirst(&test);
    }

    Mike = LengthMap(test);
    printf("%d", Mike);

    return 0 ;
}