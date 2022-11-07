#include <stdio.h>
#include <stdlib.h>
#include "source/command/list_game.h"
#include "source/ADT/mesinkata/mesinkata.h"
#include "source/ADT/mesinkarakter/mesinkarakter.h"
#include "source/ADT/array/arraydin.h"
#include "source/ADT/queue/queue.h"
#include "source/command/startGame.h"
#include "source/command/CreateGame.h"
#include "source/command/load.h"
#include "source/command/welcome.h"

int main() {
    // ArrayDin array = MakeArrayDin();
    // // // InsertFirst(&array, stringToWord("Diner Dash"));
    // // // InsertFirst(&array, stringToWord("Fishing Frenzy"));
    // // // InsertFirst(&array, stringToWord("Farm Frenzy"));
    // // // InsertFirst(&array, stringToWord("Farm Frenzy 2"));
    // // // InsertFirst(&array, stringToWord("Insaniquarium"));
    
    // // startGame(&array);
    // // ListGame(array);
    // // CreateGame(&array);
    // // ListGame(array);

    // char* maindir;

    // maindir = "data/";

    // printf("Masukkan command: ");
    // STARTCOMMAND();

    // // ADVCOMMAND();
    // // printf("%s", wordToString(currentCommand));

    // if (isWordEqual(currentCommand, stringToWord("LOAD"))) {
    //     ADVCOMMAND();
    //     // printf("%s", wordToString(currentCommand));
    //     load(currentCommand, &array);
    //     ListGame(array);
    // }

    // printf("%s", wordToString(concatWord(stringToWord(maindir), currentCommand)));
    // load(currentCommand, &array);
    // ListGame(array);

    // Queue Q;
    // QCreateEmpty(&Q, 10);

    // Add(&Q, stringToWord("TOMB RAIDER"));
    // Add(&Q, stringToWord("FARM FRENZY"));
    // Add(&Q, stringToWord("FISHING FRENZY"));
    // Add(&Q, stringToWord("INSANIQUARIUM"));
    // Add(&Q, stringToWord("DINER DASH"));

    // ListQueueGame(Q);

    welcome();
    
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