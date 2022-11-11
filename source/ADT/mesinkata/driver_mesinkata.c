// driver untuk ADT Mesin Kata

#include <stdio.h>
#include "mesinkata.h"

int main()
{
    Word temp1 = {"tes", 3};
    Word temp2 = {"concat", 6};
    Word tempconcat;
    tempconcat = (concatWord(temp1, temp2));
    printf("%s\n", wordToString(tempconcat));
    printf("panjang kata dari hasil concat : %d\n", stringLength(wordToString(tempconcat)));

    Word tubes = {"tubes", 5};
    printf("\ndi bawah ini hasil tes displayWord\n");
    displayWord(tubes);

    Word angka = {"1234", 4};
    int tempangka = 0;
    tempangka = 2 * wordToInt(angka);
    printf("\n2 kali nilai word angka <%s> adalah %d\n", wordToString(angka), tempangka);

    printf("\n======== tes mesin kata original ===========\n");
    printf("menghitung kemunculan kata tubes pada masukan pengguna\n");
    printf("masukkan kalimat: ");
    STARTWORD();
    
    int jumlah = 0;
    while(!EndWord){
        if(isWordEqual(tubes, currentWord)){
            jumlah += 1;
        }
        ADVWORD();
        IgnoreBlanks();
    }
    printf("jumlah kata tubes pada kalimat : %d\n", jumlah);

    printf("\n======= tes mesin kata dari file =========\n");
    startWFile("data/drivermesinkata.txt");
    while(!finish) {
        printf("%s\n", wordToString(currentWord));
        advNewlineFile();
    }
    
    return(0);
}

// gcc source/ADT/mesinkarakter/mesinkarakter.c source/ADT/mesinkata/mesinkata.c source/ADT/mesinkata/driver_mesinkata.c -o yy
