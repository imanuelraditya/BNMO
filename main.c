#include <stdio.h>
#include <stdlib.h>
#include "source/command/console.h"

int main() {

    // INISIALISASI ARRAY DAN QUEUE

    ArrayDin array;
    Queue Q;
    boolean esc;

    array = MakeArrayDin();
    QCreateEmpty(&Q, 100);
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

    return 0;
}

// KOMPILASI PROGRAM

/* gcc main.c source/command/console.c source/ADT/queue/queue.c source/ADT/queuedinerdash/queue.c source/ADT/stack/stack.c source/ADT/map/map.c source/ADT/mesinkarakter/mesinkarakter.c source/ADT/mesinkata/mesinkata.c source/ADT/array/arraydin.c -o a */

/* .\a */