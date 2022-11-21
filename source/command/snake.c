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
            if(Search(snake, j, i) != Nil){
            //if(p != Nil && Posisix(p) == j && Posisiy(p) == i) {
                p = Search(snake, j, i);
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

void initsnake(List * snake ){
    //List snake;
    address p;
    address temp;
    int x = 48;
    int i = 0;
    int a;
    int b;

    a = random();
    b = random();
    printf("%d %d\n", a, b);
    InsVLast(snake, 'H', a, b);
    p = First(*snake);
    while(i < 2){
        if(Posisix(p) -1 >= 0){
            InsVLast(snake, x+1, Posisix(p)-1, Posisiy(p));
        } else if(Posisix(p)-1 < 0 && Posisiy(p)-1 >= 0 && i == 0){
            InsVLast(snake, x+1, Posisix(p), Posisiy(p)-1);
        }  else if(Posisix(p)-1 < 0 && Posisiy(p)-1 >= 0 && i == 1 && Posisiy(p)-1 != Posisiy(temp)){
            InsVLast(snake, x+1, Posisix(p), Posisiy(p)-1); 
        } else if(Posisix(p)-1 < 0 && Posisiy(p)-1 >= 0 && i == 1 && Posisiy(p)-1 == Posisiy(temp)){
            InsVLast(snake, x+1, Posisix(p), Posisiy(p)+1); 
        } else if (Posisix(p)-1 < 0 && Posisiy(p)-1 < 0 ){
            InsVLast(snake, x+1, Posisix(p), Posisiy(p) + 1);
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
    //printpetak(snake);
    //return(snake);
    //return(0);
}

void belok(char x, List *s){
    address p;
    address temp;
    int i = 0;

    p = First(*s);
    printf("tes\n");
    if((x) == 'w'){
        if(Posisix(p)-1 >= 0) {
            temp = p;
            Posisix(p) = Posisix(p)-1;
            //printf("%d %d\n", Posisix(p), Posisiy(p));
            p = Next(p);
            //printf()

            for(i = 0; i < 2; i++){
                Posisix(p) = Posisix(temp);
                Posisiy(p) = Posisiy(temp);
                printf("%c %d %d\n", Info(p), Posisix(temp), Posisiy(temp));
                temp = Next(temp);
                p =Next(p);
            }
        } else {
            printf("Kamu menabrak dinding\n");
        }
    }
    //return(s);
}

int main(){
    List snake;
    char trial;

    CreateEmpty(&snake);
    initsnake(&snake);
    //printf("%c", Info(First(snake)));
    printpetak(snake);
    
    trial = 'w';
    printf("%c\n", Info(First(snake)));
    //printpetak(snake);
    belok(trial, &snake);
    
    
    printpetak(snake);
    return(0);
}

/*GARA GARA PAKE MATRIKS JADINYA KEBALIK POSISI X SAMA YNYA, MAKA NANTI INPUTNYA DITUKER*/