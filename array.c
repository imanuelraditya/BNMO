#include<stdio.h>
#include"boolean.h"
#include"array.h"

void MakeEmpty (TabInt *T) 
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    (*T).Neff = 0;
}

int NbElmt (TabInt T) 
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return T.Neff ;
}

int MaxNbEl (TabInt T) 
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax ;
}

IdxType GetFirstIdx (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin ;
}

IdxType GetLastIdx (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return NbElmt(T) ; 
}

ElType GetElmt (TabInt T, IdxType i) 
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return (T.TI[i]) ;
} 

void SetTab (TabInt Tin, TabInt *Tout) 
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
    IdxType i;
    for(i = IdxMin; i <= GetLastIdx(Tin); i++) {
        (*Tout).TI[i] = Tin.TI[i];
    }
    (*Tout).Neff = Tin.Neff;
}

void SetEl (TabInt *T, IdxType i, ElType v) 
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
    (*T).TI[i] = v ;
    (*T).Neff++ ; 
}

void SetNeff (TabInt *T, IdxType N) 
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    (*T).Neff = N ;
}

boolean IsIdxValid (TabInt T, IdxType i) 
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return((i <= GetFirstIdx(T)) && (i <= GetLastIdx(T))) ;
}

boolean IsIdxEff (TabInt T, IdxType i) 
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

boolean IsEmpty (TabInt T) 
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return(NbElmt(T)==0) ;
}

boolean IsFull (TabInt T) 
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return(NbElmt(T)==MaxNbEl(T));
}

void TulisIsi (TabInt T) 
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    IdxType i;
    if(IsEmpty(T)) {
        printf("Tabel kosong\n");
    }
    else {
        for (i = GetFirstIdx(T); i <= NbElmt(T); i++) {
            printf("%d:%d\n",i,T.TI[i]);
        }
    }
}

TabInt PlusTab (TabInt T1, TabInt T2) 
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
{
    TabInt T;
    int i;
    for (i=GetFirstIdx(T1); i<=GetLastIdx(T1); i++) {
        T.TI[i] = GetElmt(T1,i) + GetElmt(T2,i); 
	}
	T.Neff = T1.Neff; 
	return(T);
}

TabInt MinusTab (TabInt T1, TabInt T2) 
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

{
    TabInt T;
    int i;
    for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++) {
    T.TI[i] = GetElmt(T1,i) - GetElmt(T2,i); 
	}
	T.Neff = T1.Neff; 
	return(T);
}

ElType ValMax (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    ElType maksimum;
    int i;
    maksimum =  T.TI[IdxMin];
    for (i=IdxMin + 1;i<=GetLastIdx(T);i++) {
        if(maksimum < GetElmt(T,i))
        maksimum = GetElmt(T,i);
    }
    return (maksimum);
}

ElType ValMin (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    ElType mn;
    int i;
    mn =  T.TI[IdxMin];
    for (i=IdxMin + 1; i<=GetLastIdx(T); i++) {
        if(mn > T.TI[i])
        mn = T.TI[i];
   }
   return (mn);
}

IdxType IdxMaxTab (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
    ElType mxi;
    int i;
    mxi =  GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1;i <= GetLastIdx(T); i++) {
        if(GetElmt(T,mxi) < GetElmt(T,i))
        mxi = i;
    }
    return (mxi);
}

IdxType IdxMinTab (TabInt T) 
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
    ElType mni;
    int i;
    mni =  GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1;i <= GetLastIdx(T); i++) {
        if(GetElmt(T,mni) > GetElmt(T,i))
        mni = i;
    }
    return (mni);
}