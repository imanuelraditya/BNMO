# include <stdio.h>
# include <stdlib.h>
# include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylistdp (List L) 
{
    return ((Firstldp(L)==Nilldp)&(Lastldp(L)==Nilldp));
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptylistdp (List *L) 
{
    Firstldp(*L)=Nilldp;
    Lastldp(*L)=Nilldp;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressldp Alokasilistdp (elmntype X, int a, int b) 
{
    ElmtListdp *P=(ElmtListdp*)malloc(sizeof(ElmtListdp));
    if(P!=Nilldp){
        Infoldp(P)=X;
        Posisix(P) = a;
        Posisiy(P) = b;
        Prevldp(P)=Nilldp;
        Nextldp(P)=Nilldp;
        return P;
    }
    else
    {
        return Nilldp;
    }
}
/* Mengirimkan addressldp hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressldp tidak nilldpNilldp. */
/* Misalnya: menghasilkan P, maka Infoldp(P)=X, Nextldp(P)=Nilldp, Prevldp(P)=Nilldp */
/* Jika alokasi gagal, mengirimkan Nilldp. */
void Dealokasilistdp (addressldp P) 
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressldp P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressldp Searchlistdp (List L, int a, int b) 
{
    addressldp P;
    boolean found = false;
	P = Firstldp(L);
	if (IsEmptylistdp(L)){
		return Nilldp;
	}
	else{
		while (P != Nilldp && !found) {
			if(Posisix(P) == a && Posisiy(P) == b){
                found = true;
            } else {
                P = Nextldp(P);
            }
		}
		if(found){
            return(P);
        } else{
            return(Nilldp);
        }
	}
}
/* Mencari apakah ada elemen list dengan Infoldp(P)=X */
/* Jika ada, mengirimkan addressldp elemen tersebut. */
/* Jika tidak ada, mengirimkan Nilldp */

/****************** PRIMITIF BERDASARKAN NILldpNilldpAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstlistdp (List *L, elmntype X, int a, int b) 
{
    addressldp P=Alokasilistdp(X, a, b);
    if(P!=Nilldp){
        InsertFirstlistdp(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilldpNilldpai X jika alokasi berhasil */
void InsVLastlistdp (List *L, elmntype X, int a, int b) 
{
    addressldp P=Alokasilistdp(X, a, b);
    if(P!=Nilldp){
        InsertLastlistdp(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilldpNilldpai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstlistdp (List *L, elmntype *X, int * a, int * b) 
{
    addressldp P;
    DelFirstlistdp(L,&P);
    *X=Infoldp(P);
    *a = Posisix(P);
    *b = Posisiy(P);
    Dealokasilistdp(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilldpNilldpai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastlistdp (List *L, elmntype *X,  int * a, int * b) 
{
    addressldp P;
    DelLastlistdp(L,&P);
    *X=Infoldp(P);
    *a = Posisix(P);
    *b = Posisiy(P);
    Dealokasilistdp(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilldpNilldpai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstlistdp (List *L, addressldp P) 
{
    if(IsEmptylistdp(*L)){
        Firstldp(*L)=P;
        Lastldp(*L)=P;
    }
    else{
        InsertBeforelistdp(L,P,Firstldp(*L));
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressldp P sebagai elemen pertama */
void InsertLastlistdp (List *L, addressldp P) 
{
    if(IsEmptylistdp(*L)){
        InsertFirstlistdp(L,P);
    }
    else {
        InsertAfterlistdp(L,P,Lastldp(*L));
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterlistdp (List *L, addressldp P, addressldp Prec) 
{
    Prevldp(P)=Prec;
    Nextldp(P)=Nextldp(Prec);
    Nextldp(Prec)=P;
    if(Nextldp(P)==Nilldp){
        Lastldp(*L)=P;
    }
    else{
        Prevldp(Nextldp(P))=P;
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforelistdp (List *L, addressldp P, addressldp Succ) 
{
    Prevldp(P)=Prevldp(Succ);
    Nextldp(P)=Succ;
    Prevldp(Succ)=P;
    if(Prevldp(P)==Nilldp){
        Firstldp(*L)=P;
    }
    else{
        Nextldp(Prevldp(P))=P;
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstlistdp (List *L, addressldp *P) 
{
    *P=Firstldp(*L);
    if(Firstldp(*L)==Lastldp(*L)){
        Firstldp(*L)=Nilldp;
        Lastldp(*L)=Nilldp;
    }
    else{
        Firstldp(*L)=Nextldp(Firstldp(*L));
        Prevldp(Firstldp(*L))=Nilldp;
    }
    Nextldp(*P)=Nilldp;
    Prevldp(*P)=Nilldp;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Firstldp element yg baru adalah suksesor elemen pertama yang lama */
void DelLastlistdp (List *L, addressldp *P) 
{
    *P=Lastldp(*L);
    if(Firstldp(*L)==Lastldp(*L)){
        Firstldp(*L)=Nilldp;
        Lastldp(*L)=Nilldp;
    }
    else{
        Lastldp(*L)=Prevldp(Lastldp(*L));
        Nextldp(Lastldp(*L))=Nilldp;
    }
    Nextldp(*P)=Nilldp;
    Prevldp(*P)=Nilldp;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Lastldp element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPlistdp (List *L, elmntype X, int a, int b) 
{
    addressldp cari=Searchlistdp(*L, a, b);
    if(cari!=Nilldp){
        addressldp P=Firstldp(*L),prec=Nilldp;
        while (P!=cari){
            prec=P;
            P=Nextldp(P);
        }
        if(prec==Nilldp){
            DelFirstlistdp(L,&cari);
        }
        else{
            DelAfterlistdp(L,&cari,prec);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressldp P, dengan Infoldp(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Infoldp(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfterlistdp (List *L, addressldp *Pdel, addressldp Prec) 
{
    *Pdel=Nextldp(Prec);
    if(Nextldp(*Pdel)==Nilldp){
        Nextldp(Prec)=Nilldp;
        Lastldp(*L)=Prec;
    }
    else{
        Nextldp(Prec)=Nextldp(*Pdel);
        Prevldp(Nextldp(*Pdel))=Prec;
    }
    Prevldp(*Pdel)=Nilldp;
    Nextldp(*Pdel)=Nilldp;
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Nextldp(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforelistdp (List *L, addressldp *Pdel, addressldp Succ) 
{
    *Pdel=Prevldp(Succ);
    if(Prevldp(*Pdel)==Nilldp){
        Prevldp(Succ)=Nilldp;
        Firstldp(*L)=Succ;
    }
    else{
        Prevldp(Succ)=Prevldp(*Pdel);
        Nextldp(Prevldp(*Pdel))=Succ;
    }
    Prevldp(*Pdel)=Nilldp;
    Nextldp(*Pdel)=Nilldp;
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prevldp(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardlistdp (List L) 
{
    if (IsEmptylistdp(L)){
        printf("[]");
    }
    else{
        addressldp P=Firstldp(L);
        printf("[");
        while(P!=Nilldp){
            if(P==Lastldp(L)){
                printf("%d",Infoldp(P));
            }
            else{
                printf("%d,",Infoldp(P));
            }
            P=Nextldp(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilldpNilldpai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardlistdp (List L) 
{
    if (IsEmptylistdp(L)){
        printf("[]");
    }
    else{
        addressldp P=Lastldp(L);
        printf("[");
        while(P!=Nilldp){
            if(P==Firstldp(L)){
                printf("%d",Infoldp(P));
            }
            else{
                printf("%d,",Infoldp(P));
            }
            P=Prevldp(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilldpNilldpai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */