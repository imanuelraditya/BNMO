# include "arraydin.h"

int main() {
    Word b, c, d, e, f, g, h, i, x;
    int L;
    ArrayDin a, arr ;
    a = MakeArrayDin() ;
    b = stringToWord("DINER DASH") ;
    c = stringToWord("RNG") ;
    d = stringToWord("MOBILE LEGEND") ;
    e = stringToWord("POU") ;
    f = stringToWord("LALALA") ;
    g = stringToWord("SINGSING") ;
    h = stringToWord("POUPOU") ;
    i = stringToWord("CAT") ;

    InsertFirst (&a, b) ;
    InsertLast (&a, c) ;
    InsertAt (&a, d, 1) ;
    InsertLast (&a, e);
    InsertFirst (&a, f) ;
    InsertFirst (&a, g) ;
    InsertFirst (&a, h) ;
    InsertAt (&a, i, 1) ;

    DeleteFirst (&a) ;
    DeleteAt(&a, 2);
    ReverseArrayDin (&a) ;
    DeleteFirst (&a) ;
    DeleteAt(&a, 2);
    DeleteAt(&a, 1);
    DeleteAt(&a, 3);
    ReverseArrayDin (&a) ;
    ReverseArrayDin (&a) ;

    if (length(a) < 10) {
        x = Get(a, 1) ;
    }

    if (!IsEmpty(a) && Length(a) > 0) {
        L = SearchArrayDin(a, stringToWord("TOWER OF HANOI"));
    }

    if (L >= 0) {
        arr = CopyArrayDin(a);
        PrintArrayDin(arr);
    }
    
    return 0;
}