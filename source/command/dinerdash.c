#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

void displayOrder(QueueInt Q)
{
    int i = IDX_HEAD(Q);
    printf("Daftar Pesanan\n");
    printf("Makanan\t| Durasi memasak |  Ketahanan\t|  Harga\n");
    printf("--------------------------------------------------\n");
    for(i; i <= IDX_TAIL(Q); i++){
        printf("M%d\t|\t%d\t |\t%d\t|  %d\n", i, Q.buffer[i].cookTime, Q.buffer[i].expTime, Q.buffer[i].price);
    }
    printf("\n");
}

void displayCook(Map C)
{
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("---------------------------------\n");
    if(C.Count > 0)
    {
        int i = 0;
        for(i; i <= C.Count - 1; i++)
        {
            printf("M%d\t|\t%d\n", C.Elements[i].Key, C.Elements[i].Value);
        }
    }
    else
    {
        printf("\t|\n\n");
    }
    printf("\n");
}

void displayServe(Map C)
{
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan\t| Sisa ketahanan makanan\n");
    printf("---------------------------------\n");
    if(C.Count > 0)
    {
        int i = 0;
        for(i; i <= C.Count - 1; i++)
        {
            printf("M%d\t|\t%d\n", C.Elements[i].Key, C.Elements[i].Value);
        }
    }
    else
    {
        printf("\t|\n\n");
    }
    printf("\n");
}

int randomNumber(int max, int min){
    return ( (rand() % max) + min);
}

int idxToInt(char *idx){
    int i = 0;
    int index = 0;

    for(i; i < 2;i++){
        if( (idx[i+1]-'0') >= 0 && (idx[i+1]-'0') <=99){
            index = index*10 + (idx[i+1] - '0');
        }
    }
    return index;
}

void sortMap(Map *Map){
    // Algoritma Bubble Sort
    int i = 1;
    int j = 0;
    int count = Map->Count;
    for(i; i <= count - 1; i++)
    {
        for(j; j <= count - 2; j++)
        {
            if(Map->Elements[j].Value > Map->Elements[j+1].Value)
            {
                info temp = Map->Elements[j];
                Map->Elements[j] = Map->Elements[j+1];
                Map->Elements[j+1] = temp;
            }
        }
    }
}

void dinerdash(){
    // Deklarasi ADT
    QueueInt Order;
    Map Cook;
    Map Serve;

    // Inisialisasi ADT
    CreateQueueInt(&Order);
    CreateMapEmpty(&Cook);
    CreateMapEmpty(&Serve);

    // Inisialisasi Variabel
    int serveCount = 0;
    int saldo = 0;

    // Inisialiasi 3 order awal
    int firstOrder = 0;
    for(firstOrder; firstOrder < 3; firstOrder++){
        ElTypeInt ord;
        ord.cookTime = randomNumber(5,1);
        ord.expTime = randomNumber(5,1);
        ord.price = randomNumber(50000,10000);
        enqueue(&Order, ord);
    }

// Program Utama
    printf("Selamat Datang di Diner Dash!");
    
    // Looping Untuk Keberjalanan Game
    while (QueueIntLength(Order) <= 7 && serveCount < 15)
    {

        // Display
        printf("\n\nSALDO: %d\n\n", saldo);
        displayOrder(Order);
        displayCook(Cook);
        displayServe(Serve);

        // Inisialisasi variabel untuk input command
        char command[6];
        char index[4];
        boolean valid = false;
        int countValid = 0;

        // Command dan validasi kebenaran inputnya
        while(!valid){
            if(countValid > 0)
            {
                while (!EndWord)
                {
                    ADVCOMMAND();
                }
                printf("INPUT SALAH!\n");
            }
            printf("MASUKKAN COMMAND: ");
            // scanf("%s %s", &command, &index);
            STARTCOMMAND();

            for (int i = 0; i < currentCommand.Length; i++)
            {
                command[i] = currentCommand.TabWord[i];
            }

            ADVCOMMAND();

            for (int i = 0; i < currentCommand.Length; i++)
            {
                index[i] = currentCommand.TabWord[i];
            }

            if(command[0] == 'C' && command[1] == 'O' && command[2] == 'O' && command[3] == 'K')
            {
                if(index[0] == 'M' && idxToInt(index) < QueueIntLength(Order))
                {
                    valid = true;
                }
            }
            if(command[0] == 'S' && command[1] == 'E' && command[2] == 'R' && command[3] == 'V' && command[4] == 'E')
            {
                if(index[0] == 'M' && IsMemberMap(Serve, idxToInt(index)))
                {
                    valid = true;
                }
            }
            countValid++;
        }

        // Proses Masak
        if(Cook.Count >0){
            sortMap(&Cook);
            int i = 0;
            for(i; i < Cook.Count; i++)
            {
                if(Cook.Elements[i].Value > 0)
                {
                    Cook.Elements[i].Value--;
                }
            }
            while(Cook.Elements[0].Value == 0 && Cook.Count > 0)
            {
                keytype k = Cook.Elements[0].Key;
                valuetype v = Order.buffer[k].expTime + 1;
                Insert(&Serve, k, v);
                Delete(&Cook, k);
                printf("\nMakanan M%d telah selesai dimasak\n", k);
            }

        }

        // Proses Serve
        if(Serve.Count > 0)
        {
            int i = 0;
            for(i; i < Serve.Count; i++)
            {
                if(Serve.Elements[i].Value > 0)
                {
                    Serve.Elements[i].Value--;
                }
            }
            while(Serve.Elements[0].Value == 0 && Serve.Count > 0)
            {
                keytype k = Serve.Elements[0].Key;
                Delete(&Serve, k);
                printf("\nMakanan M%d telah expired\n", k);
            }
        }

        // Jika Command = COOK
        if(command[0] == 'C' && command[1] == 'O' && command[2] == 'O' && command[3] == 'K')
        {
            // Insert Order to Cook
            int idx = idxToInt(index);
            Insert(&Cook, idx, Order.buffer[idx].cookTime);
            printf("\nBerhasil memasak M%d\n", idx);
        }

        // Jika Command = SERVE
        if(command[0] == 'S' && command[1] == 'E' && command[2] == 'R' && command[3] == 'V' && command[4] == 'E')
        {
            int idx = idxToInt(index);
            if(idx == IDX_HEAD(Order))
            {
                // Mencari makanan di serve dengan ID = idx
                int i = 0;
                ElTypeInt el;
                boolean found = false;
                while(!found)
                {
                    if(idx == Serve.Elements[i].Key)
                    {
                        Delete(&Serve, Serve.Elements[i].Key);
                        dequeue(&Order, &el);
                        saldo += el.price;
                        serveCount += 1;
                        found = true;
                    }
                    i++;
                }
            }
            else
            {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", idx, IDX_HEAD(Order));
            }
        }

        // Order Baru
        ElTypeInt newOrder;
        newOrder.cookTime = randomNumber(5,1);
        newOrder.expTime = randomNumber(5,1);
        newOrder.price = randomNumber(50000,10000);
        enqueue(&Order, newOrder);

        printf("==========================================================");
    }

}