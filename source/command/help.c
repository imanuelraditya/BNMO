#include <stdio.h>
#include "help.h"

void help() {
/* deskripsi atau bantuan dari command-command lain*/
    printf("================================================================\n");
    printf("  +:*+.+:*+.+:*+.+:*+.  H E L P  M E N U .+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("                daftar dan cara kerja command:\n");
    printf("1. LIST GAME   : menampilkan daftar game yang disediakan\n");
    printf("2. QUEUE GAME  : mendaftarkan game ke dalam antrian game pribadi\n");
    printf("3. PLAY GAME   : memainkan sebuah game\n");
    printf("4. SKIP GAME   : melewatkan game sebanyak yang diinginkan\n");
    printf("5. CREATE GAME : menambahkan game baru pada daftar game\n");
    printf("6. DELETE GAME : menghapus sebuah game dari daftar game\n");
    printf("7. QUIT        : keluar dari program game ^^\n");
    printf("8. SAVE <filename.txt> : menyimpan state game pemain saat ini\n");
    printf("================================================================\n");
}
