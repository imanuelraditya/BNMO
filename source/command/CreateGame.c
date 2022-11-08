# include <stdio.h>
# include "CreateGame.h"
# include "../ADT/array/arraydin.h"

 /* I.S. Game sembarang
    F.S. Game terdefinisi */
void CreateGame (ArrayDin* listGame) {
    boolean found;
    int i;

    found = false;
    i = 0;

    printf("Masukkan nama game yang ingin ditambahkan: ");
    STARTGAMENAME();

    while (i < Length(*listGame) && !found) {
        if (isWordEqual(currentCommand, (*listGame).A[i])) {
            found = true;
        }
        else {
            i++;
        }
    }

    if (found) {
        printf("Game sudah ada di dalam list.\n");
    } else {
        InsertLast(listGame, currentCommand);
        printf("Game berhasil ditambahkan.\n");
    }
}