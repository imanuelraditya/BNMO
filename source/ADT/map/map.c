#include <stdio.h>
#include "map.h"

void CreateMapEmpty(Map *M)
{
    M->Count = Nil;
}

boolean IsMapEmpty(Map M)
{
    return M.Count == Nil;
}

boolean IsMapFull(Map M)
{
    return M.Count == MaxEl;
}

valuetype Value(Map M, keytype k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (isWordEqual(M.Elements[i].Key, k))
        {
            return M.Elements[i].Value;
        }
        i++;
    }
    return Undefined;
}

void Insert(Map *M, keytype k, valuetype v)
{
    if (!IsMapFull(*M))
    {
        M->Count++;
        M->Elements[M->Count - 1].Key = k;
        M->Elements[M->Count - 1].Value = v;
    
    }
}

void Delete(Map *M, keytype k)
{
    if (M->Count == 1)
    {
        M->Count = Nil;
    }
    else
    {
        if (IsMemberMap(*M, k))
        {
            int i = 0;
            while (i < M->Count && !isWordEqual(M->Elements[i].Key, k))
            {
                i++;
            }
            while (i < M->Count)
            {
                M->Elements[i].Key = M->Elements[i + 1].Key;
                M->Elements[i].Value = M->Elements[i + 1].Value;
                i++;
            }
            M->Count--;
        }
    }
}

boolean IsMemberMap(Map M, keytype k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (isWordEqual(lowerWord(M.Elements[i].Key), lowerWord(k)))
        {
            return true;
        }
        i++;
    }
    return false;
}

Map UnionMap(Map m1, Map m2, boolean key_based )
{
	Map m3;
	CreateMapEmpty(&m3);
	for(int i=0; i<m1.Count ; i++){
		Insert(&m3,m1.Elements[i].Key,m1.Elements[i].Value);
	}
	for(int j=0; j<m2.Count ; j++){
		Insert(&m3,m2.Elements[j].Key,m2.Elements[j].Value);
	}
	if (key_based) {
		for (int k=0 ; k<m3.Count-1 ; k++){
			for (int l=k+1; l<m3.Count ; l++){	
				if (wordToInt(m3.Elements[k].Key) > wordToInt(m3.Elements[l].Key)){
					info temp;
					temp=m3.Elements[k];
					m3.Elements[k]=m3.Elements[l];
					m3.Elements[l]=temp;
				}
			}
		}
	}
	else{
		for (int k=0 ; k<m3.Count-1 ; k++){
			for (int l=k+1; l<m3.Count ; l++){	
				if (m3.Elements[k].Value>m3.Elements[l].Value){
					info temp;
					temp=m3.Elements[k];
					m3.Elements[k]=m3.Elements[l];
					m3.Elements[l]=temp;
				}
				else if (m3.Elements[k].Value==m3.Elements[l].Value) {
					if (wordToInt(m3.Elements[k].Key) > wordToInt(m3.Elements[l].Key)){
						info temp;
						temp=m3.Elements[k];
						m3.Elements[k]=m3.Elements[l];
						m3.Elements[l]=temp;
					}
				}
			}
		}		
	}
	return m3;
}