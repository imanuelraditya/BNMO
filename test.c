#include <stdio.h>
#include <stdlib.h>
#include "source/ADT/array/arraydin.h"
#include "source/command/list_game.h"
#include "source/ADT/mesinkata/mesinkata.h"

int main() {
    ArrayDin array = MakeArrayDin();
    InsertFirst(&array, stringToWord("Diner Dash"));
    InsertFirst(&array, stringToWord("Fishing Frenzy"));
    InsertFirst(&array, stringToWord("Farm Frenzy"));
    InsertFirst(&array, stringToWord("Farm Frenzy 2"));
    InsertFirst(&array, stringToWord("Insaniquarium"));

    ListGame(array);

    return 0;
}

// int main() {
//     startWFile("data/config.txt");
//     while (!EndWord) {
//         printf("%s\n", currentWord.TabWord);
//         ADv();
//     }
//     return 0;
// }