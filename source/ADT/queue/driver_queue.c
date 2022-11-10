# include "queue.h"

int main () {
    Word b, c, d, val ;
    Queue Q ;
    int Max = 100 ;
    QCreateEmpty(&Q, Max) ;

    b = stringToWord("DINER DASH") ;
    c = stringToWord("RNG") ;
    d = stringToWord("MOBILE LEGEND") ;

    Add (&Q, b) ;
    Add (&Q, c) ;
    Add (&Q, d) ;

    Del (&Q, &val) ;

    if (!IsQEmpty(Q)) {
        ListQueueGame(Q) ;
    }

    return 0;
}