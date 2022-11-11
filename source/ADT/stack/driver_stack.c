# include "stack.h"

int main() {
    Stack s ;
    Address P ;
    CreateStack(&s) ;
    if (IsStackEmpty(s)) {
        Push (&s, Allocate(1)) ;
        Push (&s, Allocate(2)) ;
        Push (&s, Allocate(3)) ;

        Pop (&s, &P) ;

        ViewStack(s) ;
    }
}