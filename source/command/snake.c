#include <stdio.h>
#include "snake.h"
#include <math.h>
#include <time.h>

void printpetak(List snake){
    int i =0;
    int j = 0;
    address p;

    for(i=0; i<5; i++){
        if(i == 0){
            printf("-------------------------------\n");
        }
        for(j = 0; j < 5; j++){
            if(j == 0){
                printf("|");
            }
            if(Search(snake, i, j) != Nil){
            //if(p != Nil && Posisix(p) == j && Posisiy(p) == i) {
                p = Search(snake, i, j);
                printf("  %c  |", Info(p));
                //p = Next(p);    
            } else {
                printf("     |");
            }
        }
        printf("\n");
        printf("-------------------------------\n");
    }

}

int random()
{
    int a;
    srand(time(NULL));
    a = (rand() % (5)) + 0;
    return a;
}

/*void initSnake(List snake){
    address p;

    CreateEmpty(&snake);
    InsVLast(&snake, 'H', random(), random());

    p = First(snake);
    if(Posisiy(p) -1 >= 0){
        Insv
    }
    
}*/

int main(){
    List snake;
    address p;
    address temp;
    int x = 48;
    int i = 0;
    int a;
    int b;

    CreateEmpty(&snake);
    a = random();
    b = random();
    printf("%d %d\n", a, b);
    InsVLast(&snake, 'H', a, b);
    p = First(snake);
    while(i < 2){
        if(Posisiy(p) -1 >= 0){
            InsVLast(&snake, x+1, Posisix(p), Posisiy(p)-1);
        } else if(Posisiy(p)-1 < 0 && Posisix(p)-1 >= 0 && i == 0){
            InsVLast(&snake, x+1, Posisix(p)-1, Posisiy(p));
        }  else if(Posisiy(p)-1 < 0 && Posisix(p)-1 >= 0 && i == 1 && Posisix(p)-1 != Posisix(temp)){
            InsVLast(&snake, x+1, Posisix(p)-1, Posisiy(p)); 
        } else if(Posisiy(p)-1 < 0 && Posisix(p)-1 >= 0 && i == 1 && Posisix(p)-1 == Posisix(temp)){
            InsVLast(&snake, x+1, Posisix(p)+1, Posisiy(p)); 
        } else if (Posisiy(p)-1 < 0 && Posisix(p)-1 < 0 ){
            InsVLast(&snake, x+1, Posisix(p) + 1, Posisiy(p));
        }
        temp = p;
        p = Next(p);
        i++;
        x++;
    }
    // printf("%d\n", Posisix(p)-1);
    // if(Posisix(p)-1 >= 0){
    //     InsVLast(&snake, '1', Posisix(p)-1, Posisiy(p));
    //     InsVLast(&snake, '2', Posisix(p)-2, Posisiy(p));
    // }
    printpetak(snake);

    return(0);
}