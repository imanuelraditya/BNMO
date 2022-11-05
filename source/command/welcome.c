#include <stdio.h>
#include "welcome.h"

void loading() 
/* loading.. */
{
/* KAMUS LOKAL */
    int i, j, delay;

/* ALGORITMA */
    printf("loading ");

    for(i = 0; i < 10; i++) { // jumlah '>'
        for(j = 0; j < 100000000; j++) { // buat delay prosesnya
            delay = j;
        }
        printf(">");
    }

    printf(" [COMPLETE]\n\n");

    for(j = 0; j < 100099999 ; j++) { //delay lagi
        delay = j;
        }
}

void welcome() // baru bisa di jalanin kalo NMax di mesinkata diganti jadi 100
/* print welcoming page bnmo */
{
/* ALGORITMA */
    loading();
    startWFile("data/bnmo.txt");

    while(!finish) {
        printf("%s\n", currentWord.TabWord);
        advNewlineFile();
    }
}