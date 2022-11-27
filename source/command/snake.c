#include <stdio.h>
#include "snake.h"
#include <math.h>
#include <time.h>

void printpetak(List snake, List food, List meteor, List obstacle){
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
                if(stringLength(Info(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Info(p));
                //p = Next(p);    
            } else if(Search(food, j, i) != Nil){
            //if(p != Nil && Posisix(p) == j && Posisiy(p) == i) {
                p = Search(food, j, i);
                if(stringLength(Info(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Info(p));
            } else if(Search(meteor, j, i) != Nil){
                p = Search(meteor, j, i);
                if(stringLength(Info(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Info(p));
            } else if(Search(obstacle, j, i) != Nil){
                p = Search(obstacle, j, i);
                if(stringLength(Info(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s |", Info(p)); 
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

void initsnake(List * snake){
    address p;
    address temp;
    int x = 0;
    int i = 0;
    int a;
    int b;

    a = random();
    b = random();
    
    InsVLast(snake, "H", a, b);
    p = First(*snake);
    while(i < 2){
        if(Posisix(p) -1 >= 0){
            InsVLast(snake, wordToString(intToWord(x+1)), Posisix(p)-1, Posisiy(p));
        } else if(Posisix(p)-1 < 0 && Posisiy(p)-1 >= 0 && i == 0){
            InsVLast(snake, wordToString(intToWord(x+1)), Posisix(p), Posisiy(p)-1);
        }  else if(Posisix(p)-1 < 0 && Posisiy(p)-1 >= 0 && i == 1 && Posisiy(p)-1 != Posisiy(temp)){
            InsVLast(snake, wordToString(intToWord(x+1)), Posisix(p), Posisiy(p)-1); 
        } else if(Posisix(p)-1 < 0 && Posisiy(p)-1 >= 0 && i == 1 && Posisiy(p)-1 == Posisiy(temp)){
            InsVLast(snake, wordToString(intToWord(x+1)), Posisix(p), Posisiy(p)+1); 
        } else if (Posisix(p)-1 < 0 && Posisiy(p)-1 < 0 ){
            InsVLast(snake, wordToString(intToWord(x+1)), Posisix(p), Posisiy(p) + 1);
        }
        temp = p;
        p = Next(p);
        i++;
        x++;
    }
}

void dropfood(List*snake, List* food, List * posPanas, List * obstacle){
    int x;
    int y;

    x = random();
    y = random();

    if(!IsEmptyList(*obstacle)){
        if(!IsEmptyList(*posPanas)){
            while(Search((*snake), x, y) != Nil || Search((*posPanas), x, y) != Nil || Search((*obstacle), x, y) != Nil){
                x = random();
                y = random();
            }
        } else {
            while(Search((*snake), x, y) != Nil  || Search((*obstacle), x, y) != Nil){
                x = random();
                y = random();
            }
        }
    } else {
        while(Search((*snake), x, y) != Nil){
            x = random();
            y = random();
        }
    }
    //printf("food : %d %d\n", x, y);
    InsVLast(food, "O", x, y);
}

void dropmeteor(List* food, List* obstacle, List * meteor){
    int r;
    int s;

    r = random();
    s = random();

    while(Search((*food), r, s) != Nil || Search((*obstacle), r, s) != Nil){
        r = random();
        s = random();
    }
    //printf("meteor : %d %d\n", x, y);
    InsVLast(meteor, "M", r, s);
}

void dropobs(List * snake, List * food, List * obstacle){
    int a;
    int b;

    a = random();
    b = random();
    while(Search((*snake), a, b) != Nil || Search((*food), a, b) != Nil){
        a = random();
        b = random();
    }
    //printf("%d %d\n", a, b);
    InsVLast(obstacle, "###", a, b);    
}

void makan(List * snake, List * food, List * obstacle){
    elmntype tempInfo;
    int tempx, tempy;

    if((Posisix(First(*food)) == Posisix(First(*snake))) && (Posisiy(First(*food)) == Posisiy(First(*snake)))) {
        DelVLast(food, &tempInfo, &tempx, &tempy);

        if(Posisix(Last(*snake)) != 0){
            if(Search((*snake), Posisix(Last(*snake))-1, Posisiy(Last(*snake))) == Nil && Search((*obstacle), Posisix(Last(*snake))-1, Posisiy(Last(*snake))) == Nil) {
                InsVLast(snake, wordToString(intToWord(wordToInt(stringToWord(Info(Last(*snake)))) + 1)), Posisix(Last(*snake))-1, Posisiy(Last(*snake)));
            } else if(Posisiy(Last(*snake)) != 0 && Search((*snake), Posisix(Last(*snake)), Posisiy(Last(*snake))-1) == Nil && Search((*obstacle), Posisix(Last(*snake)), Posisiy(Last(*snake))-1) == Nil){
                InsVLast(snake, wordToString(intToWord(wordToInt(stringToWord(Info(Last(*snake)))) + 1)), Posisix(Last(*snake)), Posisiy(Last(*snake))-1);
            } else if(Search((*snake), Posisix(Last(*snake)), Posisiy(Last(*snake))+1) == Nil && Search((*obstacle), Posisix(Last(*snake)), Posisiy(Last(*snake))+1) == Nil){
                InsVLast(snake, wordToString(intToWord(wordToInt(stringToWord(Info(Last(*snake)))) + 1)), Posisix(Last(*snake)), Posisiy(Last(*snake))+1);
            } else if(Search((*snake), Posisix(Last(*snake))+1, Posisiy(Last(*snake))) == Nil && Search((*obstacle), Posisix(Last(*snake))+1, Posisiy(Last(*snake))) == Nil){
                InsVLast(snake, wordToString(intToWord(wordToInt(stringToWord(Info(Last(*snake)))) + 1)), Posisix(Last(*snake)) + 1, Posisiy(Last(*snake)));
            }
        } else if(Posisix(Last(*snake)) == 0){
            if(Posisiy(Last(*snake)) != 0 && Search((*snake), Posisix(Last(*snake)), Posisiy(Last(*snake))-1) == Nil && Search((*obstacle), Posisix(Last(*snake)), Posisiy(Last(*snake))-1) == Nil){
                InsVLast(snake, wordToString(intToWord(wordToInt(stringToWord(Info(Last(*snake)))) + 1)), Posisix(Last(*snake)), Posisiy(Last(*snake))-1);
            } else if(Search((*snake), Posisix(Last(*snake)), Posisiy(Last(*snake))+1) == Nil && Search((*obstacle), Posisix(Last(*snake)), Posisiy(Last(*snake))+1) == Nil) {
                InsVLast(snake, wordToString(intToWord(wordToInt(stringToWord(Info(Last(*snake)))) + 1)), Posisix(Last(*snake)), Posisiy(Last(*snake)) + 1);
            } else if(Posisiy(Last(*snake)) == 0 && Posisiy(Prev(Last(*snake))) == Posisiy(Last(*snake)) + 1 && Search((*obstacle), Posisix(Last(*snake))+1, Posisiy(Last(*snake))) == Nil) {
                InsVLast(snake, wordToString(intToWord(wordToInt(stringToWord(Info(Last(*snake)))) + 1)), Posisix(Last(*snake)) + 1, Posisiy(Last(*snake)));
            }
        }
    }
}

void hit(List * snake, List * meteor, location * temp){
    address p;
    int tempx, tempy;

    if(Search(*snake, Posisix(First(*meteor)), Posisiy(First(*meteor))) == Nil){
        if((*temp).x != -1){
            p = Search(*snake, (*temp).x, (*temp).y);

            while(p != Nil){
                Info(p) = wordToString(intToWord(wordToInt(stringToWord(Info(p))) - 1));
                p = Next(p);
            }
        }    
    }
}

int lengthsnake(List snake){
    int count = 0;
    while (First(snake) != Nil) {
        count++;
        First(snake) = Next(First(snake));
    }
    return count;
}

void belok(char x, List *s, List * posPanas, List * obstacle, boolean * gagal, boolean * menang){
    address p;
    address temp;
    int i = 0;
    int tempx, tempy;

    p = Last(*s);
    printf("\n");

    if((x) == 'w'){
        if(Search((*posPanas), Posisix(First(*s)), Posisiy(First(*s))-1) != Nil){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if ((Posisiy(First(*s)) == 0)) {
            printf("Anda menabrak dinding :<\n");
            *gagal = true;
            *menang = true;
        } else if (Search((*obstacle), Posisix(First(*s)), Posisiy(First(*s))-1) != Nil) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if (Posisiy(Next(First(*s))) == Posisiy(First(*s))-1 && Posisix(Next(First(*s))) == Posisix(First(*s))) {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else {
            if (Search((*s), Posisix(First(*s)), Posisiy(First(*s))-1) != Nil){
                printf("Anda menabrak badan sendiri :<\n");
                *menang = true;
            } else {
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != First(*s)){
                    Posisi(p) = Posisi(Prev(p));
                    p = Prev(p);
                }
                Posisiy(First(*s)) -= 1;
                *gagal = false;
            }
        }
    }
    else if ((x) == 's') {
        if (Search((*posPanas), Posisix(First(*s)), Posisiy(First(*s))+1) != Nil){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        else if ((Posisiy(First(*s)) == 4)) {
            printf("Anda menabrak dinding :<\n");
            *gagal = true;
            *menang = true;
        }
        else if (Search((*obstacle), Posisix(First(*s)), Posisiy(First(*s))+1) != Nil) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if(Posisiy(Next(First(*s))) == Posisiy(First(*s))+1 && Posisix(Next(First(*s))) == Posisix(First(*s))){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {
            if (Search((*s), Posisix(First(*s)), Posisiy(First(*s))+1) != Nil){
                printf("Anda menabrak badan sendiri :<\n");
                *menang = true;
            } else {
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != First(*s)){
                    Posisi(p) = Posisi(Prev(p));
                    p = Prev(p);
                }
                Posisiy(First(*s)) += 1;
                *gagal = false;
            }
        }
    }
    else if ((x) == 'a') {
        if (Search((*posPanas), Posisix(First(*s)) -1 , Posisiy(First(*s))) != Nil){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        else if ((Posisix(First(*s)) == 0)) {
            printf("Anda menabrak dinding :<\n");
            *gagal = true;
            *menang = true;
        }
        else if (Search((*obstacle), Posisix(First(*s)) -1 , Posisiy(First(*s))) != Nil) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if(Posisix(Next(First(*s))) == Posisix(First(*s))-1 && Posisiy(Next(First(*s))) == Posisiy(First(*s))){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {
            if (Search((*s), Posisix(First(*s))-1, Posisiy(First(*s))) != Nil){
                printf("Anda menabrak badan sendiri :<\n");
                *menang = true;
            } else {
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != First(*s)){
                    Posisi(p) = Posisi(Prev(p));
                    p = Prev(p);
                }
                Posisix(First(*s)) -= 1;
                *gagal = false;
            }
        }
    }
    else if ((x) == 'd') {
        if (Search((*posPanas), Posisix(First(*s)) + 1, Posisiy(First(*s))) != Nil){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        else if ((Posisix(First(*s)) == 4)) {
            printf("Anda menabrak dinding :<\n");
            *gagal = true;
            *menang = true;
        }
        else if (Search((*obstacle), Posisix(First(*s)) + 1, Posisiy(First(*s))) != Nil) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if(Posisix(Next(First(*s))) == Posisix(First(*s))+1 && Posisiy(Next(First(*s))) == Posisiy(First(*s))){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {
            if (Search((*s), Posisix(First(*s))+1, Posisiy(First(*s))) != Nil){
                printf("Anda menabrak badan sendiri :<\n");
                *menang = true;
            } else {
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != First(*s)){
                    Posisi(p) = Posisi(Prev(p));
                    p = Prev(p);
                }
                Posisix(First(*s)) += 1;
                *gagal = false;
            }
        }
    }
    else {
        printf("Arah tidak dikenali") ;
    }
}

int main(){
    List snake;
    List food;
    List meteor;
    List posPanas;
    List obstacle;
    
    char command;
    boolean validasicommand = false;
    boolean menang = false;
    boolean donef = false;
    boolean gagal = false;
    boolean kenakepala = false;
    int test = 0;
    int turn = 1;
    //location posPanas;

    CreateEmpty(&food);
    CreateEmpty(&snake);
    CreateEmpty(&meteor);
    CreateEmpty(&posPanas);
    CreateEmpty(&obstacle);
    initsnake(&snake);

    printf("\n                 Selamat datang di snake on meteor!\n");
    printf(".+:*+.+:*+.+:*+. P A N D U A N  S I N G K A T  G A M E .+*:+.+*:+.+*:+. \n");
    printf("o  : makanan yang harus dicapai agar snake bertambah panjang\n");
    printf("H  : Head dari snake yang akan diikuti oleh badannya (1, 2, dst.)\n");
    printf("M  : meteor yang akan muncul secara acak dan menyerang snake\n");
    printf("## : obstacle yang harus dihindari, apabila menabraknya snake akan mati\n\n");

    printf("\nMengenerate peta, snake dan makanan\n");
    printf("\nBerhasil digenerate!\n");

    printf("\n----------------------------------\n\n");

    dropfood(&snake, &food, &posPanas, &obstacle);
    donef = true;
    dropobs(&snake, &food, &obstacle);
    printpetak(snake, food, meteor, obstacle);
    while (!menang) {
        if(!donef){ // dropfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
            dropfood(&snake, &food, &posPanas, &obstacle);
            
            donef = true;
        }
        printf("\nTURN %d\n", turn);
        printf("Silahkan masukkan command anda: ") ;
        
        STARTCOMMAND();
        if(currentCommand.Length > 1 || commandWord(currentCommand) > 1){  
            printf("\n");                                                   
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        } else{
            command = currentCommand.TabWord[0];
            if (command != 'a' && command != 'w' && command != 'd' && command != 's') {
                printf("\n");
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n\n") ;
            }
            else {
                validasicommand = true;
                belok(command, &snake, &posPanas, &obstacle, &gagal, &menang);
                
                if (!menang) {
                    if(gagal == true ){
                        printf("Silahkan masukkan command lainnya\n");
                    } else {
                        elmntype tempInfo;
                        int tempx, tempy;

                        if(!IsEmptyList(meteor) && !gagal){
                            DelVLast(&meteor, &tempInfo, &tempx, &tempy);
                        }
                        if((Posisix(First(food)) == Posisix(First(snake))) && (Posisiy(First(food)) == Posisiy(First(snake))) && !gagal) {
                            makan(&snake, &food, &obstacle);
                            donef = false;
                           
                        }
                        if(!donef){ // dropfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
                            dropfood(&snake, &food, &posPanas, &obstacle);
                            
                            donef = true;
                        }
                        
                        dropmeteor(&food, &obstacle, &meteor);
                        
                        if(Search(snake, Posisix(First(meteor)), Posisiy(First(meteor))) != Nil){
                            //kondisional search posisinya meteor sama kaya posisinya snakenya apa engga
                            if(Search(snake, Posisix(First(meteor)), Posisiy(First(meteor))) == First(snake)){
                                elmntype temphead;
                                int headx;
                                int heady;
                                DelVFirst(&snake, &temphead, &headx, &heady);
                                menang = true;
                                kenakepala = true;
                                printpetak(snake, food, meteor, obstacle);
                                printf("Kepala snake terkena meteor :<\n");
                            } else {
                                elmntype tempbadan;
                                location postemp;
                                address p;

                                postemp.x = -1;
                                postemp.y = -1;
                                p = Search(snake, Posisix(First(meteor)), Posisiy(First(meteor)));
                                if(Next(p) != Nil){
                                    postemp = Posisi(Next(p));
                                }
                                DelP(&snake, tempbadan, Posisix(First(meteor)), Posisiy(First(meteor)));
                                printpetak(snake, food, meteor, obstacle);
                                hit(&snake, &meteor, &postemp);
                                printf("Anda terkena meteor\n");
                                printf("Berikut merupakan peta permainan sekarang:\n");
                                printpetak(snake, food, meteor, obstacle);
                                printf("Silahkan lanjutkan permainan\n");
                                
                                InsVLast(&posPanas, wordToString(intToWord(turn)), Posisix(First(meteor)), Posisiy(First(meteor)));
                            }
                        } else {
                
                            printpetak(snake, food, meteor, obstacle);
                            printf("Anda beruntung tidak terkena meteor! ");
                            printf("Silahkan lanjutkan permainan\n");
                        }    
                        
                        turn++;
                        if(!IsEmptyList(posPanas)){
                            if(wordToInt(stringToWord(Info(First(posPanas)))) + 2 == turn ){
                                elmntype temppanas;
                                int px, py;
                                DelVFirst(&posPanas, &temppanas, &px, &py);
                            }
                        }
                    }
                }
            }
        } 
    }
    int length, score;
    length = lengthsnake(snake);
    score = length*2;
    
    printf("Game berakhir!\n");  
    printf("Skor: %d", score);
    return(0);
}

//gcc source/command/snake.c source/ADT/listdp/listdp.c source/ADT/mesinkarakter/mesinkarakter.c source/ADT/mesinkata/mesinkata.c -o s
