#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
};

boolean isEmpty(Queue q){
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
};

boolean isFull(Queue q){
    if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1);
    else
        return (IDX_HEAD(q) - IDX_TAIL(q) == 1);
};

int length(Queue q)
{
    if (isEmpty(q)) 
        return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    else
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1);
}

void enqueue(Queue *q, ElType val)
{
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val)
{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

void displayQueue(Queue q){
    if(length(q) == 0){
        printf("[]\n");
    }
    else{
        int i = 0;
        printf("[");
        for(i; i<= length(q) - 1; i++){
            printf("%d", q.buffer[(i+IDX_HEAD(q))%CAPACITY]);
            if (i <= length(q)- 2){
                printf(",");
            }
        }
        printf("]\n");
    }
};
