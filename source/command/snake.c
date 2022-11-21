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
}

void belok(char x, List *s){
    address p;
    address temp;
    int i = 0;
    int tempx, tempy;

    p = Last(*s);
    printf("Hasil\n");
    if((x) == 'w'){
        if ((Posisiy(First(*s)) == 0) || (Posisiy(First(*s)) > Posisiy(Next(First(*s))))) {
            printf("Kamu menabrak dinding\n");
        }
        else {
            while(p != First(*s)){
                Posisi(p) = Posisi(Prev(p));
                p = Prev(p);
            }
            Posisiy(First(*s)) -= 1;
        }
    }
    else if ((x) == 's') {
        if ((Posisiy(First(*s)) == 4) || (Posisiy(First(*s)) < Posisiy(Next(First(*s))))) {
            printf("Kamu menabrak dinding\n");
        }
        else {
            while(p != First(*s)){
                Posisi(p) = Posisi(Prev(p));
                p = Prev(p);
            }
            Posisiy(First(*s)) += 1;
        }
    }
    else if ((x) == 'a') {
        if ((Posisix(First(*s)) == 0) || (Posisix(First(*s)) > Posisix(Next(First(*s))))) {
            printf("Kamu menabrak dinding\n");
        }
        else {
            while(p != First(*s)){
                Posisi(p) = Posisi(Prev(p));
                p = Prev(p);
            }
            Posisix(First(*s)) -= 1;
        }
    }
    else if ((x) == 'd') {
        if ((Posisix(First(*s)) == 4) || (Posisix(First(*s)) < Posisix(Next(First(*s))))) {
            printf("Kamu menabrak dinding\n");
        }
        else {
            while(p != First(*s)){
                Posisi(p) = Posisi(Prev(p));
                p = Prev(p);
            }
            Posisix(First(*s)) += 1;
        }
    }
    else {
        printf("Arah tidak dikenali") ;
    }
}

int main(){
    List snake;
    char trial;
    boolean suka = false;

    CreateEmpty(&snake);
    initsnake(&snake);

    printpetak(snake);
    while (suka = true) {
        printf("Mau kemana ularnya? : ") ;
        scanf ("%c", &trial) ;
        if (trial != 'a' && trial != 'w' && trial != 'd' && trial != 's') {
            printf("Tidak bisa") ;
        }
        else {
            belok(trial, &snake);
            printpetak(snake);
        }
    }
    
    return(0);
}