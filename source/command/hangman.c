#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

char* pilihTebakan(ArrayDin* daftarTebakan)
{
    startWFile("data/DaftarKataHangman.txt");
    jumlahKata = wordToInt(currentWord);
    
    for (i = 0 ; i < jumlahKata ; i++)
    {
        advNewlineFile();
        InsertLast(daftarTebakan, currentWord);
    }

    num = randomnumber(jumlahKata-1,0);
    return(Get(daftarTebakan, num));
}

void daftarTebak(Queue allTebak)
{
    int i;
	for (i = Head(allTebak); i <= Tail(allTebak); i = (i + 1) % QMaxEl(allTebak))
    {
		printf("%s", wordToString(allTebak.T[i]));
	}
}

boolean pengulangan(Queue allTebak, char input)
{
    char* temp;
    boolean found = false;
    while (!IsQEmpty(allTebak))
    {
        if (HEAD(allTebak)=input)
        {
            found = true;
        }
        dequeue(&allTebak, &temp);
    }
}

void Hangman()
{
    Queue allTebak;
    ArrayDin* daftarTebakan;
    int i, panjangDitebak, panjangBenar, kesempatan, poin;
    char hurufTebakan[panjangDitebak];
    char pemain, tebakanL;
    char* kataDitebak;
    char* tebakan;
    boolean valid = false;
    
    QCreateEmpty(&allTebak, 26);
    (*daftarTebakan) = MakeArrayDin();
    kataDitebak = pilihTebakan(daftarTebakan);
    panjangDitebak = Length(kataDitebak);
    
    kesempatan = 10;
    poin = 0;
    panjangBenar = 0;
    
    printf("Tebakan sebelumnya: -\n");
    printf("Kata: ");
    for(i=0; i<panjangDitebak; i++)
    {
        printf("_");
    }
    printf("\n");
    printf("Kesempatan: 10");
    printf("Masukkan tebakan (huruf kapital): ");
    STARTCOMMAND();

    do
    {
        if (tebakan[i] < 'A' || tebakan[i] > 'Z')
        {
            printf("Harap memasukkan input berupa 1 huruf kapital.");
            printf("Masukkan tebakan (huruf kapital): ");
            STARTCOMMAND();
        }
        else
        {
            valid == true;
        }

        if (valid == true)
        {
            while (panjangBenar<panjangDitebak && kesempatan!=0)
            {
                tebakan = wordToString(currentCommand);
                tebakanL = tebakan[0]-32;

                if (pengulangan(allTebak, tebakanL))
                {
                    printf("Huruf sudah pernah ditebak. Tebaklah huruf lain!");
                    break;
                }
                else
                {
                    kesempatan--;
                    for(i=0, i<panjangDitebak, i++)
                    {
                        if(kataDitebak[i]==tebakan)
                        {
                            for(i=0; i<panjangDitebak; i++)
                            {
                                if (kataDitebak[i]==tebakan)
                                {
                                    hurufTebakan[i]==tebakan;
                                    panjangBenar++;
                                }
                            }
                            if (!pengulangan(allTebak, tebakanL))
                            {
                                Add(allTebak, tebakanL);
                            }
                        }
                    }
                }
            }
            
            printf("Tebakan sebelumnya: ");
            daftarTebak(allTebak);
            printf("\n");

            printf("Kata: ");
            for(i=HEAD(allTebak); i<QMaxEl(allTebak); i++)
            {
                if(IsWordEqual(allTebak.T[i], Get(*kataDitebak, i)))
                {
                    printf("%c", kataDitebak[i];)
                }
                else
                {
                    printf("_");
                }
            }
            printf("\n");

            printf("Kesempatan: %d\n", kesempatan);
            printf("Masukkan tebakan (huruf kapital): ");
            STARTCOMMAND();
            }
        }
    } (while kesempatan != 0);

    if (kesempatan==0 && panjangBenar==panjangDitebak)
    {
        printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin.\n", kataDitebak, panjangDitebak);
        poin = panjangDitebak;
    }
    else
    {
        printf("Gagal menebak huruf %s! Kamu mendapatkan %d poin.\n", kataDitebak, panjangBenar);
        poin = panjangBenar;
    }
    QDeAlokasi(allTebak);

    printf("\n");
    printf("Masukkan nama pemain: ");
    STARTCOMMAND();
    pemain = wordToString(currentCommand);
    printf("\n");
}

