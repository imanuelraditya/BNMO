#ifndef __ARRAY_MAP__
#define __ARRAY_MAP__

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../map/map.h"

#define InitialSize 150

typedef int MapIdx;
typedef Map MapType;
typedef struct {
    MapType *Tab;
    int MapCapacity;
    int MapNeff;
} ArrayMap;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayMap kosong dengan ukuran InitialSize
 */
ArrayMap MakeArrayMap();

/**
 * Destruktor
 * I.S. ArrayMap terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayMap(ArrayMap *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsArrayMapEmpty(ArrayMap array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthMap(ArrayMap array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
MapType GetMap(ArrayMap array, MapIdx i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetMapCapacity(ArrayMap array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertMapAt(ArrayMap *array, MapType el, MapIdx i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertMapLast(ArrayMap *array, MapType el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertMapFirst(ArrayMap *array, MapType el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteMapAt(ArrayMap *array, MapIdx i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteMapLast(ArrayMap *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteMapFirst(ArrayMap *array);

#endif