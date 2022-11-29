#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/array/arraydin.h"
#include "../ADT/queue/queue.h"
#include "../ADT/queue/queuedinerdash.h"

char* pilihTebakan(ArrayDin* daftarTebakan)
/* Mengambil salah satu kata dari file daftar kata untuk ditebak oleh pemain */
/* I.S Queue terdefinisi */
/* F.S Mengembalika output berupa string isi dari Queue */

void daftarTebak(Queue allTebak)
/* Mencetak daftar kata yang sudah ditebak oleh pemain */
/* I.S Array kosong */
/* F.S Array terisi dengan salah satu string kata dari file eksternal yang dipilih secara random */

boolean pengulangan(Queue allTebak, char input)
/* Mengirim true jika ada input huruf tebakan yang sudah pernah */
/* ditebak oleh pemain sebelumnya */
/* I.S Sembarang */
/* F.S Mengembalikan true jika ditemukan karakter yang sama dengan input pada Queue*/

void Hangman()
/* I.S Sembarang */
/* F.S Mengembalikan output berupa game Hangman */