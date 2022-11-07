# include "PlayGame.h"

void playGame (Queue queueGame) 
{
    Word play ;
    ListQueueGame (queueGame) ; 
    if (!IsQEmpty (queueGame)) {
        Del(&queueGame, &play) ; 

        if (isWordEqual(play, stringToWord("Dinner DASH"))) {
            printf ("Dinner DASH\n") ;
            // dinner_dash() ;
        }
        else if (isWordEqual(play, stringToWord("RNG"))) {
            rng() ;
        }
        else {
            wordToString (play) ;
            printf ("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", play) ;
        }
    }
    
    else {
        printf ("Belum ada game yang dimasukkan ke dalam antrean. Silahakan Queue Game terlebih dahulu.\n") ;
    }
}