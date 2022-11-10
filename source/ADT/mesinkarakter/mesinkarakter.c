#include<stdio.h>
#include<stdlib.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
boolean finish;

static FILE *pita;
static int retval;

void START() 
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
{
    pita = stdin ;
    advTerminal() ;
}

void ADV() 
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() 
/* Mengirimkan currentChar */
{
    return currentChar ;
}

boolean IsEOP() 
/* Mengirimkan true jika currentChar = MARK */
{
    return (currentChar == MARK) ;
}

void startFromFile(char *str)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari sebuah file yang berasal dari parameter input berupa string nama file.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) 
          finish bernilai salah karena belum mencapai akhir dari file */
{
       finish = false;
       pita = fopen(str, "r");
    
       advFile();
}

void advTerminal()
/* I.S. : Karakter pada jendela = currentChar, currentChar != ENTER
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = ENTER
          Jika  currentChar = ENTER maka EOP akan menyala (true) */
{
       retval = fscanf(pita,"%c", &currentChar);
       EOP = (currentChar == ENTER);
}

void advFile()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          proses akan berenti bila sudah mencapai kondisi EOF atau End Of File yang akan
          menyala ketika sudah terjadi error atau tidak bisa melakukan pembacaan kembali
          finish bernilai TRUE yang bemakna file sudah selesai dibaca */ 
{
    retval = fscanf(pita,"%c", &currentChar);
    if(retval == EOF) {
        fclose(pita);
        finish = true;
    }
}