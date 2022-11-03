# include <stdio.h>
# include "CreateGame.h"
# include "../ADT/array/arraydin.h"

 /* I.S. Game sembarang
    F.S. Game terdefinisi */
void CreateGame (ArrayDin listGame) {
    char* namaGame ;
    printf ("Masukkan nama game yang ingin ditambahkan: ") ;
    scanf("%s", &namaGame) ;
    Word s;
    s = stringToWord (&namaGame);
    InsertLast (&listGame, s) ;
}