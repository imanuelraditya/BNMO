#include <stdio.h>
#include "mesinkata.h"

boolean EndWord ;
Word currentWord ;

void IgnoreBlanks() 
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK || currentChar == ENTER) {
        ADV() ;
    }
}

void IgnoreDots() {
    while (currentChar == ' ' && currentChar == '.') {
        //advFromFile(); ini gaada fungsinya -rr
    }
}

void startWFile(char * file) //trialnya rr
/* */
{
    finish = false;
    startFromFile(file);
    copywFile();
}

void copywFile() //trialnya rr
/* */
{
    int i = 0;
    while(currentChar != ENTER && !finish) {
        if(i < NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;
            advFile();
        }
    }
    if(i > NMax) {
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
}

void igBlankFile() //trialnya rr
/* */
{
    while(currentChar == BLANK) {
        advFile();
    }
}

void advNewlineFile() //trialnya rr
{
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == ENTER){
        EndWord = false;
        advFile();
        copywFile();
    }
}

void STARTWORD(char* file)
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    startFromFile(file);
    IgnoreBlanks() ;
    if (currentChar == MARK) {
            EndWord = true;
    } 
    else {
        EndWord = false;
        ADVWORD() ;
    }
}

void ADVWORD() 
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

{
    IgnoreBlanks () ;
    if (currentChar == MARK && !EndWord) {
        EndWord = true ;
    }
    else {
        CopyWord() ;
        IgnoreBlanks();
    }
}

void CopyWord() 
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i; 
    i = 0; 
    while ((currentChar != MARK) && (currentChar != BLANK) && (currentChar != ENTER)) {
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
        CopyWord();
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

void STARTCOMMAND () {
    START();
    IgnoreBlanks();
    if (currentChar == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND();
    }
}

void ADVCOMMAND () {
    IgnoreDots();
    if (currentChar == ENTER && !EndWord) {
        EndWord = true;
    } else {
        CopyCommand();
        IgnoreBlanks();
    }
}

void CopyCommand () {
    int i;
    i = 0;
    while ((currentChar != ENTER) && (currentChar != BLANK)) {
        if (i < NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        //advFromFile(); // ini gaada fungsinya -rr
    }
    currentWord.Length = i;
}

int stringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

Word stringToWord(char *str)
{
    Word word;
    word.Length = stringLength(str);
    for (int i = 0; i < word.Length; i++)
    {
        word.TabWord[i] = str[i];
    }
    return word;
}