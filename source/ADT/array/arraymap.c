#include <stdio.h>
#include <stdlib.h>
#include "arraymap.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayMap kosong dengan ukuran InitialSize
 */
ArrayMap MakeArrayMap() {
    ArrayMap arr;
    arr.Tab = (MapType*)malloc((InitialSize)*sizeof(MapType));
    arr.MapCapacity = InitialSize;
    arr.MapNeff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayMap terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayMap(ArrayMap *array) {
    free(array->Tab);
    array->MapNeff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsArrayMapEmpty(ArrayMap array) {
    return array.MapNeff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthMap(ArrayMap array) {
    return array.MapNeff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
MapType GetMap(ArrayMap array, MapIdx i) {
    return array.Tab[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetMapCapacity(ArrayMap array) {
    return array.MapCapacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertMapAt(ArrayMap *array, MapType el, MapIdx i) {
    int j;

    if (array->MapNeff < array->MapCapacity) {
        for (j = array->MapNeff; j > i; j--) {
            array->Tab[j] = array->Tab[j-1];
        }
        array->Tab[i] = el;
        array->MapNeff++;
    } else {
        MapType *temp = (MapType*)malloc((array->MapCapacity+1)*sizeof(MapType));
        for (j = 0; j < i; j++) {
            temp[j] = array->Tab[j];
        }
        free((void*)array->Tab);
        array->Tab = (MapType*)malloc((array->MapCapacity * 2)*sizeof(MapType));
        for (j = 0; j < i; j++) {
            array->Tab[j] = temp[j];
        }
        array->Tab[i] = el;
        for (j = i+1; j < array->MapNeff; j++) {
            array->Tab[j] = temp[j-1];
        }
        free(temp);
        array->MapCapacity *= 2;
        array->MapNeff++;
    }
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertMapLast(ArrayMap *array, MapType el) {
    InsertMapAt(array, el, array->MapNeff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertMapFirst(ArrayMap *array, MapType el) {
    InsertMapAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteMapAt(ArrayMap *array, MapIdx i) {
    int j;
    MapType el = GetMap(*array, i);
    if (array->MapNeff > array->MapCapacity / 4) {
        array->MapNeff--;
        for (j = i; j < array->MapNeff; j++) {
            array->Tab[j] = array->Tab[j+1];
        }
    }
    else {
        int newCapacity = InitialSize;
        if (newCapacity < array->MapCapacity / 2) {
            newCapacity = array->MapCapacity / 2;
        }
        MapType *temp = (MapType*)malloc((newCapacity)*sizeof(MapType));
        for (j = 0; j < i; j++) {
            temp[j] = array->Tab[j];
        }
        array->MapNeff--;
        for (j = i; j < array->MapNeff; j++) {
            temp[j] = array->Tab[j+1];
        }
        free(array->Tab);
        array->Tab = (MapType*)malloc((newCapacity)*sizeof(MapType));
        for (j = 0; j < array->MapNeff; j++) {
            array->Tab[j] = temp[j];
        }
        array->MapCapacity = newCapacity;
        free(temp);
    }
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteMapLast(ArrayMap *array) {
    DeleteMapAt(array, array->MapNeff-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteMapFirst(ArrayMap *array) {
    DeleteMapAt(array, 0);  
}