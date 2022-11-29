#include <stdio.h>
#include "snake.h"
#include <math.h>
#include <time.h>

void printpetak(List snake, List food, List meteor, List obstacle){
    int i =0;
    int j = 0;
    addressldp p;

    for(i=0; i<5; i++){
        if(i == 0){
            printf("-------------------------------\n");
        }
        for(j = 0; j < 5; j++){
            if(j == 0){
                printf("|");
            }
            if(Searchlistdp(snake, j, i) != Nilldp){
                p = Searchlistdp(snake, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
                //p = Nextldp(p);    
            } else if(Searchlistdp(food, j, i) != Nilldp){
                p = Searchlistdp(food, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
            } else if(Searchlistdp(meteor, j, i) != Nilldp){
                p = Searchlistdp(meteor, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
            } else if(Searchlistdp(obstacle, j, i) != Nilldp){
                p = Searchlistdp(obstacle, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s |", Infoldp(p)); 
            } else {
                printf("     |");
            }
        }
        printf("\n");
        printf("-------------------------------\n");
    }

}

int randoms()
{
    int a;
    srand(time(NULL));
    a = (rand() % (5)) + 0;
    return a;
}

void initsnake(List * snake){
    addressldp p;
    addressldp temp;
    int x = 0;
    int i = 0;
    int a;
    int b;

    a = randoms();
    b = randoms();
    
    InsVLastlistdp(snake, "H", a, b);
    p = Firstldp(*snake);
    while(i < 2){
        if(Posisix(p)-1 >= 0){
            InsVLastlistdp(snake, wordToString(intToWord(x+1)), (Posisix(p)-1) % 5, Posisiy(p));
        } else {
            InsVLastlistdp(snake, wordToString(intToWord(x+1)), (Posisix(p)-1 + 5), Posisiy(p));
        }
        temp = p;
        p = Nextldp(p);
        i++;
        x++;
    }
}

void dropfood(List*snake, List* food, List * posPanas, List * obstacle){
    int x;
    int y;

    x = randoms();
    y = randoms();

    if(!IsEmptylistdp(*obstacle)){
        if(!IsEmptylistdp(*posPanas)){
            while(Searchlistdp((*snake), x, y) != Nilldp || Searchlistdp((*posPanas), x, y) != Nilldp || Searchlistdp((*obstacle), x, y) != Nilldp){
                x = randoms();
                y = randoms();
            }
        } else {
            while(Searchlistdp((*snake), x, y) != Nilldp  || Searchlistdp((*obstacle), x, y) != Nilldp){
                x = randoms();
                y = randoms();
            }
        }
    } else {
        while(Searchlistdp((*snake), x, y) != Nilldp){
            x = randoms();
            y = randoms();
        }
    }
    //printf("food : %d %d\n", x, y);
    InsVLastlistdp(food, "O", x, y);
}

void dropmeteor(List* food, List* obstacle, List * meteor){
    int r;
    int s;

    r = randoms();
    s = randoms();

    while(Searchlistdp((*food), r, s) != Nilldp || Searchlistdp((*obstacle), r, s) != Nilldp){
        r = randoms();
        s = randoms();
    }
    //printf("meteor : %d %d\n", x, y);
    InsVLastlistdp(meteor, "M", r, s);
}

void dropobs(List * snake, List * food, List * obstacle){
    int a;
    int b;

    a = randoms();
    b = randoms();
    while(Searchlistdp((*snake), a, b) != Nilldp || Searchlistdp((*food), a, b) != Nilldp){
        a = randoms();
        b = randoms();
    }
    //printf("%d %d\n", a, b);
    InsVLastlistdp(obstacle, "###", a, b);    
}

void makan(List * snake, List * food, List * obstacle, boolean * menang){
    elmntype tempInfoldp;
    int tempx, tempy;

    if((Posisix(Firstldp(*food)) == Posisix(Firstldp(*snake))) && (Posisiy(Firstldp(*food)) == Posisiy(Firstldp(*snake)))) {
        DelVLastlistdp(food, &tempInfoldp, &tempx, &tempy);

        if(Posisix(Lastldp(*snake)) != 0){
            if(Searchlistdp((*snake), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake))) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake)));
            } else if(Posisiy(Lastldp(*snake)) != 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 +5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1+5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5);
            } else if(Posisiy(Lastldp(*snake)) != 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1);
            } else if(Posisiy(Lastldp(*snake)) == 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1-5);
            } else if(Searchlistdp((*snake), (Posisix(Lastldp(*snake))+1)%5, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obstacle), (Posisix(Lastldp(*snake))+1)%5, Posisiy(Lastldp(*snake))) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), (Posisix(Lastldp(*snake)) + 1)%5, Posisiy(Lastldp(*snake)));
            }
        } else if(Posisix(Lastldp(*snake)) == 0){
            if(Searchlistdp((*snake), Posisix(Lastldp(*snake))-1 + 5, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)) -1 + 5, Posisiy(Lastldp(*snake))) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake))-1 + 5, Posisiy(Lastldp(*snake)));
            } else if(Posisiy(Lastldp(*snake)) != 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5);
            } else if(Posisiy(Lastldp(*snake)) != 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake)) + 1);
            } else if(Posisiy(Lastldp(*snake)) == 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake)) + 1 - 5);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Posisiy(Prevldp(Lastldp(*snake))) == Posisiy(Lastldp(*snake)) + 1 && Searchlistdp((*obstacle), (Posisix(Lastldp(*snake))+1) % 5, Posisiy(Lastldp(*snake))) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), (Posisix(Lastldp(*snake)) + 1) % 5, Posisiy(Lastldp(*snake)));
            }
        } else {
            printf("Ekor snake tidak dapat di-spawn ke arah manapun :<\n");
            *menang = true;
        }
    }
}

