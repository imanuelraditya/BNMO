#include<stdio.h>
#include<stdlib.h>
#include"deletegame.h"

void deleteGame (ArrayDin* listGame, Queue Q) 
{
    int nomor, i, gameQueue;
    gameQueue = QNBElmt(Q);
    ada_di_Queue = false;

    ListGame (listGame);
    printf("Masukkan nomor game yang akan dihapus: ");
    scanf("%d", &nomor);

    for (i=0; i=gameQueue; i++)
    {
        if (Q.T[i].TabWord == Get(listGame, nomor).TabWord)
        {
            printf("Game gagal dihapus\n");
            ada_di_Queue == true;
            break;
        }
    }
    
    if ada_di_Queue == false
    {
        if (nomor == 1 || nomor == 2 || nomor == 3 || nomor == 4 || nomor == 5)
        {
            printf("Game gagal dihapus\n");
        }
        else 
        {
            DeleteAt(listGame, nomor);
            printf("Game berhasil dihapus\n");
        }
    }
}
