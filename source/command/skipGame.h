#include <stdio.h>
#include "../ADT/queue/queue.h"
#include "PlayGame.h"

void skipGame(Queue * Q, int n);
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