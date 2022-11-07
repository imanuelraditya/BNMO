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

    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}