#include<stdio.h>
#include<stdlib.h>
#include "save.h"

void save(Word filename, ArrayDin* listGame)
{
    int i;

    FILE * fpointer
    fpointer = fopen(filename, "w+");

    fprintf(fpointer, "%d\n", Length(listGame));
    for (i=0, i<Length(listGame), i++)
    {
        fprintf(fpointer, "%s\n", Get(listGame, i).TabWord);
    }
    fclose(fpointer);

    printf("Save file berhasil disimpan\n");
}