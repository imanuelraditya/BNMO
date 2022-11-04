#include <stdio.h>
#include "skipGame.h"

void skipGame(Queue * Q, int n) 
/* melewatkan permainan sebanyak n yang terdapat pada antrian game pribadi */
/* I.S. - game telah dijalankan
        - Queue game bisa kosong
        - n bisa lebih banyak dari daftar game yang tersedia
   F.S. - Jika Queue antrian game pribadi pemain KOSONG, maka akan menampilkan pesan 
          "Tidak ada permainan di dalam daftar game-mu"
        - Jika jumlah n melebihi jumlah permainan yang ada di daftar game permainan,
          menampilkan pesan "Tidak ada lagi permainan di dalam daftar game-mu" 
        - Jika jumlah n kurang dari jumlah permainan yang ada di daftar game permainan,
          akan dimainkan game pada queue teratas saat ini setelah n game dilewatkan     */
{
    // KAMUS LOKAL
    Word temp;
    int i = 0;
    // ALGORITMA
    if(IsQEmpty){
        printf("Tidak ada permainan di dalam daftar game-mu (T ^ T)\n");
    } else if(n > QNBElmt(*Q)){
        for(i = 0; i < QNBElmt(*Q) ; i++) { // menghapus semua isi yang ada di antrian game 
            Del(Q, &temp);                  // karena skip lebih banyak dr jumlah game di antrian
        }
        printf("Tidak ada lagi permainan di dalam daftar game-mu\n");
    } else { // n < QNBElmt(*Q) -> maka akan di play game paling atas 
        for(i = 0 ; i < n ; i++) {
            Del(Q, &temp);
        }
        playGame(*Q);

    }
}