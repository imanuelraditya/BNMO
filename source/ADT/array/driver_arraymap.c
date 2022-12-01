# include <stdio.h>
# include <stdlib.h>
# include "arraymap.h"
#include "../mesinkata/mesinkata.h"

int main() {
    ArrayMap test1, test2;
    Map M1, M2;
    int Mike;
    CreateMapEmpty(&M1);
    CreateMapEmpty(&M2);
    Insert(&M1, stringToWord("Aku Bahagia"), 1);
    Insert(&M1, stringToWord("Aku Sedih"), 2);
    Insert(&M1, stringToWord("Aku Senyum"), 3);

    Insert(&M2, stringToWord("Aku Tidak Tahu"), 1);
    Insert(&M2, stringToWord("Aku dan Kamu"), 2);
    Insert(&M2, stringToWord("Aku Bingung"), 3);

    test1 = MakeArrayMap();
    test2 = MakeArrayMap();

    InsertMapLast(&test1, M1);
    InsertMapFirst(&test2, M2);

    if (IsArrayMapEmpty(test1) == true) {
        Mike = 2;
    }
    else {
        Mike = 1;
    }

    if (Mike = 1) {
        Mike = LengthMap(test1);
    }

    if (LengthMap(test1) < 5) {
        Mike = GetMapCapacity(test1);
    }

    if (Mike >= 0) {
        DeleteMapFirst(&test1);
    }

    Mike = LengthMap(test1);
    printf("%d", Mike);

    return 0 ;
}