# include "stack.h"

int main() {
    Stack s ;
    Address P ;
    CreateStack(&s) ;
    if (IsEmpty(s)) {
        Push (&s, Allocate(stringToWord("DINER DASH"))) ;
        Push (&s, Allocate(stringToWord("RNG"))) ;
        Push (&s, Allocate(stringToWord("MOBILE LEGEND"))) ;

        Pop (&s, &P) ;

        ViewStack(s) ;
    }
}