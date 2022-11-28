# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "listdp.h"
# include "../mesinkata/mesinkata.h"

int main() {
    address p, temp;
    int a, b, i, x;
    i, x = 0;
    char* tampung;
    List test;
    CreateEmptylistdp(&test);
    srand(time(NULL));
    a = (rand() % (5)) + 0;
    b = (rand() % (5)) + 0;
    InsVLastlistdp(&test, "H", a, b);
    p = First(test);

    while (i < 2) {
        if(Posisix(p)-1 >= 0){
            InsVLastlistdp(&test, wordToString(intToWord(x+1)), (Posisix(p)-1) % 5, Posisiy(p));
        } else {
            InsVLastlistdp(&test, wordToString(intToWord(x+1)), (Posisix(p)-1 + 5), Posisiy(p));
        }
        temp = p;
        p = Next(p);
        i++;
        x++;
    }

    int m, n = 0;
    address t;
    for (m=0; m<5; m++) {
        if(m == 0){
            printf("-------------------------------\n");
        }
        for(n = 0; n < 5; n++){
            if(n == 0){
                printf("|");
            }
            if(Searchlistdp(test, n, m) != Nil){
                p = Searchlistdp(test, n, m);
                if(stringLength(Info(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Info(p));
            }  else {
                printf("     |");
            }
        }
        printf("\n");
        printf("-------------------------------\n");
    }

    printf("\n");
    PrintForwardlistdp(test);
    PrintBackwardlistdp(test);
    return 0;
}