#include <stdio.h>
#include "snake.h"
#include <math.h>
#include <time.h>

void printpetak(List snake, List food){
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
            } else if(Search(food, j, i) != Nil){
            //if(p != Nil && Posisix(p) == j && Posisiy(p) == i) {
                p = Search(food, j, i);
                printf("  %c  |", Info(p));
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
    //printf("%d %d\n", a, b);
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

void dropfood(List*snake, List* food){
    int x;
    int y;

    x = random();
    y = random();

    while(Search((*snake), x, y) != Nil){
        x = random();
        y = random();
    }
    printf("%d %d\n", x, y);
    InsVLast(food, 'O', x, y);
}

void belok(char x, List *s){
    address p;
    address temp;
    int i = 0;
    int tempx, tempy;

    p = Last(*s);
    printf("\n");
    printf("Berhasil bergerak!\n");
    printf("Berikut merupakan peta permainan:\n");
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
    List food;
    char command;
    boolean suka = false;
    boolean done = false;
    boolean eat = false;
    int test = 0;

    CreateEmpty(&food);
    CreateEmpty(&snake);
    initsnake(&snake);

    printpetak(snake, food);
    while (suka = true) {
        printf("Silahkan masukkan command anda: ") ;
        //scanf ("%c", &trial) ;
        STARTCOMMAND();
        if(currentCommand.Length > 1 || commandWord(currentCommand) > 1){  // ini udah bisa, tapi kalo misal ngetik commandnya lebih dari satu kata, kaya halo halo halo, nanti pemberitahuan
            printf("\n");                                                   // command tidak validnya juga ke print 3 kali :)
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        } else{
            command = currentCommand.TabWord[0];
            if (command != 'a' && command != 'w' && command != 'd' && command != 's') {
                printf("\n");
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n") ;
            }
            else {
                belok(command, &snake);
                printpetak(snake, food);
            }
        }
        if(!done && !eat){ // dropfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
            dropfood(&snake, &food);
            done = true;
        }
    }    

        // if (trial != 'a' && trial != 'w' && trial != 'd' && trial != 's') {
        //     printf("\n");
        //     printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n") ;
        // }
        // else {
        //     belok(trial, &snake);
        //     printpetak(snake);
        // }
    
    
    
    return(0);
}