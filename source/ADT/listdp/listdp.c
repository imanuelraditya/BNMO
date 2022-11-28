# include <stdio.h>
# include <stdlib.h>
# include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylistdp (List L) 
{
    return ((First(L)==Nil)&&(Last(L)==Nil));
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptylistdp (List *L) 
{
    First(*L)=Nil;
    Last(*L)=Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasilistdp (elmntype X, int a, int b) 
{
    ElmtListdp *P=(ElmtListdp*)malloc(sizeof(ElmtListdp));
    if(P!=Nil){
        Info(P)=X;
        Posisix(P) = a;
        Posisiy(P) = b;
        Prev(P)=Nil;
        Next(P)=Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasilistdp (address P) 
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Searchlistdp (List L, int a, int b) 
{
    address P;
    boolean found = false;
	P = First(L);
	if (IsEmptylistdp(L)){
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
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstlistdp (List *L, elmntype X, int a, int b) 
{
    address P=Alokasilistdp(X, a, b);
    if(P!=Nil){
        InsertFirstlistdp(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastlistdp (List *L, elmntype X, int a, int b) 
{
    address P=Alokasilistdp(X, a, b);
    if(P!=Nil){
        InsertLastlistdp(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstlistdp (List *L, elmntype *X, int * a, int * b) 
{
    address P;
    DelFirstlistdp(L,&P);
    *X=Info(P);
    *a = Posisix(P);
    *b = Posisiy(P);
    Dealokasilistdp(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastlistdp (List *L, elmntype *X,  int * a, int * b) 
{
    address P;
    DelLastlistdp(L,&P);
    *X=Info(P);
    *a = Posisix(P);
    *b = Posisiy(P);
    Dealokasilistdp(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstlistdp (List *L, address P) 
{
    if(IsEmptylistdp(*L)){
        First(*L)=P;
        Last(*L)=P;
    }
    else{
        InsertBeforelistdp(L,P,First(*L));
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLastlistdp (List *L, address P) 
{
    if(IsEmptylistdp(*L)){
        InsertFirstlistdp(L,P);
    }
    else {
        InsertAfterlistdp(L,P,Last(*L));
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterlistdp (List *L, address P, address Prec) 
{
    Prev(P)=Prec;
    Next(P)=Next(Prec);
    Next(Prec)=P;
    if(Next(P)==Nil){
        Last(*L)=P;
    }
    else{
        Prev(Next(P))=P;
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforelistdp (List *L, address P, address Succ) 
{
    Prev(P)=Prev(Succ);
    Next(P)=Succ;
    Prev(Succ)=P;
    if(Prev(P)==Nil){
        First(*L)=P;
    }
    else{
        Next(Prev(P))=P;
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstlistdp (List *L, address *P) 
{
    *P=First(*L);
    if(First(*L)==Last(*L)){
        First(*L)=Nil;
        Last(*L)=Nil;
    }
    else{
        First(*L)=Next(First(*L));
        Prev(First(*L))=Nil;
    }
    Next(*P)=Nil;
    Prev(*P)=Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastlistdp (List *L, address *P) 
{
    *P=Last(*L);
    if(First(*L)==Last(*L)){
        First(*L)=Nil;
        Last(*L)=Nil;
    }
    else{
        Last(*L)=Prev(Last(*L));
        Next(Last(*L))=Nil;
    }
    Next(*P)=Nil;
    Prev(*P)=Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPlistdp (List *L, elmntype X, int a, int b) 
{
    address cari=Searchlistdp(*L, a, b);
    if(cari!=Nil){
        address P=First(*L),prec=Nil;
        while (P!=cari){
            prec=P;
            P=Next(P);
        }
        if(prec==Nil){
            DelFirstlistdp(L,&cari);
        }
        else{
            DelAfterlistdp(L,&cari,prec);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfterlistdp (List *L, address *Pdel, address Prec) 
{
    *Pdel=Next(Prec);
    if(Next(*Pdel)==Nil){
        Next(Prec)=Nil;
        Last(*L)=Prec;
    }
    else{
        Next(Prec)=Next(*Pdel);
        Prev(Next(*Pdel))=Prec;
    }
    Prev(*Pdel)=Nil;
    Next(*Pdel)=Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforelistdp (List *L, address *Pdel, address Succ) 
{
    *Pdel=Prev(Succ);
    if(Prev(*Pdel)==Nil){
        Prev(Succ)=Nil;
        First(*L)=Succ;
    }
    else{
        Prev(Succ)=Prev(*Pdel);
        Next(Prev(*Pdel))=Succ;
    }
    Prev(*Pdel)=Nil;
    Next(*Pdel)=Nil;
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardlistdp (List L) 
{
    if (IsEmptylistdp(L)){
        printf("[]");
    }
    else{
        address P=First(L);
        printf("[");
        while(P!=Nil){
            if(P==Last(L)){
                printf("%d",Info(P));
            }
            else{
                printf("%d,",Info(P));
            }
            P=Next(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardlistdp (List L) 
{
    if (IsEmptylistdp(L)){
        printf("[]");
    }
    else{
        address P=Last(L);
        printf("[");
        while(P!=Nil){
            if(P==First(L)){
                printf("%d",Info(P));
            }
            else{
                printf("%d,",Info(P));
            }
            P=Prev(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */