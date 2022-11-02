/*LOAD merupakan salah satu command yang dimasukkan pertama kali oleh pemain ke BNMO. 
Memiliki satu argumen yaitu filename yang merepresentasikan suatu save file yang ingin dibuka. 
Setelah menekan Enter, akan dibaca save file <filename> yang berisi list game yang dapat dimainkan, 
histori dan scoreboard game.*/

void load(char* filename) {
    STARTWORD(filename);
    if (EndWord) {
        printf("File tidak ditemukan\n");
    } else {
        printf("File ditemukan\n");