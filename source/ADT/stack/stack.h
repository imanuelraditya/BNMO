# ifndef stackdin_H
# define stacktdin_H

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef Word InfoType;
typedef struct tElmStack *Address;

typedef struct tElmStack {
    InfoType Info;
    Address Next;
} ElmStack;

typedef struct {
    Address Top;
    int Count;
} Stack;

#define Info(P) (*P).Info
#define Next(P) (*P).Next
#define Top(S) (S).Top
#define Max(S) (S).Max
#define Count(S) (S).Count
#define Nil NULL

void CreateStack(Stack *S);
/*  
I.S. Sembarang
F.S. Terbentuk Stack kosong
*/

boolean IsStackEmpty(Stack S);
/*  
Menghasilkan True jika Stack kosong, dan False jika Stack tidak kosong
*/

Address Allocate(InfoType X);
/*
Menghasilkan Address dari alokasi sebuah elemen dengan InfoType X
Jika alokasi berhasil maka nilai Address tidak Nil dan jika gagal nilai Address Nil
*/

void DeAllocate(Address P);
/*
I.S. P terdefinisi
F.S. Memori yang digunakan oleh P dikembalikan ke sistem
*/

void Push(Stack *S, Address P);
/*
I.S. Sembarang, P terdefinisi
F.S. Menempatkan P pada Top dari S
*/

void Pop(Stack *S, Address *P);
/*
I.S. Stack tidak kosong
F.S. Mengambil P dari Top dari S
*/

void ViewStack(Stack S);
/*
I.S. Sembarang
F.S. Menampilkan semua Info dari masing-masing elemen dari Stack
*/

# endif