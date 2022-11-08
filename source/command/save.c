#include<stdio.h>
#include<stdlib.h>
#include "save.h"

void save(Word filename, ArrayDin* listGame)
{
    FILE *fpointer;
    char* maindir;
    int i;

    maindir = "data/";

    fpointer = fopen(wordToString(concatWord(stringToWord(maindir), filename)), "w");

    if (fpointer == NULL) {
        printf("Tidak ada nama file yang tercantum. Silakan coba lagi.\n");
    }
    else {
        fprintf(fpointer, "%d\n", Length(*listGame));
        for (i = 0; i < Length(*listGame); i++)
        {
            fprintf(fpointer, "%s\n", wordToString(Get(*listGame, i)));
        }
        fclose(fpointer);
    }

    printf("Save file berhasil disimpan\n");
}