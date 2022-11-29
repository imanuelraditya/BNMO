#include <stdio.h>
#include "console.h"

void wordList(ArrayDin* listOfWord);
/*
    * I.S. : listOfWord sembarang
    * F.S. : listOfWord terisi dengan daftar kata yang ada di file
*/

Word chooseWord(ArrayDin listOfWord);
/*
    * I.S. : listOfWord terisi dengan daftar kata
    * F.S. : mengembalikan kata yang dipilih secara random dari listOfWord
*/

boolean isAlreadyGuessed(ArrayDin listOfGuess, Word guess);
/*
    * I.S. : listOfGuess terisi dengan daftar huruf yang sudah di-guess
    * F.S. : mengembalikan true jika guess sudah ada di listOfGuess
*/

void printGuess(ArrayDin listOfGuess);
/*
    * I.S. : listOfGuess terisi dengan daftar huruf yang sudah di-guess
    * F.S. : menampilkan daftar huruf yang sudah di-guess
*/

boolean win(Word word, ArrayDin listOfGuess);
/*
    * I.S. : word terisi dengan kata yang akan di-guess
    *        listOfGuess terisi dengan daftar huruf yang sudah di-guess
    * F.S. : mengembalikan true jika semua huruf pada word sudah ada di listOfGuess
*/

void addDictionary(ArrayDin* listOfWord);
/*
    * I.S. : listOfWord terisi dengan daftar kata
    * F.S. : listOfWord terisi dengan daftar kata yang sudah ditambahkan
*/

void hangman(int* totalscore);
/*
    * I.S. : sembarang
    * F.S. : permainan hangman dimulai
*/