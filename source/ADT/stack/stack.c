# include "stack.h"

void CreateStack(Stack *S)
{
/*  
I.S. Sembarang
F.S. Terbentuk Stack kosong
*/
    Top(*S) = Nil;
    Count(*S) = 0;
}

boolean IsEmpty(Stack S)
{
/*  
Menghasilkan True jika Stack kosong, dan False jika Stack tidak kosong
*/
    return Top(S) == Nil;
}

Address Allocate(InfoType X)
{
/*
Menghasilkan Address dari alokasi sebuah elemen dengan InfoType X
Jika alokasi berhasil maka nilai Address tidak Nil dan jika gagal nilai Address Nil
*/
    Address P = (Address)malloc(sizeof(ElmStack));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DeAllocate(Address P)
{
/*
I.S. P terdefinisi
F.S. Memori yang digunakan oleh P dikembalikan ke sistem
*/
    free(P);
}

void Push(Stack *S, Address P)
{
/*
I.S. Sembarang, P terdefinisi
F.S. Menempatkan P pada Top dari S
*/
    Next(P) = Top(*S);
    Top(*S) = P;
    Count(*S)++;
}

void Pop(Stack *S, Address *P)
{
/*
I.S. Stack tidak kosong
F.S. Mengambil P dari Top dari S
*/
    *P = Top(*S);
    Top(*S) = Next(*P);
    Count(*S)--;
}

void ViewStack(Stack S)
{
/*
I.S. Sembarang
F.S. Menampilkan semua Info dari masing-masing elemen dari Stack
*/
    Address P;
    InfoType X[Count(S)];
    int i = 0;
    for (P = Top(S); P != Nil; P = Next(P))
    {
        X[i] = Info(P);
        i++;
    }
    for (i = Count(S) - 1; i >= 0; i--)
        printf("%d ", X[i]);
}