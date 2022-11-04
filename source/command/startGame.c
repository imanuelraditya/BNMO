#include <stdio.h>
#include "startGame.h"

void startGame(ArrayDin * arr)
/* membuka dan membaca file konfigurasi awal */
/* I.S. sembarang (tidak dapat menggunakan game)
   F.S. game sudah siap dimainkan
        List Game yang dapat dimainkan sudah tersedia yaitu dengan konfigurasi awal
        command - command lain dapat dijalankan */
{
    int jumlah, i; // jumlah game yang tersedia, untuk looping banyak membaca 

    startWFile("data/config.txt"); // membuka file konfigurasi awal yang tersedia di dalam file config.txt

    /* currentWord adalah baris pertama pada file config.txt
       baris pertama adalah jumlah game yang tersedia -> angka -> diubah dari string menjadi integer, 
       karena nanti akan digunakan untuk looping sesuai jumlah tersebut */

    jumlah = wordToInt(currentWord); // mengubah currentWord menjadi integer

    // memasukkan semua judul game pada file konfigurasi awal sebanyak 'jumlah' kedalam list game
    for (i = 0 ; i < jumlah ; i++) {
         advNewlineFile();
         InsertLast(arr, currentWord);
     }
}
