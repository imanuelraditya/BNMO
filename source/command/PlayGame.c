# include "PlayGame.h"

void playGame (Queue* queueGame) 
{
    Word play ;
    ListQueueGame (*queueGame) ; 

    printf ("\n") ;

    if (!IsQEmpty (*queueGame)) {
        Del(queueGame, &play) ; 

        if (isWordEqual(play, stringToWord("DINER DASH"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            dinerdash() ;
        }
        else if (isWordEqual(play, stringToWord("RNG"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            rng() ;
        }
        else {
            printf ("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", wordToString(play)) ;
        }
    }
    
    else {
        printf ("Belum ada game yang dimasukkan ke dalam antrean. Silahakan Queue Game terlebih dahulu.\n") ;
    }
}