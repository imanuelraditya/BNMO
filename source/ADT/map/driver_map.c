#include <stdio.h>
#include "map.h"
#include "../mesinkata/mesinkata.h"

int main(){
    Map M;
    info I;
    CreateMapEmpty(&M);
    I.Key = stringToWord("Berbagia aku");
    I.Value = 4;

    Insert(&M, I.Key, I.Value);

    if (IsMemberMap(M, I.Key)){
        printf("k merupakan member dari M\n");
    } else {
        printf("k bukan merupakan member dari M\n");
    }
    
    Delete(&M, I.Key);

    if (Value(M, I.Key) == I.Value){
        printf("v merupakan value dari key k dalam M\n");
    } else {
        printf("v bukan merupakan value dari key k dalam M\n");
    }

    return 0;
}

