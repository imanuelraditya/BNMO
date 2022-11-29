/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan addressldp adalah pointer */
/* infoldptype adalah integer */

#ifndef listdp_H
#define listdp_H

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

#define Nilldp NULL

/* Definisi Type Data */
typedef struct tPOINT {
	int x;
	int y;
} POINT;
typedef POINT location;
typedef char* elmntype;
typedef struct tElmtlistdp *addressldp;
typedef struct tElmtlistdp {
	elmntype infoldp; 
    location posisi;
	addressldp nextldp;
	addressldp prevldp;
} ElmtListdp;
typedef struct {
	addressldp Firstldp;
	addressldp Lastldp;
} List;

/* Definisi list : */
/* List kosong : Firstldp(L) = Nilldp dan Lastldp(L) = Nilldp */
/* Setiap elemen dengan addressldp P dapat diacu Infoldp(P), Nextldp(P), Prevldp(P) */
/* Elemen terakhir list: Lastldp(L) */

/* Notasi Akses */
#define Infoldp(P) (P)->infoldp
#define Nextldp(P) (P)->nextldp
#define Prevldp(P) (P)->prevldp
#define Firstldp(L) ((L).Firstldp)
#define Lastldp(L) ((L).Lastldp)
#define Posisix(P) (P)->posisi.x
#define Posisiy(P) (P)->posisi.y
#define Posisi(P) (P)->posisi

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylistdp (List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptylistdp (List *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressldp Alokasilistdp (elmntype X, int a, int b);
/* Mengirimkan addressldp hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressldp tidak nilldp. */
/* Misalnya: menghasilkan P, maka Infoldp(P)=X, Nextldp(P)=Nilldp, Prevldp(P)=Nilldp */
/* Jika alokasi gagal, mengirimkan Nilldp. */
void Dealokasilistdp (addressldp P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressldp P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressldp Searchlistdp (List L, int a, int b);
/* Mencari apakah ada elemen list dengan Infoldp(P)=X */
/* Jika ada, mengirimkan addressldp elemen tersebut. */
/* Jika tidak ada, mengirimkan Nilldp */

/****************** PRIMITIF BERDASARKAN NILldpAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstlistdp (List *L, elmntype X, int a, int b) ;
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilldpai X jika alokasi berhasil */
void InsVLastlistdp (List *L, elmntype X, int a, int b) ;
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilldpai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstlistdp (List *L, elmntype *X, int * a, int * b);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilldpai infoldp disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastlistdp (List *L, elmntype *X, int * a, int * b);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilldpai infoldp disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstlistdp (List *L, addressldp P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressldp P sebagai elemen pertama */
void InsertLastlistdp (List *L, addressldp P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterlistdp (List *L, addressldp P, addressldp Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforelistdp (List *L, addressldp P, addressldp Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstlistdp (List *L, addressldp *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Firstldp element yg baru adalah suksesor elemen pertama yang lama */
void DelLastlistdp (List *L, addressldp *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Lastldp element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPlistdp (List *L,  elmntype X, int a, int b);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressldp P, dengan Infoldp(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Infoldp(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfterlistdp (List *L, addressldp *Pdel, addressldp Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Nextldp(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforelistdp (List *L, addressldp *Pdel, addressldp Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prevldp(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardlistdp (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilldpai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardlistdp (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilldpai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif