#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../boolean.h"
#include "../ADT/array/arraydin.h"
#include "../ADT/map/map.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/queue/queue.h"
#include "../ADT/queuedinerdash/queue.h"
#include "../ADT/stack/stack.h"

#ifndef CONSOLE_H
#define CONSOLE_H

// LIST HEADER COMMAND

void CreateGame (ArrayDin* listGame);
/* I.S. listGame sembarang */
/* F.S. listGame bertambah dengan nama game yang diinput */

void deleteGame (ArrayDin* listGame, Queue Q);
/* I.S. listGame terdefinisi */
/* F.S. listGame berkurang dengan nama game yang diinput */

void help();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void invalidCommand(Word* w);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa pesan bahwa command yang dimasukkan tidak valid */

void ListGame (ArrayDin array);
/* I.S. array terdefinisi */
/* F.S. mengembalikan output berupa daftar game yang ada dalam array */

void load (Word filename, ArrayDin* arrayGame, ArrayDin* arrayHistory, Map* Map_RNG, Map* Map_DinerDash, Map* Map_TowerOfHanoi, Map* Map_Hangman, Map* Map_SnakeOnMeteor, boolean* esc);
/* I.S. array kosong */
/* F.S. array terisi dengan list nama game yang ada dalam file eksternal yang disimpan */

void loadSuceeded();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa pesan bahwa load berhasil */

void loadFailed();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa pesan bahwa load gagal */

void randomScore(Word game);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa score yang dihasilkan secara random */

void playGame (Queue* queueGame, ArrayDin* arrayHistory, Map* Map_RNG, Map* Map_DinerDash, Map* Map_TowerOfHanoi, Map* Map_Hangman, Map* Map_SnakeOnMeteor);
/* I.S. queueGame terdefinisi, arrayHistory mungkin kosong atau sudah terdefinisi */
/* F.S. game yang berada pada head akan dimainkan dan queueGame berkurang */

void queueGame(ArrayDin listGame, Queue* Q);
/* I.S. listGame terdefinisi */
/* F.S. queueGame terisi dengan nama game yang dipilih dari listGame */

void Quit();
/* I.S. sembarang */
/* F.S. keluar dari program utama */

void save (Word filename, ArrayDin* array, ArrayDin* arrayHistory, Map* Map_RNG, Map* Map_DinerDash, Map* Map_TowerOfHanoi, Map* Map_Hangman, Map* Map_SnakeOnMeteor);
/* I.S. array terdefinisi */
/* F.S. array disimpan dalam file eksternal */

void skipGame(Queue * Q, ArrayDin* arrayHistory, Map* Map_RNG, Map* Map_DinerDash, Map* Map_TowerOfHanoi, Map* Map_Hangman, Map* Map_SnakeOnMeteor, int n);
/* I.S. Q terdefinisi */
/* F.S. Q berkurang sebanyak n */

void startGame(ArrayDin * arr);
/* I.S. arr kosong */
/* F.S. arr terisi dengan list nama game yang ada pada file config */

void loading();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa animasi loading */

void welcome();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa welcoming page BNMO */

void listHistory(ArrayDin array, int n);
/* I.S. array terdefinisi */
/* F.S. mengembalikan output berupa daftar game yang ada dalam array history */

void resetHistory(ArrayDin * arrayHistory);
/* I.S. arrayHistory terdefinisi */
/* F.S. arrayHistory kosong */

void displayScoreboard(Map M);
/* I.S. M terdefinisi */
/* F.S. mengembalikan output berupa scoreboard */

// LIST HEADER GAME

/* DINER DASH */

void displayOrder(QueueInt Q);
/* I.S. Q terdefinisi */
/* F.S. mengembalikan output berupa daftar pesanan yang ada pada Q */

void displayCook(Map C);
/* I.S. C terdefinisi */
/* F.S. mengembalikan output berupa daftar makanan yang sedang dimasak pada C */

void displayServe(Map C);
/* I.S. C terdefinisi */
/* F.S. mengembalikan output berupa daftar makanan yang sudah dimasak pada C */

int randomNumber(int max, int min);
/* I.S. max dan min terdefinisi */
/* F.S. mengembalikan output berupa angka random dari min sampai max */

int idxToInt(char *idx);
/* I.S. idx terdefinisi */
/* F.S. mengembalikan output berupa indeks dari makanan yang dipilih */

void sortMapAsc(Map *Map);
/* I.S. Map terdefinisi */
/* F.S. Map terurut berdasarkan indeks */

void sortMapDesc(Map *Map);
/* I.S. Map terdefinisi */
/* F.S. Map terurut berdasarkan indeks */

void dinerdash(Map *M);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa game Diner Dash */

/* RNG */

int randomx();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa angka random dari 1 sampai 500 */

void rng(Map* M);
/* I.S. sembarang */
/* F.S. mengembalikan output berupa game RNG */

// BONUS

// TOWER OF HANOI

void PrintTower(Stack S[3], int n);
/*
I.S. Sembarang
F.S. Menampilkan semua Info dari masing-masing elemen dari Stack
*/

void towerOfHanoi(Map* M);

#endif