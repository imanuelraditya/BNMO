#include<stdio.h>
#include"boolean.h"
#include"array.h"

void MakeEmpty (TabInt *T) {
    (*T).Neff = 0;
}

int NbElmt (TabInt T) {
    return T.Neff ;
}

int MaxNbEl (TabInt T) {
    return IdxMax ;
}

IdxType GetFirstIdx (TabInt T) {
    return IdxMin ;
}

IdxType GetLastIdx (TabInt T) {
    return NbElmt(T) ; 
}

ElType GetElmt (TabInt T, IdxType i) {
    return (T.TI[i]) ;
} 

void SetTab (TabInt Tin, TabInt *Tout) {
    IdxType i;
    for(i = IdxMin; i <= GetLastIdx(Tin); i++) {
        (*Tout).TI[i] = Tin.TI[i];
    }
    (*Tout).Neff = Tin.Neff;
}

void SetEl (TabInt *T, IdxType i, ElType v) {
    (*T).TI[i] = v ;
    (*T).Neff++ ; 
}

void SetNeff (TabInt *T, IdxType N) {
    (*T).Neff = N ;
}

boolean IsIdxValid (TabInt T, IdxType i) {
    return((i <= GetFirstIdx(T)) && (i <= GetLastIdx(T))) ;
}

boolean IsIdxEff (TabInt T, IdxType i) {
    return((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

boolean IsEmpty (TabInt T) {
    return(NbElmt(T)==0) ;
}

boolean IsFull (TabInt T) {
    return(NbElmt(T)==MaxNbEl(T));
}

void TulisIsi (TabInt T) {
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

TabInt PlusTab (TabInt T1, TabInt T2) {
    TabInt T;
    int i;
    for (i=GetFirstIdx(T1); i<=GetLastIdx(T1); i++) {
        T.TI[i] = GetElmt(T1,i) + GetElmt(T2,i); 
	}
	T.Neff = T1.Neff; 
	return(T);
}

TabInt MinusTab (TabInt T1, TabInt T2) {
    TabInt T;
    int i;
    for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++) {
    T.TI[i] = GetElmt(T1,i) - GetElmt(T2,i); 
	}
	T.Neff = T1.Neff; 
	return(T);
}

ElType ValMax (TabInt T) {
    ElType maksimum;
    int i;
    maksimum =  T.TI[IdxMin];
    for (i=IdxMin + 1;i<=GetLastIdx(T);i++) {
        if(maksimum < GetElmt(T,i))
        maksimum = GetElmt(T,i);
    }
    return (maksimum);
}

ElType ValMin (TabInt T) {
    ElType mn;
    int i;
    mn =  T.TI[IdxMin];
    for (i=IdxMin + 1; i<=GetLastIdx(T); i++) {
        if(mn > T.TI[i])
        mn = T.TI[i];
   }
   return (mn);
}

IdxType IdxMaxTab (TabInt T) {
    ElType mxi;
    int i;
    mxi =  GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1;i <= GetLastIdx(T); i++) {
        if(GetElmt(T,mxi) < GetElmt(T,i))
        mxi = i;
    }
    return (mxi);
}

IdxType IdxMinTab (TabInt T) {
    ElType mni;
    int i;
    mni =  GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1;i <= GetLastIdx(T); i++) {
        if(GetElmt(T,mni) > GetElmt(T,i))
        mni = i;
    }
    return (mni);
}