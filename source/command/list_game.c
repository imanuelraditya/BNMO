#include <stdio.h>
#include <stdlib.h>
#include "list_game.h"

void ListGame (ArrayDin array) {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan list game yang tersedia */
    /* Proses: Menampilkan list game yang tersedia */
    
    int i;

    printf("Berikut adalah daftar game yang tersedia\n");
    if (IsEmpty(array)) {
        printf("Tidak ada game yang tersedia.\n");
    } else {
        for (i = 0; i < Length(array); i++) {
            printf("%d. %s\n", i+1, Get(array, i).TabWord);
        }
    }
}

// int main() {
//     ArrayDin array = MakeArrayDin();
//     InsertFirst(&array, stringToWord("Diner Dash"));
//     InsertFirst(&array, stringToWord("Fishing Frenzy"));
//     InsertFirst(&array, stringToWord("Farm Frenzy"));
//     InsertFirst(&array, stringToWord("Farm Frenzy 2"));
//     InsertFirst(&array, stringToWord("Insaniquarium"));

//     ListGame(array);

//     return 0;
// }