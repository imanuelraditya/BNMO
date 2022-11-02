#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"rng.h"

/*Mengambil angka random untuk ditebak di rentang 1 sampai 500*/
int randomx()
{
    int a;
    srand(time(NULL));
    a = rand() % (500 + 1 - 1) + 1;
    return a;
}

void rng(){
    int tebakan, x, i;
    i = 0;
    x = randomx();

    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak angka X.\n");
    printf("Tebakan: ");
    scanf("%d", &tebakan);

    do 
    {
        ++i; /*Memberikan 8 kesempatan menebak*/
        if (tebakan==x)
        {
            printf("Ya, X adalah %d\n", x);
            break;
        }
        else if (tebakan>x)
        {
            printf("Lebih kecil\n");
            printf("Tebakan: ");
            scanf("%d", &tebakan);
        }
        else
        {
            printf("Lebih besar\n");
            printf("Tebakan: ");
            scanf("%d", &tebakan);
        }
    } while(i!=7);

    if (i==7)
    {
        printf("Kesempatan Anda habis. X yang tepat adalah %d\n", x);
    }
}