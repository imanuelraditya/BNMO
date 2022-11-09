#include <stdio.h>
#include "load.h"


void load(Word filename, ArrayDin *array) {
    /* LOAD merupakan salah satu command yang dimasukkan pertama kali oleh pemain ke BNMO. 
    Memiliki satu argumen yaitu filename yang merepresentasikan suatu save file yang ingin dibuka. 
    Setelah menekan Enter, akan dibaca save file <filename> yang berisi list game yang dapat dimainkan */

    char* maindir;
    int count, i;

    maindir = "data/";
    i = 0;

    startWFile(wordToString(concatWord(stringToWord(maindir), filename)));

    count = wordToInt(currentWord);

    for (i = 0; i < count; i++) {
        advNewlineFile();
        InsertLast(array, currentWord);
    }
}

void loadSuceeded() {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan pesan loading berhasil */
    /* Proses: Menampilkan pesan loading berhasil */
    
    /* loading.. */

    /* KAMUS LOKAL */
        int i, j, delay;

    /* ALGORITMA */
        printf("LOADNG FILE");

        for(i = 0; i < 10; i++) { // jumlah '>'
            for(j = 0; j < 100000000; j++) { // buat delay prosesnya
                delay = j;
            }
            printf(" .");
        }

        printf(" [SUCCEEDED //]\n\n");

        for(j = 0; j < 100099999 ; j++) { //delay lagi
            delay = j;
            }
        
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void loadFailed() {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan pesan loading gagal */
    /* Proses: Menampilkan pesan loading gagal */
    
    /* loading.. */

    /* KAMUS LOKAL */
        int i, j, delay;

    /* ALGORITMA */
        printf("LOADNG FILE");

        for(i = 0; i < 10; i++) { // jumlah '>'
            for(j = 0; j < 100000000; j++) { // buat delay prosesnya
                delay = j;
            }
            printf(" .");
        }

        printf(" [FAILED XX]\n\n");

        for(j = 0; j < 100099999 ; j++) { //delay lagi
            delay = j;
            }
        
        printf("Load file gagal. File tidak ditemukan.\n");
}