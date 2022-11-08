#include <stdio.h>
#include "queue.h"

void CreateQueueInt(QueueInt *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
};

boolean isQueueIntEmpty(QueueInt q){
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
};

boolean isQueueIntFull(QueueInt q){
    if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1);
    else
        return (IDX_HEAD(q) - IDX_TAIL(q) == 1);
};

int QueueIntLength(QueueInt q)
{
    if (isQueueIntEmpty(q)) 
        return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    else
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1);
}

void enqueue(QueueInt *q, ElTypeInt val)
{
    if (isQueueIntEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    TAIL(*q) = val;
}

void dequeue(QueueInt *q, ElTypeInt *val)
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

void displayQueueInt(QueueInt q){
    if(QueueIntLength(q) == 0){
        printf("[]\n");
    }
    else{
        int i = 0;
        printf("[");
        for(i; i<= QueueIntLength(q) - 1; i++){
            printf("%d", q.buffer[(i+IDX_HEAD(q))%CAPACITY]);
            if (i <= QueueIntLength(q)- 2){
                printf(",");
            }
        }
        printf("]\n");
    }
};
