# include "PlayGame.h"

void playGame (Queue queueGame) 
{
    Word play ;
    printf ("Berikut adalah daftar game mu\n") ;
    ListQueueGame (queueGame) ; 
    if (!IsQEmpty (queueGame)) {
        Del (&queueGame, &play) ; 
    }
    if (isWordEqual(play, stringToWord("Dinner DASH"))) {
        dinner_DASH() ;
    }
    else if (isWordEqual(play, stringToWord("RNG"))) {
        RNG() ;
    }
    else {
        wordToString (play) ;
        printf ("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", play) ;
    }
}