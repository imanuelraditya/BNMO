# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "listdp.h"
# include "../mesinkata/mesinkata.h"

int main() {
    addressldp p, temp;
    int a, b, i, x;
    i, x = 0;
    char* tampung;
    List test;
    CreateEmptylistdp(&test);
    srand(time(NULL));
    a = (rand() % (5)) + 0;
    b = (rand() % (5)) + 0;
    InsVLastlistdp(&test, "H", a, b);
    p = Firstldp(test);

    while (i < 2) {
        if(Posisix(p)-1 >= 0){
            InsVLastlistdp(&test, wordToString(intToWord(x+1)), (Posisix(p)-1) % 5, Posisiy(p));
        } else {
            InsVLastlistdp(&test, wordToString(intToWord(x+1)), (Posisix(p)-1 + 5), Posisiy(p));
        }
        temp = p;
        p = Nextldp(p);
        i++;
        x++;
    }

    int m, n = 0;
    addressldp t;
    for (m=0; m<5; m++) {
        if(m == 0){
            printf("-------------------------------\n");
        }
        for(n = 0; n < 5; n++){
            if(n == 0){
                printf("|");
            }
            if(Searchlistdp(test, n, m) != Nilldp){
                p = Searchlistdp(test, n, m);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
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