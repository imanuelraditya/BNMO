# include <stdio.h>
# include "CreateGame.h"
# include "../ADT/array/arraydin.h"

 /* I.S. Game sembarang
    F.S. Game terdefinisi */
void CreateGame (ArrayDin* listGame) {
    printf("Masukkan nama game yang ingin ditambahkan: ");
    STARTCOMMAND();
    InsertLast(listGame, stringToWord(currentCommand.TabWord));
}