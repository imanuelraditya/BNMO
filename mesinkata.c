#include <stdio.h>
#include "mesinkata.h"

boolean EndWord ;
Word currentWord ;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV() ;
    }
}

void STARTWORD() {
    START() ;
    IgnoreBlanks() ;
    if (currentChar == MARK) {
            EndWord = true;
    } 
    else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks () ;
    if (currentChar == MARK) {
        EndWord = true ;
    }
    else {
        CopyWord() ;
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i; 
    i = 0; 
    while ((currentChar != MARK) && (currentChar != BLANK)) {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar ;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}

void advNewline()
{
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == MARK){
        EndWord = false;
        ADV();
        copyWord();
    }
}

Word concatWord(Word w1, Word w2)
{
    Word ans;
    ans.Length = w1.Length + w2.Length;
    int i;
    for(i = 0; i < w1.Length; i++){
        ans.TabWord[i] = w1.TabWord[i];
    }
    for(i = 0; i < w2.Length;i++){
        ans.TabWord[i+w1.Length] = w2.TabWord[i];
    }
    return ans;
}

boolean isWordEqual(Word a, Word b)
{
    if(a.Length != b.Length){
        return false;
    }
    else{
        int i = 0;
        boolean flag = true;
        while(i < a.Length && flag){
            if(a.TabWord[i] != b.TabWord[i]){
                flag = false;
            }
            i++;
        }
        return flag;
    }
}

void displayWord(Word w)
{
    int i;
    for(i = 0; i<w.Length;i++){
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

void copyWordFromWord(Word w1, Word *w2)
{
    w2->Length = w1.Length;
    for(int i = 0; i < w1.Length; i++){
        w2->TabWord[i] = w1.TabWord[i];
    }
}