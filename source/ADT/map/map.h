#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 10
#define Undefined -999

// typedef int bool;
typedef int keytype;
typedef int valuetype;
typedef int address;

typedef struct {
	keytype Key;
	valuetype Value;
} info;

typedef struct {
	info Elements[MaxEl];
	address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateMapEmpty(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsMapFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

Map UnionMap(Map m1, Map m2, boolean key_based );
    /* Menggabungkan m1 dengan m2 pada sebuah map baru dengan urutan yang ditentukan berdasarkan key_based
    apabila key_based true maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan keynya
    apabila key_based false maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan valuenya*/

    /*I.S : Map m1 dan m2 terdefinisi. m1 dan m2 TIDAK kosong dan TIDAK penuh
    F.S : Map m3 yang merupakan gabungan isi dari m1 dan m2 yang diisi berdasarkan nilai key_based. Jumlah elemen m3 TIDAK mungkin melebihi MaxEl*/

    /*Notes: 
        1. Apabila terdapat nilai key yg sama pada m1 dan m2, value yang akan ditambah pada map baru adalah value dari m1 pada key tersebut
        2. Ingat yang unik adalah key, bukan value
    Hint: Lakukan penambahan semua elemen dari m1 dan m2 ke m3 terlebih dahulu kemudian urutkan isinya menggunakan algoritma sorting*/
    
    /*
    Contoh:
        1.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: true
          Output:
            m3: {<1,2>,<7,1>,<8,100>,<11,10>,<20,3>}
        2.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: false
          Output:
            m3: {<7,1>,<1,2>,<20,3>,<11,10>,<8,100>}
    */

#endif