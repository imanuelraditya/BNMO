#include<stdio.h>
#include<stdlib.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START() {
    pita = stdin ;
    ADV() ;
}

void ADV() {
    retval = fscanf(pita,"%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    return currentChar ;
}

boolean IsEOP() {
    return (currentChar == MARK) ;
}

void startFromFile(char *str){
       // fclose (tipe) ;
       pita = fopen(str, "r");
       if(pita == NULL){
              printf("File tidak ditemukan. Exiting....\n");
              exit(0);
       }
       ADV();
}