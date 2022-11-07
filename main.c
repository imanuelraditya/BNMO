#include <stdio.h>
#include <stdlib.h>
#include "source/ADT/array/arraydin.h"
#include "source/ADT/mesinkarakter/mesinkarakter.h"
#include "source/ADT/mesinkata/mesinkata.h"
#include "source/ADT/queue/queue.h"
#include "source/command/command_lain.h"
#include "source/command/createGame.h"
#include "source/command/help.h"
#include "source/command/list_game.h"
#include "source/command/load.h"
#include "source/command/PlayGame.h"
#include "source/command/quit.h"
#include "source/command/rng.h"
#include "source/command/skipGame.h"
#include "source/command/startGame.h"
#include "source/command/welcome.h"

int main() {

    // INISIALISASI ARRAY DAN QUEUE

    ArrayDin array;
    Queue Q;
    boolean esc;

    array = MakeArrayDin();
    QCreateEmpty(&Q, 20);
    esc = false;

    // PROGRAM UTAMA

    welcome();

    printf("\n");

    while (!esc) {
        printf("Masukkan command: ");
        STARTCOMMAND();
        if (isWordEqual(currentCommand, stringToWord("START"))) {
            startGame(&array);
            esc = true;
        } else if (isWordEqual(currentCommand, stringToWord("LOAD"))) {
            ADVCOMMAND();
            load(currentCommand, &array);
            esc = true;
        } else {
            while (!EndWord) {
                ADVCOMMAND();
            }
            printf("Command tidak valid\n");
        }

        printf("\n");
    }

    esc = false;

    help();

    printf("\n");

    while (!esc) {
        printf("Masukkan command: ");
        STARTCOMMAND();

        if (isWordEqual(currentCommand, stringToWord("SAVE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                printf("Game berhasil disimpan\n");
                // save(currentCommand, array);
            }
            else {
                while (!EndWord) {
                    ADVCOMMAND();
                }
                printf("Command tidak valid\n");
            }
        } else if (isWordEqual(currentCommand, stringToWord("CREATE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                CreateGame(&array);
            }
            else {
                while (!EndWord) {
                    ADVCOMMAND();
                }
                printf("Command tidak valid\n");
            }
        } else if (isWordEqual(currentCommand, stringToWord("LIST"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                ListGame(array);
            }
            else {
                while (!EndWord) {
                    ADVCOMMAND();
                }
                printf("Command tidak valid\n");
            }
        } else if (isWordEqual(currentCommand, stringToWord("DELETE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                printf("Game berhasil dihapus\n");
                // deleteGame(currentCommand, &array);
            }
            else {
                while (!EndWord) {
                    ADVCOMMAND();
                }
                printf("Command tidak valid\n");
            }
        } else if (isWordEqual(currentCommand, stringToWord("QUEUE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                printf("Game berhasil dimasukkan ke dalam queue\n");
                // queueGame(currentCommand, &array, &Q);
            }
            else {
                while (!EndWord) {
                    ADVCOMMAND();
                }
                printf("Command tidak valid\n");
            }
        } else if (isWordEqual(currentCommand, stringToWord("PLAY"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                playGame(Q);
            }
            else {
                while (!EndWord) {
                    ADVCOMMAND();
                }
                printf("Command tidak valid\n");
            }
        } else if (isWordEqual(currentCommand, stringToWord("SKIPGAME"))) {
            ADVCOMMAND();
            skipGame(&Q, wordToInt(currentCommand));
        } else if (isWordEqual(currentCommand, stringToWord("QUIT"))) {
            Quit();
            esc = true;
        } else if (isWordEqual(currentCommand, stringToWord("HELP"))) {
            help();
        } else {
            while (!EndWord) {
                ADVCOMMAND();
            }
            printf("Command tidak valid\n");
        }

        printf("\n");
    }
}