void hit(List * snake, List * meteor, location * temp){
    addressldp p;
    int tempx, tempy;

    if(Searchlistdp(*snake, Posisix(Firstldp(*meteor)), Posisiy(Firstldp(*meteor))) == Nilldp){
        if((*temp).x != -1){
            p = Searchlistdp(*snake, (*temp).x, (*temp).y);

            while(p != Nilldp){
                Infoldp(p) = wordToString(intToWord(wordToInt(stringToWord(Infoldp(p))) - 1));
                p = Nextldp(p);
            }
        }    
    }
}

int lengthsnake(List snake){
    int count = 0;
    while (Firstldp(snake) != Nilldp) {
        count++;
        Firstldp(snake) = Nextldp(Firstldp(snake));
    }
    return count;
}

void belok(char x, List *s, List * posPanas, List * obstacle, boolean * gagal, boolean * menang){
    addressldp p;
    addressldp temp;
    int i = 0;
    int tempx, tempy;

    p = Lastldp(*s);
    printf("\n");

    if((x) == 'w'){
        if(Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        // } else if ((Posisiy(Firstldp(*s)) == 0)) {
        //     printf("Anda menabrak dinding :<\n");
        //     *gagal = true;
        //     *menang = true;
        } else if(Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if (Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if (Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp) {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if (Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5 ) != Nilldp) {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else {
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisiy(Firstldp(*s)) != 0){
                Posisiy(Firstldp(*s)) -= 1;
                *gagal = false;
            } else {
                Posisiy(Firstldp(*s)) = Posisiy(Firstldp(*s)) - 1 + 5;
                *gagal = false;
            }    
        }
    }
    else if ((x) == 's') {
        if (Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        // else if ((Posisiy(Firstldp(*s)) == 4)) {
        //     printf("Anda menabrak dinding :<\n");
        //     *gagal = true;
        //     *menang = true;
        // }
        else if (Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if (Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if(Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if(Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*s), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {        
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisiy(Firstldp(*s)) != 4){    
                Posisiy(Firstldp(*s)) += 1;
                *gagal = false;
            } else {
                Posisiy(Firstldp(*s)) = (Posisiy(Firstldp(*s)) + 1) % 5;
                *gagal = false;
            }    
        }
    }
    else if ((x) == 'a') {
        if (Posisix(Firstldp(*s)) != 0 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)) -1 , Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisix(Firstldp(*s)) == 0 && Searchlistdp((*posPanas), (Posisix(Firstldp(*s)) -1) + 5 , Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        // else if ((Posisix(Firstldp(*s)) == 0)) {
        //     printf("Anda menabrak dinding :<\n");
        //     *gagal = true;
        //     *menang = true;
        // }
        else if (Posisix(Firstldp(*s)) != 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)) -1 , Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if (Posisix(Firstldp(*s)) == 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)) -1 + 5, Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if(Posisix(Firstldp(*s)) != 0 && Searchlistdp((*s), Posisix(Firstldp(*s))-1, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if(Posisix(Firstldp(*s)) == 0 && Searchlistdp((*s), Posisix(Firstldp(*s))-1 + 5, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisix(Firstldp(*s)) != 0){ 
                Posisix(Firstldp(*s)) -= 1;
                *gagal = false;
            } else {
                Posisix(Firstldp(*s)) = Posisix(Firstldp(*s)) - 1 + 5;
                *gagal = false;
            }
        }
    }
    else if ((x) == 'd') {
        if (Posisix(Firstldp(*s)) != 4 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)) + 1, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisix(Firstldp(*s)) == 4 && Searchlistdp((*posPanas), (Posisix(Firstldp(*s)) + 1) % 5, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        // else if ((Posisix(Firstldp(*s)) == 4)) {
        //     printf("Anda menabrak dinding :<\n");
        //     *gagal = true;
        //     *menang = true;
        // }
        else if (Posisix(Firstldp(*s)) != 4 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)) + 1, Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        }else if (Posisix(Firstldp(*s)) == 4 && Searchlistdp((*obstacle), (Posisix(Firstldp(*s)) + 1) %5, Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obstacle :<\n");
            *gagal = true;
            *menang = true;
        } else if(Posisix(Firstldp(*s)) != 4 && Searchlistdp((*s), Posisix(Firstldp(*s))+1, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if(Posisix(Firstldp(*s)) == 4 && Searchlistdp((*s), (Posisix(Firstldp(*s))+1)%5, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisix(Firstldp(*s)) != 4){    
                Posisix(Firstldp(*s)) += 1;
                *gagal = false;
            } else {
                Posisix(Firstldp(*s)) = (Posisix(Firstldp(*s)) + 1) %5;
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

    CreateEmptylistdp(&food);
    CreateEmptylistdp(&snake);
    CreateEmptylistdp(&meteor);
    CreateEmptylistdp(&posPanas);
    CreateEmptylistdp(&obstacle);
    initsnake(&snake);

    printf("\n                 Selamat datang di snake on meteor!\n");
    printf(" .+:*+.+:*+.+:*+. P A N D U A N  S I N G K A T  G A M E .+*:+.+*:+.+*:+. \n");
    printf("o   : makanan yang harus dicapai agar snake bertambah panjang\n");
    printf("H   : Head dari snake yang akan diikuti oleh badannya (1, 2, dst.)\n");
    printf("M   : meteor yang akan muncul secara acak dan menyerang snake\n");
    printf("### : obstacle yang harus dihindari, apabila menabraknya snake akan mati\n\n");

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
                        elmntype tempInfoldp;
                        int tempx, tempy;

                        if(!IsEmptylistdp(meteor) && !gagal){
                            DelVLastlistdp(&meteor, &tempInfoldp, &tempx, &tempy);
                        }
                        if((Posisix(Firstldp(food)) == Posisix(Firstldp(snake))) && (Posisiy(Firstldp(food)) == Posisiy(Firstldp(snake))) && !gagal) {
                            makan(&snake, &food, &obstacle, &menang);
                            donef = false;
                           
                        }
                        if(!donef){ // dropfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
                            dropfood(&snake, &food, &posPanas, &obstacle);
                            
                            donef = true;
                        }
                        
                        dropmeteor(&food, &obstacle, &meteor);
                        
                        if(Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor))) != Nilldp){
                            //kondisional search posisinya meteor sama kaya posisinya snakenya apa engga
                            if(Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor))) == Firstldp(snake)){
                                elmntype temphead;
                                int headx;
                                int heady;
                                DelVFirstlistdp(&snake, &temphead, &headx, &heady);
                                menang = true;
                                kenakepala = true;
                                printpetak(snake, food, meteor, obstacle);
                                printf("Kepala snake terkena meteor :<\n");
                            } else {
                                elmntype tempbadan;
                                location postemp;
                                addressldp p;

                                postemp.x = -1;
                                postemp.y = -1;
                                p = Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                                if(Nextldp(p) != Nilldp){
                                    postemp = Posisi(Nextldp(p));
                                }
                                DelPlistdp(&snake, tempbadan, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                                printpetak(snake, food, meteor, obstacle);
                                hit(&snake, &meteor, &postemp);
                                printf("Anda terkena meteor\n");
                                printf("Berikut merupakan peta permainan sekarang:\n");
                                printpetak(snake, food, meteor, obstacle);
                                printf("Silahkan lanjutkan permainan\n");
                                
                                InsVLastlistdp(&posPanas, wordToString(intToWord(turn)), Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                            }
                        } else {
                
                            printpetak(snake, food, meteor, obstacle);
                            printf("Anda beruntung tidak terkena meteor! ");
                            printf("Silahkan lanjutkan permainan\n");
                        }    
                        
                        turn++;
                        if(!IsEmptylistdp(posPanas)){
                            if(wordToInt(stringToWord(Infoldp(Firstldp(posPanas)))) + 2 == turn ){
                                elmntype temppanas;
                                int px, py;
                                DelVFirstlistdp(&posPanas, &temppanas, &px, &py);
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
