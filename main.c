#include <stdio.h>
#include <stdlib.h>
#include "source/command/console.h"

int main() {

    // INISIALISASI ARRAY DAN QUEUE

    ArrayDin arrayGame, arrayHistory;
    Queue Q;
    Map ScoreRNG, ScoreDinerDash, ScoreTowerOfHanoi, ScoreHangman, ScoreSnakeOnMeteor;
    boolean esc;

    arrayGame = MakeArrayDin();
    arrayHistory = MakeArrayDin();
    QCreateEmpty(&Q, 100);
    CreateMapEmpty(&ScoreRNG);
    CreateMapEmpty(&ScoreDinerDash);
    CreateMapEmpty(&ScoreTowerOfHanoi);
    CreateMapEmpty(&ScoreHangman);
    CreateMapEmpty(&ScoreSnakeOnMeteor);
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
                startGame(&arrayGame);
                esc = true;
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("LOAD"))) {
            if (commandWord(currentCommand) == 2) {
                load(currentCommand, &arrayGame, &arrayHistory, &ScoreRNG, &ScoreDinerDash, &ScoreTowerOfHanoi, &ScoreHangman, &ScoreSnakeOnMeteor, &esc);
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
                save(currentCommand, &arrayGame, &arrayHistory, &ScoreRNG, &ScoreDinerDash, &ScoreTowerOfHanoi, &ScoreHangman, &ScoreSnakeOnMeteor);
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("CREATE"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("GAME"))) {
                if (commandWord(currentCommand) == 1) {
                    CreateGame(&arrayGame);
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
                    ListGame(arrayGame);
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
                    deleteGame(&arrayGame, Q);
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
                    queueGame(arrayGame, &Q);
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
                    playGame(&Q, &arrayHistory, &ScoreRNG, &ScoreDinerDash, &ScoreTowerOfHanoi, &ScoreHangman, &ScoreSnakeOnMeteor);
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
                    skipGame(&Q, &arrayHistory, &ScoreRNG, &ScoreDinerDash, &ScoreTowerOfHanoi, &ScoreHangman, &ScoreSnakeOnMeteor, wordToInt(currentCommand));
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
                        Word namaFile, format;
                        
                        printf("Masukkan nama file: ");
                        
                        do {
                        STARTCOMMAND();
                        
                        namaFile = currentCommand;

                        if (commandWord(currentCommand) == 1) {
                            format.Length = 4;

                            for (int i = 0; i < 4; i++) {
                                format.TabWord[i] = namaFile.TabWord[namaFile.Length - 4 + i];
                            }

                            if (!isWordEqual(format, stringToWord(".txt")) && !isWordEqual(format, stringToWord(".TXT"))) {
                                printf("Format file tidak valid. Silakan coba lagi.\n\n");
                                printf("Masukkan nama file: ");
                            }
                        }
                        else {
                            invalidCommand(&currentCommand);
                            printf("\nMasukkan nama file: ");
                        }
                        } while (!isWordEqual(format, stringToWord(".txt")) && !isWordEqual(format, stringToWord(".TXT")));
                        
                        save(namaFile, &arrayGame, &arrayHistory, &ScoreRNG, &ScoreDinerDash, &ScoreTowerOfHanoi, &ScoreHangman, &ScoreSnakeOnMeteor);
                        esc = true;
                        Quit();
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
        } else if (isWordEqual(currentCommand, stringToWord("HISTORY"))) {
            if (commandWord(currentCommand) == 2) {
                listHistory(arrayHistory, wordToInt(currentCommand));
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("RESET"))) {
            ADVCOMMAND();
            if (isWordEqual(currentCommand, stringToWord("HISTORY"))) {
                if (commandWord(currentCommand) == 1) {
                    printf("Apakah anda yakin ingin menghapus semua history? (Y/N): ");

                    STARTCOMMAND();

                    if (isWordEqual(currentCommand, stringToWord("Y"))) {
                        if (commandWord(currentCommand) == 1) {
                            resetHistory(&arrayHistory);
                        }
                        else {
                            invalidCommand(&currentCommand);
                        }
                    }
                    else if (isWordEqual(currentCommand, stringToWord("N"))) {
                        if (commandWord(currentCommand) == 1) {
                            printf("\nHistory tidak jadi di-reset.\n");
                            listHistory(arrayHistory, Length(arrayHistory));
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
            }
            else if (isWordEqual(currentCommand, stringToWord("SCOREBOARD"))) {
                if (commandWord(currentCommand) == 1) {
                    printf("\nDaftar scoreboard:\n0. ALL\n1. RNG\n2. DINER DASH\n3. TOWER OF HANOI\n4. HANGMAN\n5. SNAKE ON METEOR\n\n");
  
                    printf("\nScoreboard yang ingin dihapus: ");

                    STARTCOMMAND();

                    if (commandWord(currentCommand) == 1) {
                        int num = wordToInt(currentCommand);

                        printf("Apakah anda yakin ingin melakukan reset scoreboard? (Y/N): ");

                        STARTCOMMAND();

                        if (isWordEqual(currentCommand, stringToWord("Y"))) {
                            if (commandWord(currentCommand) == 1) {
                                if (num == 0) {
                                    CreateMapEmpty(&ScoreRNG);
                                    CreateMapEmpty(&ScoreDinerDash);
                                    CreateMapEmpty(&ScoreTowerOfHanoi);
                                    CreateMapEmpty(&ScoreHangman);
                                    CreateMapEmpty(&ScoreSnakeOnMeteor);
                                    printf("\nScoreboard berhasil di-reset.\n");
                                }
                                else if (num == 1) {
                                    CreateMapEmpty(&ScoreRNG);
                                    printf("\nScoreboard berhasil di-reset.\n");
                                }
                                else if (num == 2) {
                                    CreateMapEmpty(&ScoreDinerDash);
                                    printf("\nScoreboard berhasil di-reset.\n");
                                }
                                else if (num == 3) {
                                    CreateMapEmpty(&ScoreTowerOfHanoi);
                                    printf("\nScoreboard berhasil di-reset.\n");
                                }
                                else if (num == 4) {
                                    CreateMapEmpty(&ScoreHangman);
                                    printf("\nScoreboard berhasil di-reset.\n");
                                }
                                else if (num == 5) {
                                    CreateMapEmpty(&ScoreSnakeOnMeteor);
                                    printf("\nScoreboard berhasil di-reset.\n");
                                }
                                else {
                                    printf("\nInput tidak valid.\n");
                                }
                            }
                            else {
                                invalidCommand(&currentCommand);
                            }
                        }
                        else if (isWordEqual(currentCommand, stringToWord("N"))) {
                            if (commandWord(currentCommand) == 1) {
                                printf("\nScoreboard tidak jadi di-reset.\n");
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
                } else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        } else if (isWordEqual(currentCommand, stringToWord("SCOREBOARD"))) {
            if (commandWord(currentCommand) == 1) {
                printf("**** SCOREBOARD GAME RNG ****\n");
                displayScoreboard(ScoreRNG);
                printf("\n**** SCOREBOARD GAME DINER DASH ****\n");
                displayScoreboard(ScoreDinerDash);
                printf("\n**** SCOREBOARD GAME TOWER OF HANOI ****\n");
                displayScoreboard(ScoreTowerOfHanoi);
                printf("\n**** SCOREBOARD GAME HANGMAN ****\n");
                displayScoreboard(ScoreHangman);
                printf("\n**** SCOREBOARD GAME SNAKE ON METEOR ****\n");
                displayScoreboard(ScoreSnakeOnMeteor);
                printf("\n");
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