#include <stdio.h>
#include <stdlib.h>
#include "source/command/list_game.h"
#include "source/ADT/mesinkata/mesinkata.h"
#include "source/command/startGame.h"
#include "source/command/CreateGame.h"

int main() {
    ArrayDin array = MakeArrayDin();
    // InsertFirst(&array, stringToWord("Diner Dash"));
    // InsertFirst(&array, stringToWord("Fishing Frenzy"));
    // InsertFirst(&array, stringToWord("Farm Frenzy"));
    // InsertFirst(&array, stringToWord("Farm Frenzy 2"));
    // InsertFirst(&array, stringToWord("Insaniquarium"));
    startGame(&array);
    ListGame(array);
    CreateGame(&array);
    ListGame(array);

    return 0;
}

// compilenya : gcc test.c source/command/list_game.c source/command/startGame.c source/ADT/mesinkata/mesinkata.c source/ADT/mesinkarakter/mesinkarakter.c source/ADT/array/arraydin.c -o triall

// int main() {
//     startWFile("data/config.txt");
//     while (!EndWord) {
//         printf("%s\n", currentWord.TabWord);
//         ADv();
//     }
//     return 0;
// }