#include<stdio.h>
#include<stdlib.h>
#include "../ADT/array/arraydin.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"

void save(Word filename, ArrayDin* listGame);
/* SAVE merupakan command yang digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file. 
   Command SAVE memiliki satu argumen yang merepresentasikan nama file yang akan disimpan pada disk.
*/