# include <stdio.h>
# include "CreateGame.h"
# include "../ADT/array/arraydin.h"

 /* I.S. Game sembarang
    F.S. Game terdefinisi */
void CreateGame (ArrayDin* listGame) {
    printf("Masukkan nama game yang ingin ditambahkan: ");
    STARTGAMENAME();
    InsertLast(listGame, stringToWord(currentCommand.TabWord));

    printf("Game berhasil ditambahkan!\n");
}