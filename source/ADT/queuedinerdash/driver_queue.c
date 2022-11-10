# include "queue.h"
int main() {
    QueueInt Q ;
    ElTypeInt a;
    a.cookTime = 2 ;
    a.expTime = 5 ;
    a.price = 51000 ;
    CreateQueueInt(&Q) ;
    if (isQueueIntEmpty(Q)) {
        enqueue(&Q, a) ;
        enqueue(&Q, a) ;
    }
    if (!isQueueIntFull(Q)) {
        ElTypeInt val ;
        dequeue(&Q, &val) ;
    }

    if (QueueIntLength(Q) < 5) {
        displayQueueInt(Q) ;
    }

    return 0 ;
}