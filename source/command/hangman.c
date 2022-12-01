#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

void wordList(ArrayDin* listOfWord) {
    int jumlah, i;

    startWFile("data/DaftarKataHangman.txt");

    jumlah = wordToInt(currentWord);

    for (i = 0 ; i < jumlah ; i++) {
         advNewlineFile();
         InsertLast(listOfWord, currentWord);
     }
}

Word chooseWord(ArrayDin listOfWord) {
    int i, random;

    random = rand() % listOfWord.Neff;

    return Get(listOfWord, random);
}

boolean isAlreadyGuessed(ArrayDin listOfGuess, Word guess) {
    int i;

    for (i = 0 ; i < listOfGuess.Neff ; i++) {
        if (isWordEqual(lowerWord(Get(listOfGuess, i)), lowerWord(guess))) {
            return true;
        }
    }

    return false;
}

void printGuess(ArrayDin listOfGuess) {
    int i;

    for (i = 0 ; i < listOfGuess.Neff ; i++) {
        printf("%c", Get(listOfGuess, i).TabWord[0]);
    }
}

boolean win(Word word, ArrayDin listOfGuess) {
    int i, j, count = 0;

    for (i = 0 ; i < word.Length ; i++) {
        for (j = 0 ; j < listOfGuess.Neff ; j++) {
            if (isWordEqual(upperWord(charToWord(word.TabWord[i])), upperWord(charToWord(Get(listOfGuess, j).TabWord[0])))) {
                count++;
            }
        }
    }

    if (count == word.Length) {
        return true;
    } else {
        return false;
    }
}

void addDictionary(ArrayDin* listOfWord) {
    FILE *file;
    boolean found = false;
    int i = 0;

    printf("\nMasukkan kata baru yang ingin ditambahkan: ");
    STARTGAMENAME();

    while (i < Length(*listOfWord) && !found) {
        if (isWordEqual(lowerWord(currentCommand), lowerWord(Get(*listOfWord, i)))) {
            found = true;
        }
        else {
            i++;
        }
    }

    if (found) {
        printf("Kata sudah ada di dalam daftar kata.\n");
    }
    else {
        InsertLast(listOfWord, upperWord(currentCommand));
        
        file = fopen("data/DaftarKataHangman.txt", "a");
        fprintf(file, "%d\n", Length(*listOfWord));
        for (i = 0 ; i < Length(*listOfWord) ; i++) {
            fprintf(file, "%s\n", wordToString(Get(*listOfWord, i)));
        }
        fclose(file);
        printf("Kata berhasil ditambahkan.\n");
    }
}

void hangman(int* totalscore) {
    ArrayDin listOfWord, listOfGuess;
    Word wordToGuess, guess;
    int i, j, chance, score, lengthGuess, lengthWord;
    boolean found, valid, flag;

    flag = false;

    listOfWord = MakeArrayDin();
    wordList(&listOfWord);

    printf("Selamat datang di game Hangman!\n");

    while (!flag) {
        printf("\nSilakan pilih mode berikut:\n1. Menambah dictionary\n2. Bermain\n");
        printf("\nMasukkan pilihan: ");
        STARTCOMMAND();

        if (commandWord(currentCommand) == 1) {
            if (isWordEqual(lowerWord(currentCommand), lowerWord(charToWord('1')))) {
                addDictionary(&listOfWord);
            }
            else if (isWordEqual(lowerWord(currentCommand), lowerWord(charToWord('2')))) {
                flag = true;
                chance = 10;
                score = 0;
                (*totalscore) = 0;

                listOfWord = MakeArrayDin();
                listOfGuess = MakeArrayDin();

                wordList(&listOfWord);

                wordToGuess = chooseWord(listOfWord);
                lengthWord = wordToGuess.Length;
                lengthGuess = 0;

                do {
                    printf("\nTebakan sebelumnya : -\n");
                    printf("Kata:");
                    for (i = 0 ; i < wordToGuess.Length ; i++) {
                        printf(" _");
                    }
                    printf("\n");
                    printf("Kesempatan: %d", chance);
                    printf("\nMasukkan tebakan: ");
                    STARTCOMMAND();

                    if (commandWord(currentCommand) == 1 && currentCommand.Length == 1 && 'a' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'z' || 'A' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'Z') {
                        guess = charToWord(currentCommand.TabWord[0]);

                        while (!win(wordToGuess, listOfGuess) && chance > 0) {
                            
                                if (isAlreadyGuessed(listOfGuess, guess)) {
                                    printf("Tebakan sudah pernah dilakukan!\n");
                                } else {
                                    InsertLast(&listOfGuess, guess);
                                    
                                    found = false;

                                    for (i = 0 ; i < wordToGuess.Length ; i++) {
                                        if (isWordEqual(upperWord(charToWord(wordToGuess.TabWord[i])), upperWord(charToWord(guess.TabWord[0])))) {
                                            found = true;
                                        }
                                    }

                                    if(!found) {
                                        chance--;
                                    }
                                }

                            valid = false;

                            while (!valid && !win(wordToGuess, listOfGuess) && chance > 0) {
                                printf("\nTebakan sebelumnya : ");
                                printGuess(listOfGuess);
                                printf("\n");
                                printf("Kata:");
                                for (i = 0 ; i < wordToGuess.Length ; i++) {
                                    found = false;
                                    for (j = 0 ; j < listOfGuess.Neff ; j++) {
                                        if (isWordEqual(upperWord(charToWord(wordToGuess.TabWord[i])), upperWord(charToWord(Get(listOfGuess, j).TabWord[0])))) {
                                            found = true;
                                        }
                                    }

                                    if (found) {
                                        printf(" %c", wordToGuess.TabWord[i]);
                                    } else {
                                        printf(" _");
                                    }
                                }
                                printf("\n");
                                printf("Kesempatan: %d\n", chance);
                                printf("Masukkan tebakan: ");

                                STARTCOMMAND();

                                if (commandWord(currentCommand) == 1 && currentCommand.Length == 1 && 'a' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'z' || 'A' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'Z') {
                                    guess = charToWord(currentCommand.TabWord[0]);
                                    valid = true;
                                } else {
                                    printf("Masukkan salah!\n");
                                    printf("\nMasukkan tebakan: ");
                                }
                            }
                        }

                        if (win(wordToGuess, listOfGuess)) {
                            score = lengthWord;
                            (*totalscore) += score;
                            printf("\nBerhasil menebak kata %s! Kamu mendapatkan %d poin!\n", wordToString(wordToGuess), score);
                        } else {
                            printf("\nKamu gagal menebak kata %s!\n", wordToString(wordToGuess));
                        }
                    } else {
                        printf("Masukkan salah!\n");
                    }

                    while (win(wordToGuess, listOfGuess) && chance > 0) {
                            listOfWord = MakeArrayDin();
                            listOfGuess = MakeArrayDin();

                            wordList(&listOfWord);

                            wordToGuess = chooseWord(listOfWord);
                            lengthWord = wordToGuess.Length;
                            lengthGuess = 0;
                    }
                } while (chance > 0);
            }
            else {
                printf("Pilihan tidak valid.\n");
            }
        }
        else {
            printf("Masukkan salah. Silakan masukkan kembali.\n");
        }
    }
}

int main() {
    int totalscore;
    hangman(&totalscore);
    return 0;
}