# include <stdio.h>
# include "CreateGame.h"

 /* I.S. Game sembarang
    F.S. Game terdefinisi */
void CreateGame (char namaGame[]);
    char namaGame[] ;
    printf ("Masukkan nama game yang ingin ditambahkan: ") ;
    scanf("%d", namaGame[]) ;
    String s;
    make_string (&s);
    s = stringToWord (namaGame);

    insertLast(&T, s) ;