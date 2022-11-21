/*
Nama    : Michael Sihotang
NIM     : 18221054
Pra Praktikum 09 Problem 01
*/

# include <stdio.h>
# include <stdlib.h>
# include "listliniersnake.h"
# include "../../boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L) {
    if (First(L) == Nil) {
        return true;
    }
    else {
        return false;
    }
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (elementtype X, int a, int b) {
    address P;
    P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P!= Nil) {
        Info(P) = X;
        Posisix(P) = a;
        Posisiy(P) = b;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P) {
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, int a, int b){
	address P;
    boolean found = false;
	P = First(L);
	if (IsEmptyList(L)){
		return Nil;
	}
	else{
		while (P != Nil && !found) {
			if(Posisix(P) == a && Posisiy(P) == b){
                found = true;
            } else {
                P = Next(P);
            }
		}
		if(found){
            return(P);
        } else{
            return(Nil);
        }
	}
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, elementtype X, int a, int b) {
    address P;

    P = Alokasi(X, a, b);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, elementtype X, int a, int b) {
    address P;

    P = Alokasi(X, a, b);
    if (P != Nil) {
        InsertLast(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, elementtype *X) {
    address P;

    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, elementtype *X) {
    address P;

    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P) {
    if (IsEmptyList(*L)){ // empty list
        Next(P) = Nil;
        First(*L) = P;
    }
    else{
        address last = First(*L);

        while(Next(last) != Nil) {
            last = Next(last);
        }

        InsertAfter(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, elementtype X) {
    int a = 0;
    int b = 0;
    address P = Search(*L, a, b); // INI NANTI DI KOREKSI

    if (P != Nil){   // Found
        address prec = First(*L);

        if (prec == P){ // If its on first element
            DelFirst(L, &P);
        }
        else {

            while(Next(prec) != P) { // search for the predecesor
                prec = Next(prec);
            }

            DelAfter(L, &P, prec);
        }
    }
    Dealokasi(&P);
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P) {
    if (Next(First(*L)) == Nil){    // 1 element only

        *P = First(*L);
        CreateEmpty(L);

    }
    else {
        address prec = First(*L);

        while(Next(Next(prec)) != Nil) {
            prec = Next(prec);
        }

        // Next Next (prec ) == nil , got the prec of last element

        DelAfter(L, P, prec);

    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec) {
    address P;
    boolean found;

    P = First(*L);
    found = false;
    while ((P != Nil) && (!found)) {
        if (P == Prec) {
            found = true;
        }
        else {
            P = Next(P);
        }
    }

    *Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
    printf("[");
    if (!IsEmptyList(L)){

        address CP = First(L);

        do{

            printf("%d",Info(CP));
            CP = Next(CP);

            if (CP != Nil){ // last element no ','
                printf(",");
            }

        } while (CP != Nil);

    }

    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L) {
    int count;
    address P;

    count = 0;
    P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }

    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L) {
    address P, Prec, Last;

    P = First((*L));
    Prec = Nil;

    while (P != Nil) {
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    First(*L) = Last;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3) {
    CreateEmpty(L3);

    if (!(IsEmptyList(*L1))){
        First(*L3) = First(*L1);

        address last1 = First(*L1);

        while(Next(last1) != Nil) {
            last1 = Next(last1);
        }

        Next(last1) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }


    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */