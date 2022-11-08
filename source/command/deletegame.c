#include<stdio.h>
#include<stdlib.h>
#include"deletegame.h"

void deleteGame (ArrayDin* listGame, Queue Q) 
{
    int nomor, i, gameQueue;
    boolean found;

    gameQueue = QNBElmt(Q);
    i = 0;
    found = false;

    ListGame(*listGame);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();

    if (commandWord(currentCommand) == 1) {
        nomor = wordToInt(currentCommand);

        while (i < QNBElmt(Q) && !found) {
            if (isWordEqual(Q.T[i], Get(*listGame, (nomor - 1)))) {
                found = true;
            }
            else {
                i++;
            }
        }
        
        if (found)
        {
            printf("Game gagal dihapus.\n");
        }
        else {
            if (nomor == 1 || nomor == 2 || nomor == 3 || nomor == 4 || nomor == 5)
            {
                printf("Game gagal dihapus.\n");
            }
            else 
            {
                DeleteAt(listGame, (nomor-1));
                printf("Game berhasil dihapus.\n");
            }
        }
    }
    else {
        invalidCommand(&currentCommand);
    }
}