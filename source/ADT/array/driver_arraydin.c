# include "arraydin.h"

int main() {
    Word b, c, d ;
    ArrayDin a ;
    a = MakeArrayDin() ;
    b = stringToWord("DINER DASH") ;
    c = stringToWord("RNG") ;
    d = stringToWord("MOBILE LEGEND") ;

    InsertFirst (&a, b) ;
    InsertLast (&a, c) ;
    InsertAt (&a, d, 1) ;

    DeleteFirst (&a) ;
    ReverseArrayDin (&a) ;

    if (length(a) < 10) {
        Get(a, 1) ;
    }
}