# include <stdio.h>
# include "boolean.h"
# include "queue.h"
#include <stdlib.h>

void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return (length(q) == CAPACITY) ;
}

int length(Queue q) {
    int length;
    if (isEmpty(q)){
        length = 0;
    }
    else if(IDX_HEAD(q) > IDX_TAIL(q)){
        length = (IDX_TAIL(q) + 1) + (CAPACITY - IDX_HEAD(q));
    }
    else if(IDX_HEAD(q) <= IDX_TAIL(q)){
        length = IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
    return length;
}

void enqueue(Queue *q, ElType val) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else {
        IDX_TAIL(*q) = (IDX_HEAD(*q) + length(*q)) % CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val) {
   *val = HEAD(*q);
	if (IDX_HEAD(*q)==IDX_TAIL(*q)){
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	}
	else {
		IDX_HEAD(*q) = ((IDX_HEAD(*q)+1) % CAPACITY);
	}
}

void displayQueue(Queue q) {
    int i ;
    printf ("[") ;
    if (!isEmpty(q)) {
        if (IDX_HEAD(q) > IDX_TAIL(q)) {
            for (i = IDX_HEAD(q); i < CAPACITY; i++) {
                printf("%d,",q.buffer[i]) ;
            }
            for (i = 0; i <= IDX_TAIL(q);i++) {
                printf ("%d", q.buffer[i]) ;
                if (i != IDX_TAIL(q)) {
                    printf(",") ;
                }
            }
        }
        else {
            for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
                printf("%d", q.buffer[i]) ;
                if (i != IDX_TAIL(q)) {
                    printf(",") ;
                }
            }
        }
    }
    printf("]\n") ;
}