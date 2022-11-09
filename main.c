#include <stdio.h>
#include <stdlib.h>
#include "source/ADT/array/arraydin.h"
#include "source/ADT/map/map.h"
#include "source/ADT/mesinkarakter/mesinkarakter.h"
#include "source/ADT/mesinkata/mesinkata.h"
#include "source/ADT/queue/queue.h"
#include "source/ADT/queuedinerdash/queue.h"
#include "source/command/command_lain.h"
#include "source/command/createGame.h"
#include "source/command/deletegame.h"
#include "source/command/dinerdash.h"
#include "source/command/help.h"
#include "source/command/list_game.h"
#include "source/command/load.h"
#include "source/command/PlayGame.h"
#include "source/command/queueGame.h"
#include "source/command/quit.h"
#include "source/command/rng.h"
#include "source/command/save.h"
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
    printf("\n");

    welcome();

    printf("\n");

    while (!esc) {
        printf("Masukkan command: ");
        STARTCOMMAND();

        if (isWordEqual(currentCommand, stringToWord("START"))) {
            if (commandWord(currentCommand) == 1) {
                startGame(&array);
                esc = true;
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("LOAD"))) {
            if (commandWord(currentCommand) == 2) {
                load(currentCommand, &array);
                if (Length(array) == 0) {
                    loadFailed();
                }
                else {
                    esc = true;
                    loadSuceeded();
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else {
            invalidCommand(&currentCommand);
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
            if (commandWord(currentCommand) == 2) {
                save(currentCommand, &array);
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("CREATE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                if (commandWord(currentCommand) == 1) {
                    CreateGame(&array);
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("LIST"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                if (commandWord(currentCommand) == 1) {
                    ListGame(array);
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("DELETE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                if (commandWord(currentCommand) == 1) {
                    deleteGame(&array, Q);
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("QUEUE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                if (commandWord(currentCommand) == 1) {
                    queueGame(array, &Q);
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("PLAY"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                if (commandWord(currentCommand) == 1) {
                    playGame(&Q);
                }
                else {
                    invalidCommand(&currentCommand);
                    printf("%s", wordToString(currentCommand));
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("SKIP"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                ADVCOMMAND();
                if (commandWord(currentCommand) == 1) {
                    skipGame(&Q, wordToInt(currentCommand));
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("QUIT"))) {
            if (commandWord(currentCommand) == 1) {
                printf("Apakah anda ingin melakukan SAVE sebelum keluar dari program? (Y/N): ");
                
                STARTCOMMAND();

                if (isWordEqual(currentCommand, stringToWord("Y"))) {
                    if (commandWord(currentCommand) == 1) {
                        Word namaFile;
                        
                        printf("Masukkan nama file: ");
                        
                        STARTCOMMAND();
                        
                        namaFile = currentCommand;

                        if (commandWord(currentCommand) == 1) {
                            save(namaFile, &array);
                            printf("\n");
                            esc = true;
                            Quit();
                        }
                        else {
                            invalidCommand(&currentCommand);
                        }
                    }
                    else {
                        invalidCommand(&currentCommand);
                    }
                }
                else if (isWordEqual(currentCommand, stringToWord("N"))) {
                    if (commandWord(currentCommand) == 1) {
                        esc = true;
                        Quit();
                    }
                    else {
                        invalidCommand(&currentCommand);
                    }
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("HELP"))) {
            if (commandWord(currentCommand) == 1) {
                help();
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else {
            invalidCommand(&currentCommand);
        }

        printf("\n");
    }
}

// KOMPILASI PROGRAM

/* gcc main.c source/command/command_lain.c source/command/createGame.c source/command/deletegame.c source/command/dinerdash.c 
source/command/help.c source/command/list_game.c source/command/load.c source/command/PlayGame.c source/command/queueGame.c 
source/command/quit.c source/command/rng.c source/command/save.c source/command/skipGame.c source/command/startGame.c 
source/command/welcome.c source/ADT/queue/queue.c source/ADT/queuedinerdash/queue.c source/ADT/map/map.c 
source/ADT/mesinkarakter/mesinkarakter.c source/ADT/mesinkata/mesinkata.c source/ADT/array/arraydin.c -o a */

/* .\a */