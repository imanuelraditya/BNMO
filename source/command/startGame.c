#include <stdio.h>
#include "startGame.h"

void startGame() {
    int jumlah = 0;
    int i = 0;

    startWFile("data/config.txt");
    
    printf("%s\n", currentWord.TabWord);
    printf("%d\n", currentWord.Length);

    for(i = 0 ; i < currentWord.Length ; i++) {
        jumlah = (jumlah * 10 + (currentWord.TabWord[i] - '0'));
    }

    printf("%d\n", jumlah); //ini kebawah cuma buat ngetes
    printf("%d\n", jumlah + 7);
    advNewlineFile();
    printf("%s\n", currentWord.TabWord);
    advNewlineFile();
    printf("%s\n", currentWord.TabWord);
    advNewlineFile();
    printf("%s\n", currentWord.TabWord);
    advNewlineFile();
    printf("%s\n", currentWord.TabWord);
    advNewlineFile();
    printf("%s\n", currentWord.TabWord);

    // ini start game versi beneran kalo uda ada listnya
    // for (i = 0 ; i < jumlah ; i++) {
    //     advNewlineFile();
    //     currentWord.TabWord() dimasukin ke list game
    // }
}
