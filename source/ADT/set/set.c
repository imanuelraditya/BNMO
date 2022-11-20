// Nama     : Michael Sihotang
// NIM      : 18221054

#include <stdio.h>
#include "set.h"

void CreateEmpty(Set *S) {
    (*S).Count = 0;
}

boolean IsEmpty(Set S) {
    return (S.Count == 0) ;
}

boolean IsFull(Set S) {
    return (S.Count == 100);
}

void Insert(Set *S, infotype Elmt) {
    if (!IsMember((*S), Elmt)) {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}

void Delete(Set *S, infotype Elmt) {
    int i;
    boolean found;

    i = 0;
    found = false;

    while (i < (*S).Count && !found) {
        if ((*S).Elements[i] == Elmt) {
            found = true;
            while (i < (*S).Count - 1) {
                (*S).Elements[i] = (*S).Elements[i + 1];
                i++;
            }
            (*S).Count--;
        } 
        else {
            i++;
        }
    }
}

boolean IsMember(Set S, infotype Elmt) {
    int i;
    boolean found;

    i = 0;
    found = false;

    while (i < S.Count && !found) {
        if (S.Elements[i] == Elmt) {
            found = true;
        } 
        else {
            i++;
        }
    }

    return found;
}

Set SetUnion(Set s1, Set s2) {
	Set s3 ;
	address idx1, idx2 ;
	idx1 = 0 ;
	idx2 = 0 ;
	CreateEmpty (&s3) ;

	while (idx1 < s1.Count) {
		Insert (&s3, s1.Elements[idx1]) ;
		idx1++ ;
	}
	while (idx2 < s2.Count) {
		Insert (&s3, s2.Elements[idx2]) ;
		idx2++ ;
	}
	return s3 ;
}
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2) {
	Set s3 ;
	address idx = 0 ;
	CreateEmpty (&s3) ;
	while (idx < s1.Count) {
		if (IsMember(s2, s1.Elements[idx])) {
			Insert (&s3, s1.Elements[idx]) ;
		}
		idx++ ;
	}
	return s3 ;
}
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2) {
	Set s3 ;
	address idx1, idx2 ;
	idx1 = 0 ;
	idx2 = 0 ;
	CreateEmpty (&s3) ;
	while (idx1 < s1.Count) {
		if (!IsMember(s2, s1.Elements[idx1])) {
			Insert (&s3, s1.Elements[idx1]) ;
		}
		idx1++ ;
	}
	while (idx2 < s2.Count) {
		if (!IsMember(s1, s2.Elements[idx2])) {
			Insert (&s3, s2.Elements[idx2]) ;
		}
		idx2++ ;
	}
	return s3 ;
}
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2) {
	Set s3 ;
	address idx = 0 ;
	CreateEmpty (&s3) ;
	while (idx < s1.Count) {
		if (!IsMember(s2, s1.Elements[idx])) {
			Insert (&s3, s1.Elements[idx]) ;
		}
		idx++ ;
	}
	return s3 ;
}
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]