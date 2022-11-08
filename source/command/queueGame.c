#include <stdio.h>
#include "queueGame.h"
#include "list_game.h"

void queueGame(ArrayDin listGame, Queue* Q)
{
    int i;
    boolean valid;
    
    ListQueueGame(*Q);
    valid = false;

    printf("\n");

    ListGame(listGame);

    printf("\n");

    while (!valid) {

        printf("Nomor Game yang mau ditambahkan ke antrian: ");
        STARTCOMMAND();

        if (wordToInt(currentCommand) > Length(listGame) || wordToInt(currentCommand) < 1){
            while (!EndWord) {
                ADVCOMMAND();
            }
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n\n");
        }
        else {
            valid = true;

            for (i = 0; i < Length(listGame); i++)
            {
                if (i == wordToInt(currentCommand) - 1)
                {
                    Add(Q, Get(listGame, i));
                }
            }

            printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
        }
    }
}