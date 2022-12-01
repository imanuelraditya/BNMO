#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

/* LIST FUNGSI PROSEDUR COMMAND */

// CREATE GAME

void CreateGame (ArrayDin* listGame, ArrayMap* listScoreboard) {
    boolean found;
    int i;
    Map M;

    found = false;
    i = 0;

    printf("Masukkan nama game yang ingin ditambahkan: ");
    STARTGAMENAME();

    while (i < Length(*listGame) && !found) {
        if (isWordEqual(lowerWord(currentCommand), lowerWord((*listGame).A[i]))) {
            found = true;
        }
        else {
            i++;
        }
    }

    if (found) {
        printf("Game sudah ada di dalam list.\n");
    } else {
        InsertLast(listGame, currentCommand);
        CreateMapEmpty(&M);
        InsertMapLast(listScoreboard, M);
        printf("Game berhasil ditambahkan.\n");
    }
}

// DELETE GAME

void deleteGame (ArrayDin* listGame, ArrayDin* listHistory, ArrayMap* listScoreboard, Queue Q) 
{
    int nomor, i, gameQueue;
    boolean found;

    gameQueue = QNBElmt(Q);
    i = Head(Q);
    found = false;

    ListGame(*listGame);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();

    if (commandWord(currentCommand) == 1) {

        nomor = wordToInt(currentCommand);

        while (i <= Tail(Q) && !found) {
            if (isWordEqual(Q.T[i], Get(*listGame, (nomor - 1)))) {
                found = true;
            }
            else {
                if (i == (QMaxEl(Q) - 1)) {
                    i = 0;
                }
                else {
                    i++;
                }
            }
        }
        
        if (found)
        {
            printf("\nGame gagal dihapus.\n");
        }
        else {
            if (nomor == 1 || nomor == 2 || nomor == 3 || nomor == 4 || nomor == 5)
            {
                printf("\nGame gagal dihapus.\n");
            }
            else 
            {
                if (nomor > Length(*listGame) || nomor < 1) {
                    printf("\nGame gagal dihapus.\n");
                }
                else {
                    for (i = 0; i < Length(*listHistory); i++) {
                        if (isWordEqual(Get(*listHistory, i), Get(*listGame, (nomor-1)))) {
                            DeleteAt(listHistory, i);
                        }
                    }
                    
                    DeleteAt(listGame, (nomor-1));
                    DeleteMapAt(listScoreboard, (nomor-1));

                    printf("\nGame berhasil dihapus.\n");
                }
            }
        }
    }
    else {
        invalidCommand(&currentCommand);
    }
}

// HELP

void help() {
    printf("==========================================================================\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U .+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("                daftar dan cara kerja command:\n");
    printf("1.  LIST GAME            : menampilkan daftar game yang disediakan\n");
    printf("2.  QUEUE GAME           : mendaftarkan game ke dalam antrian game pribadi\n");
    printf("3.  PLAY GAME            : memainkan sebuah game\n");
    printf("4.  SKIP GAME <n>        : melewatkan game sebanyak yang diinginkan\n");
    printf("5.  CREATE GAME          : menambahkan game baru pada daftar game\n");
    printf("6.  DELETE GAME          : menghapus sebuah game dari daftar game\n");
    printf("7.  SCOREBOARD           : melihat nama dan skor untuk semua game\n");
    printf("8.  RESET SCOREBOARD     : mereset scoreboard permainan\n");
    printf("9.  HISTORY <n>          : menampilkan n permainan yang telah dimainkan\n");
    printf("10. RESET HISTORY        : menghapus semua history permainan\n");
    printf("11. QUIT                 : keluar dari program game ^^\n");
    printf("12. SAVE <filename.txt>  : menyimpan state game pemain saat ini\n");
    printf("==========================================================================\n");
}

// COMMAND LAIN

void invalidCommand(Word* w) {
    while (!EndWord) {
        ADVCOMMAND();
    }
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}

// LIST GAME

void ListGame (ArrayDin array) {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan list game yang tersedia */
    /* Proses: Menampilkan list game yang tersedia */
    
    int i;

    printf("Berikut adalah daftar game yang tersedia\n");
    if (IsEmpty(array)) {
        printf("Tidak ada game yang tersedia.\n");
    } else {
        for (i = 0; i < Length(array); i++) {
            printf("%d. %s\n", (i + 1), wordToString(array.A[i]));
        }
    }
}

// LOAD <filename.txt>

void load(Word filename, ArrayDin* arrayGame, ArrayDin* arrayHistory, ArrayMap* ArrayMap, boolean* esc) {
    /* LOAD merupakan salah satu command yang dimasukkan pertama kali oleh pemain ke BNMO. 
    Memiliki satu argumen yaitu filename yang merepresentasikan suatu save file yang ingin dibuka. 
    Setelah menekan Enter, akan dibaca save file <filename> yang berisi list game yang dapat dimainkan */

    char* maindir;
    int count, i, j, k;
    Word format, gameName, gameScore;
    Map M;

    maindir = "data/";
    i = 0;

    format.Length = 4;

    for (i = 0; i < 4; i++) {
        format.TabWord[i] = filename.TabWord[filename.Length - 4 + i];
    }

    if (isWordEqual(format, stringToWord(".txt")) || isWordEqual(format, stringToWord(".TXT"))) {
        startWFile(wordToString(concatWord(stringToWord(maindir), filename)));

        count = wordToInt(currentWord);

        for (i = 0; i < count; i++) {
            advNewlineFile();
            InsertLast(arrayGame, currentWord);
            CreateMapEmpty(&M);
            InsertMapLast(ArrayMap, M);
        }

        advNewlineFile();
        
        count = wordToInt(currentWord);

        for (i = 0; i < count; i++) {
            advNewlineFile();
            InsertLast(arrayHistory, currentWord);
        }

        for (int k = 0; k < LengthMap(*ArrayMap); k++) {
            advNewlineFile();

            count = wordToInt(currentWord);

            gameName.TabWord[0] = '\0';
            gameName.Length = 0;

            gameScore.TabWord[0] = '\0';
            gameScore.Length = 0;

            for (i = 0; i < count; i++) {
                advNewlineFile();
                j = 0;

                while (currentWord.TabWord[j] != BLANK) {
                    gameName.TabWord[j] = currentWord.TabWord[j];
                    j++;
                    gameName.Length++;
                }

                j++;

                while (j < currentWord.Length) {
                    gameScore.TabWord[j - (gameName.Length + 1)] = currentWord.TabWord[j];
                    j++;
                    gameScore.Length++;
                }

                Insert(&ArrayMap->Tab[k], gameName, wordToInt(gameScore));

                gameName.Length = 0;
                gameScore.Length = 0;
            }
        }

        if (Length(*arrayGame) == 0) {
            loadFailed();
        }
        else {
            loadSuceeded();
            (*esc) = true;
        }
    }
    else {
        printf("Format file tidak valid.\n");
    }
}

void loadSuceeded() {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan pesan loading berhasil */
    /* Proses: Menampilkan pesan loading berhasil */
    
    /* loading.. */

    /* KAMUS LOKAL */
        int i, j, delay;

    /* ALGORITMA */
        printf("LOADNG FILE");

        for(i = 0; i < 10; i++) { // jumlah '>'
            for(j = 0; j < 100000000; j++) { // buat delay prosesnya
                delay = j;
            }
            printf(" .");
        }

        printf(" [SUCCEEDED //]\n\n");

        for(j = 0; j < 100099999 ; j++) { //delay lagi
            delay = j;
            }
        
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void loadFailed() {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan pesan loading gagal */
    /* Proses: Menampilkan pesan loading gagal */
    
    /* loading.. */

    /* KAMUS LOKAL */
        int i, j, delay;

    /* ALGORITMA */
        printf("LOADNG FILE");

        for(i = 0; i < 10; i++) { // jumlah '>'
            for(j = 0; j < 100000000; j++) { // buat delay prosesnya
                delay = j;
            }
            printf(" .");
        }

        printf(" [FAILED XX]\n\n");

        for(j = 0; j < 100099999 ; j++) { //delay lagi
            delay = j;
            }
        
        printf("Load file gagal. File tidak ditemukan.\n");
}

// PLAY GAME

void randomScore(Word game, int* score) {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan score random */
    /* Proses: Menampilkan score random */
    
    /* KAMUS LOKAL */
        int i, j, delay;

    /* ALGORITMA */
        printf("PLAYING %s", wordToString(game));

        for(i = 0; i < 10; i++) { // jumlah '>'
            for(j = 0; j < 100000000; j++) { // buat delay prosesnya
                delay = j;
            }
            printf(" .");
        }

        printf(" [//GAME OVER//]\n\n");

        for(j = 0; j < 100099999 ; j++) { //delay lagi
            delay = j;
            }
        
        (*score) = rand() % 100;

        printf("Score: %d\n", (*score));
}

void playGame (Queue* queueGame, ArrayDin arrayGame, ArrayDin* arrayHistory, ArrayMap* arrayMap)
{
    Word play, username;
    int score, i;
    Map M;
    boolean namevalid;

    ListQueueGame (*queueGame) ; 

    printf ("\n") ;

    if (!IsQEmpty (*queueGame)) {
        Del(queueGame, &play) ; 

        if (isWordEqual(play, stringToWord("DINER DASH"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            dinerdash(&score);
        }
        else if (isWordEqual(play, stringToWord("RNG"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            rng(&score) ;
        }
        else if (isWordEqual(play, stringToWord("TOWER OF HANOI"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            towerOfHanoi(&score);
        }
        // else if (isWordEqual(play, stringToWord("DINOSAUR IN EARTH")) || isWordEqual(play, stringToWord("RISEWOMAN")) || isWordEqual(play, stringToWord("EIFFEL TOWER"))) {
        //     printf ("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", wordToString(play)) ;
        // }
        else if (isWordEqual(play, stringToWord("SNAKE ON METEOR"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            snakeOnMeteor(&score);
        }
        else if (isWordEqual(play, stringToWord("HANGMAN"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            hangman(&score);
        }
        else {
            randomScore(play, &score);
        }

        InsertFirst(arrayHistory, play);
        
        namevalid = false;

        while (!namevalid) {
            printf("\nMasukkan username anda: ");

            STARTCOMMAND();

            if (commandWord(currentCommand) == 1) {
                namevalid = true;

                username = currentCommand;
                
                i = 0;

                while (!isWordEqual(play, arrayGame.A[i])) {
                    i++;
                }

                while (IsMemberMap(arrayMap->Tab[i], username)) {
                    if (IsMemberMap(arrayMap->Tab[i], username)) {
                        printf("Username sudah terdaftar.\n");
                    }

                    printf("\nMasukkan username anda: ");

                    STARTCOMMAND();

                    if (commandWord(currentCommand) == 1) {
                        username = currentCommand;
                    }

                    else {
                        invalidCommand(&currentCommand);
                    }
                }
            
                Insert(&arrayMap->Tab[i], username, score);
                sortMapDesc(&arrayMap->Tab[i]);
            }
            else {
                printf("Username hanya boleh terdiri atas satu kata, silahkan masukkan username yang valid.\n");
            }
        }
    }
    
    else {
        printf ("Belum ada game yang dimasukkan ke dalam antrean. Silahakan Queue Game terlebih dahulu.\n") ;
    }
}

// QUEUE GAME

void queueGame(ArrayDin listGame, Queue* Q)
{
    int i;
    
    ListQueueGame(*Q);

    printf("\n");

    ListGame(listGame);

    printf("\n");


    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTCOMMAND();

    if (commandWord(currentCommand) == 1) {

        if (wordToInt(currentCommand) > Length(listGame) || wordToInt(currentCommand) < 1){
            while (!EndWord) {
                ADVCOMMAND();
            }
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        }
        else {
            for (i = 0; i < Length(listGame); i++)
            {
                if (i == wordToInt(currentCommand) - 1)
                {
                    Add(Q, Get(listGame, i));
                }
            }

            printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
        }
    }
    else {
        invalidCommand(&currentCommand);
    }
}

// QUIT

void Quit(){
    printf("\nAnda keluar dari game BNMO\nBye bye ...\n");
    exit(0);
}

// SAVE <filename.txt>

void save(Word filename, ArrayDin listGame, ArrayDin arrayHistory, ArrayMap arrayMap) {
    FILE *fpointer;
    char* maindir;
    Word format;
    int i;

    maindir = "data/";

    format.Length = 4;

    for (i = 0; i < 4; i++) {
        format.TabWord[i] = filename.TabWord[filename.Length - 4 + i];
    }

    if (isWordEqual(format, stringToWord(".txt")) || isWordEqual(format, stringToWord(".TXT"))) {
        fpointer = fopen(wordToString(concatWord(stringToWord(maindir), filename)), "w");

        if (fpointer == NULL) {
            printf("Tidak ada nama file yang tercantum. Silakan coba lagi.\n");
        }
        else  {
            fprintf(fpointer, "%d\n", Length(listGame));
            for (i = 0; i < Length(listGame); i++)
            {
                fprintf(fpointer, "%s\n", wordToString(Get(listGame, i)));
            }

            fprintf(fpointer, "%d\n", Length(arrayHistory));
            for (i = 0; i < Length(arrayHistory); i++)
            {
                fprintf(fpointer, "%s\n", wordToString(Get(arrayHistory, i)));
            }

            for (int i = 0; i < LengthMap(arrayMap); i++)
            {
                fprintf(fpointer, "%d\n", (GetMap(arrayMap, i).Count));
                for (int j = 0; j < (GetMap(arrayMap, i).Count); j++)
                {
                    fprintf(fpointer, "%s %d\n", wordToString(GetMap(arrayMap, i).Elements[j].Key), GetMap(arrayMap, i).Elements[j].Value);
                }
            }

            fclose(fpointer);
        }

        printf("Save file berhasil disimpan\n");
    }

    else {
        printf("Format file tidak valid. Silakan coba lagi.\n");
    }
}

// SKIP GAME <n>

void skipGame(Queue * Q, ArrayDin arrayGame, ArrayDin* arrayHistory, ArrayMap* arrayMap, int n) 
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
    if (IsQEmpty(*Q)) {
        printf("Tidak ada permainan di dalam daftar game-mu\n");
    }
    else {
        while (i < n && !IsQEmpty(*Q)) {
            Del(Q, &temp);
            i++;
        }
        if (IsQEmpty(*Q)) {
            printf("Tidak ada permainan lagi di dalam daftar game-mu\n");
        }
        else {
            playGame(Q, arrayGame, arrayHistory, arrayMap);
        }
    }
}

// START GAME

void startGame(ArrayDin * arr, ArrayMap* arrayMap)
/* membuka dan membaca file konfigurasi awal */
/* I.S. sembarang (tidak dapat menggunakan game)
   F.S. game sudah siap dimainkan
        List Game yang dapat dimainkan sudah tersedia yaitu dengan konfigurasi awal
        command - command lain dapat dijalankan */
{
/* KAMUS LOKAL */
    int jumlah, i; // jumlah game yang tersedia, untuk looping banyak membaca
    Map M; // map untuk menyimpan scoreboard yang tersedia
    
/* ALGORITMA */
    startWFile("data/config.txt"); // membuka file konfigurasi awal yang tersedia di dalam file config.txt

    /* currentWord adalah baris pertama pada file config.txt
       baris pertama adalah jumlah game yang tersedia -> angka -> diubah dari string menjadi integer, 
       karena nanti akan digunakan untuk looping sesuai jumlah tersebut */

    jumlah = wordToInt(currentWord); // mengubah currentWord menjadi integer

    // memasukkan semua judul game pada file konfigurasi awal sebanyak 'jumlah' kedalam list game
    for (i = 0 ; i < jumlah ; i++) {
         advNewlineFile();
         InsertLast(arr, currentWord);
         CreateMapEmpty(&M);
         InsertMapLast(arrayMap, M);
     }

     printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

// WELCOME

void loading() 
/* loading.. */
{
/* KAMUS LOKAL */
    int i, j, delay;

/* ALGORITMA */
    printf("accessing BNMO ");

    for(i = 0; i < 10; i++) { // jumlah '>'
        for(j = 0; j < 100000000; j++) { // buat delay prosesnya
            delay = j;
        }
        printf(">");
    }

    printf(" [COMPLETE]\n\n");

    for(j = 0; j < 100099999 ; j++) { //delay lagi
        delay = j;
        }
}

void welcome() // baru bisa di jalanin kalo NMax di mesinkata diganti jadi 100
/* print welcoming page bnmo */
{
/* ALGORITMA */
    loading();
    startWFile("data/bnmo.txt");

    while(!finish) {
        printf("%s\n", currentWord.TabWord);
        advNewlineFile();
    }
}

// LIST HISTORY

void listHistory(ArrayDin array, int n) {
    int i;

    printf("Berikut adalah daftar Game yang telah dimainkan:\n");

    if (n > Length(array)) {
        n = Length(array);
    }

    if (n == 0) {
        printf("Tidak ada permainan yang pernah dimainkan\n");
    }
    else {
        for (i = 0; i < n; i++) {
            printf("%d. %s\n", i+1, wordToString(Get(array, i)));
        }
    }
}

// RESET HISTORY

void resetHistory(ArrayDin * arrayHistory) {
    (*arrayHistory) = MakeArrayDin();
    printf("\nHistory berhasil di-reset.\n");
}

// SCOREBOARD

void displayScoreboard(ArrayDin arrayGame, ArrayMap arrayMap) {
    for (int i = 0; i < LengthMap(arrayMap); i++) {
        if (IsMapEmpty(arrayMap.Tab[i])) {
            printf("\n**** SCOREBOARD GAME %s ****\n", wordToString(Get(arrayGame, i)));
            printf("| %-10s | %-10s |\n", "NAMA", "SCORE");
            printf("---- SCOREBOARD KOSONG ----\n");
        }
        else {
            int maxname, maxscore;

            printf("\n**** SCOREBOARD GAME %s ****\n", wordToString(Get(arrayGame, i)));

            maxname = 0;
            maxscore = 0;

            for (int j = 0; j < (arrayMap.Tab[i]).Count; j++) {
                if ((arrayMap.Tab[i]).Elements[j].Key.Length > maxname) {
                    maxname = (arrayMap.Tab[i]).Elements[j].Key.Length;
                }
                if (intToWord((arrayMap.Tab[i]).Elements[j].Value).Length > maxscore) {
                    maxscore = intToWord((arrayMap.Tab[i]).Elements[j].Value).Length;
                }
            }

            printf("| NAMA");

            for (int j = 0; j < maxname + 2; j++) {
                printf(" ");
            }

            printf("| SCORE");

            for (int j = 0; j < maxscore + 2; j++) {
                printf(" ");
            }

            printf("|\n");

            printf("|");

            for (int j = 0; j < maxname + maxscore + 16; j++) {
                printf("-");
            }

            printf("|\n");

            for (int j = 0; j < (arrayMap.Tab[i]).Count; j++) {
                printf("| %s", wordToString(arrayMap.Tab[i].Elements[j].Key));

                for (int k = 0; k < maxname + 6 - (arrayMap.Tab[i]).Elements[j].Key.Length; k++) {
                    printf(" ");
                }

                printf("| %d", arrayMap.Tab[i].Elements[j].Value);

                if (arrayMap.Tab[i].Elements[j].Value == 0) {
                    for (int k = 0; k < maxscore + 6 - intToWord((arrayMap.Tab[i]).Elements[j].Value).Length; k++) {
                        printf(" ");
                    }
                }
                else {
                    for (int k = 0; k < maxscore + 7 - intToWord((arrayMap.Tab[i]).Elements[j].Value).Length; k++) {
                        printf(" ");
                    }
                }

                printf("|\n");
            }
        }
    }
}

// RESET SCOREBOARD

void resetScoreboard(ArrayMap * arrayMap, int n) {
    if (n < 0 || n > LengthMap(*arrayMap)) {
        printf("\nGame tidak ditemukan. Scoreboard tidak jadi di-reset.\n\n");
    }
    else {
        if (n == 0) {
            for (int i = 0; i < LengthMap(*arrayMap); i++) {
                CreateMapEmpty(&(*arrayMap).Tab[i]);
            }
        } 
        else if (n > 0 && n <= LengthMap(*arrayMap)) {
            CreateMapEmpty(&(*arrayMap).Tab[n-1]);
        }
        printf("\nScoreboard berhasil di-reset.\n");
    }
}

/* LIST FUNGSI PROSEDUR GAME */

// DINER DASH

void displayOrder(QueueInt Q)
{
    int i = IDX_HEAD(Q);
    printf("Daftar Pesanan\n");
    printf("Makanan\t| Durasi memasak |  Ketahanan\t|  Harga\n");
    printf("--------------------------------------------------\n");
    for(i; i <= IDX_TAIL(Q); i++){
        printf("M%d\t|\t%d\t |\t%d\t|  %d\n", i, Q.buffer[i].cookTime, Q.buffer[i].expTime, Q.buffer[i].price);
    }
    printf("\n");
}

void displayCook(Map C)
{
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("---------------------------------\n");
    if(C.Count > 0)
    {
        int i = 0;
        for(i; i <= C.Count - 1; i++)
        {
            printf("M%d\t|\t%d\n", wordToInt(C.Elements[i].Key), C.Elements[i].Value);
        }
    }
    else
    {
        printf("\t|\n\n");
    }
    printf("\n");
}

void displayServe(Map C)
{
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan\t| Sisa ketahanan makanan\n");
    printf("---------------------------------\n");
    if(C.Count > 0)
    {
        int i = 0;
        for(i; i <= C.Count - 1; i++)
        {
            printf("M%d\t|\t%d\n", wordToInt(C.Elements[i].Key), C.Elements[i].Value);
        }
    }
    else
    {
        printf("\t|\n\n");
    }
    printf("\n");
}

int randomNumber(int max, int min){
    return ( (rand() % max) + min);
}

int idxToInt(char *idx){
    int i = 0;
    int index = 0;

    for(i; i < 2;i++){
        if( (idx[i+1]-'0') >= 0 && (idx[i+1]-'0') <=99){
            index = index*10 + (idx[i+1] - '0');
        }
    }
    return index;
}

void sortMapAsc(Map *Map){
    // Algoritma Bubble Sort
    int i = 1;
    int j = 0;
    int count = Map->Count;
    for(i; i <= count - 1; i++)
    {
        for(j; j <= count - 2; j++)
        {
            if(Map->Elements[j].Value > Map->Elements[j+1].Value)
            {
                info temp = Map->Elements[j];
                Map->Elements[j] = Map->Elements[j+1];
                Map->Elements[j+1] = temp;
            }
        }
    }
}

void sortMapDesc(Map *Map){
    // Algoritma Bubble Sort
    int i, j;
    int count;
    
    count = Map->Count;
    for(i = count - 1; i >= 1; i--)
    {
        for(j = count - 2; j >= 0; j--)
        {
            if(Map->Elements[j].Value < Map->Elements[j+1].Value)
            {
                info temp = Map->Elements[j];
                Map->Elements[j] = Map->Elements[j+1];
                Map->Elements[j+1] = temp;
            }
        }
    }
}

void dinerdash(int* score){
    // Deklarasi ADT
    QueueInt Order;
    Map Cook;
    Map Serve;

    // Inisialisasi ADT
    CreateQueueInt(&Order);
    CreateMapEmpty(&Cook);
    CreateMapEmpty(&Serve);

    // Inisialisasi Variabel
    int serveCount = 0;
    int saldo = 0;

    // Inisialiasi 3 order awal
    int firstOrder = 0;
    for(firstOrder; firstOrder < 3; firstOrder++){
        ElTypeInt ord;
        ord.cookTime = randomNumber(5,1);
        ord.expTime = randomNumber(5,1);
        ord.price = randomNumber(50000,10000);
        enqueue(&Order, ord);
    }

// Program Utama
    printf("Selamat Datang di Diner Dash!");
    
    // Looping Untuk Keberjalanan Game
    while (QueueIntLength(Order) <= 7 && serveCount < 15)
    {

        // Display
        printf("\n\nSALDO: %d\n\n", saldo);
        displayOrder(Order);
        displayCook(Cook);
        displayServe(Serve);

        // Inisialisasi variabel untuk input command
        char command[6];
        char index[4];
        boolean valid = false;
        int countValid = 0;
        int i;

        // Command dan validasi kebenaran inputnya
        while(!valid){
            printf("COMMAND : ");
            STARTCOMMAND();
            
            for (i = 0; i< currentCommand.Length; i++){
                command[i] = currentCommand.TabWord[i];
            }

            if((command[0] == 'C' && command[1] == 'O' && command[2] == 'O' && command[3] == 'K') || (command[0] == 'c' && command[1] == 'o' && command[2] == 'o' && command[3] == 'k'))
            {
                ADVCOMMAND();

                if (commandWord(currentCommand) == 1) {
                    for (i = 0; i< currentCommand.Length; i++){
                        index[i] = currentCommand.TabWord[i];
                    }

                    if(index[0] == 'M' && idxToInt(index) < (QueueIntLength(Order) + serveCount))
                    {
                        valid = true;
                    }
                    else
                    {
                        printf("M%d tidak ada pada Order!\n", idxToInt(index));
                    }
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else if((command[0] == 'S' && command[1] == 'E' && command[2] == 'R' && command[3] == 'V' && command[4] == 'E') || (command[0] == 's' && command[1] == 'e' && command[2] == 'r' && command[3] == 'v' && command[4] == 'e'))
            {
                ADVCOMMAND();
                
                if (commandWord(currentCommand) == 1) {
                    for (i = 0; i< currentCommand.Length; i++){
                        index[i] = currentCommand.TabWord[i];
                    }

                    if(index[0] == 'M' && idxToInt(index) < QueueIntLength(Order))
                    {
                        valid = true;
                    }
                    else
                    {
                        printf("M%d tidak ada pada Order!\n", idxToInt(index));
                    }
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else if(command[0] == 'S' && command[1] == 'K' && command[2] == 'I' && command[3] == 'P')
            {
                if (commandWord(currentCommand) == 1) {
                    valid = true;
                    printf("SKIP 1 PUTARAN\n\n");
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else
            {
                if (commandWord(currentCommand) <= 2) {
                    printf("INPUT SALAH!\n\n");
                }
                else {
                    invalidCommand(&currentCommand);
                }

            }
            
        }

        // Proses Masak
        if(Cook.Count >0){
            sortMapAsc(&Cook);
            int i = 0;
            for(i; i < Cook.Count; i++)
            {
                if(Cook.Elements[i].Value > 0)
                {
                    Cook.Elements[i].Value--;
                }
            }
            
            while (Cook.Elements[0].Value == 0 && Cook.Count > 0)
            {
                printf("Makanan M%d selesai dimasak!\n", wordToInt(Cook.Elements[0].Key));
                Insert(&Serve, Cook.Elements[0].Key, Order.buffer[0].expTime + 1);
                Delete(&Cook, Cook.Elements[0].Key);
            }
        }

        // Proses Serve
        if(Serve.Count > 0)
        {
            int i = 0;
            for(i; i < Serve.Count; i++)
            {
                if(Serve.Elements[i].Value > 0)
                {
                    Serve.Elements[i].Value--;
                }
            }
            while(Serve.Elements[0].Value == 0 && Serve.Count > 0)
            {
                keytype k = Serve.Elements[0].Key;
                Delete(&Serve, k);
                printf("\nMakanan M%d telah expired\n", wordToInt(k));
            }
        }

        // Jika Command = COOK
        if(command[0] == 'C' && command[1] == 'O' && command[2] == 'O' && command[3] == 'K')
        {
            // Insert Order to Cook
            int idx = idxToInt(index);
            Insert(&Cook, intToWord(idx), Order.buffer[idx].cookTime);
            printf("\nBerhasil memasak M%d\n", idx);
        }

        // Jika Command = SERVE
        if(command[0] == 'S' && command[1] == 'E' && command[2] == 'R' && command[3] == 'V' && command[4] == 'E')
        {
            int idx = idxToInt(index);
            if(idx == IDX_HEAD(Order))
            {
                // Mencari makanan di serve dengan ID = idx
                int i = 0;
                ElTypeInt el;
                boolean found = false;
                while(!found)
                {
                    if(idx == wordToInt(Serve.Elements[i].Key))
                    {
                        Delete(&Serve, Serve.Elements[i].Key);
                        dequeue(&Order, &el);
                        saldo += el.price;
                        serveCount += 1;
                        found = true;
                    }
                    i++;
                }

                printf("\nBerhasil mengantar M%d\n", idx);
            }
            else
            {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", idx, IDX_HEAD(Order));
            }
        }

        // Order Baru
        ElTypeInt newOrder;
        newOrder.cookTime = randomNumber(5,1);
        newOrder.expTime = randomNumber(5,1);
        newOrder.price = randomNumber(50000,10000);
        enqueue(&Order, newOrder);

        printf("===========================================================\n");   
    }

    printf("Total saldo yang Anda peroleh : %d\n", saldo);

    (*score) = saldo;

    printf("===========================================================\n");
    printf("                    - DINER DASH OVER -                    \n");
    printf("\n");
}

/* RNG */

/*Mengambil angka random untuk ditebak di rentang 1 sampai 500*/
int randomx()
{
    int a;
    srand(time(NULL));
    a = rand() % (500 + 1 - 1) + 1;
    return a;
}

void rng(int* score){
    int tebakan, x, i;
    i = 0;
    x = randomx();

    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak angka X.\n");
    
    do
    {
        printf("Tebakan: ");
        STARTCOMMAND();
        tebakan = wordToInt(currentCommand);
        
        if (commandWord(currentCommand) == 1) {
            ++i;
            if (tebakan==x)
            {
                printf("Ya, X adalah %d\n", x);
                break;
            }
            else if (tebakan>x)
            {
                printf("Lebih kecil\n");
            }
            else
            {
                printf("Lebih besar\n");
            }
        }
        else {
            invalidCommand(&currentCommand);
        }
    } while(i!=8); /*Memberikan 8 kesempatan menebak*/

    if ((tebakan!=x) && (i==8))
    {
        printf("Kesempatan Anda habis. X yang tepat adalah %d\n", x);
        (*score) = 0;
    }
    else {
        (*score) = 180 - (20*i);
    }
    
    printf("Skor Anda: %d\n", (*score));
}

// CREATE TOWER OF HANOI

void PrintTower(Stack S[3], int n) {
    /*  
    I.S. Sembarang
    F.S. Menampilkan semua Info dari masing-masing elemen dari Stack
    */
    
    int i, j, k;
    Address P;
    InfoType X[3][n];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < n - Count(S[i]); j++) {
            X[i][j] = 0;
        }
        for (P = Top(S[i]); P != Nil; P = Next(P)) {
            X[i][j] = Info(P);
            j++;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            printf(" ");
            if (X[j][i] == 0) {
                for (k = 0; k < n - 1; k++) {
                    printf(" ");
                }

                printf("|");

                for (k = n; k < 2 * n - 1; k++) {
                    printf(" ");
                }
            }
            else {
                for (k = 0; k < n - X[j][i]; k++) {
                    printf(" ");
                }
                for (k = 0; k < 2 * X[j][i] - 1; k++) {
                    printf("*");
                }
                for (k = 0; k < n - X[j][i]; k++) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        printf(" ");
        for (j = 0; j < 2 * n - 1; j++) {
            printf("-");
        }
    }

    printf("\n");

    for (i = 65; i <= 67; i++) {
        printf(" ");
        for (j = 0; j < n - 1; j++) {
            printf(" ");
        }
        printf("%c", i);
        for (j = 0; j < n - 1; j++) {
            printf(" ");
        }
    }
    printf("\n");
}

void towerOfHanoi(int* score) {
    int disk, towerOrigin, towerDestination, step, i, maxScore;
    Stack Tower[3];
    Address P;

    for(int i = 0; i < 3; i++) {
        CreateStack(&Tower[i]);
    }

    printf("===========================================================\n");
    printf("                    - TOWER OF HANOI -                     \n");
    printf("===========================================================\n\n");

    do {
    printf("Masukkan jumlah cakram: ");

    STARTCOMMAND();
    disk = wordToInt(currentCommand);
    } while(disk < 1);

    maxScore = pow(2, disk) - 1;

    if (commandWord(currentCommand) == 1) {
        if (disk > 0) {
            for (i = 0; i < disk; i++) {
                Push(&Tower[0], Allocate(disk - i));
            }
            
            step = 0;

            printf("\n-----------------------------------------------------------\n");
            
            while (Count(Tower[2]) != disk) {
                for (i = 64; i < 67; i++) {
                    printf("\nTower %c: ", i + 1);
                    ViewStack(Tower[i - 64]);
                }

                printf("\n\n");
                PrintTower(Tower, disk);
                printf("\n\n");
                printf("Jumlah langkah: %d\n\n", step);
                printf("Memindahkan cakram dari tower (A - C): ");

                STARTCOMMAND();
                
                if (isWordEqual(currentCommand, stringToWord("A"))) {
                    towerOrigin = 1;
                }
                else if (isWordEqual(currentCommand, stringToWord("B"))) {
                    towerOrigin = 2;
                }
                else if (isWordEqual(currentCommand, stringToWord("C"))) {
                    towerOrigin = 3;
                }
                else {
                    towerOrigin = 0;
                }

                if (commandWord(currentCommand) == 1) {
                    printf("Ke tower (A - C): ");

                    STARTCOMMAND();
                    
                    if (isWordEqual(currentCommand, stringToWord("A"))) {
                        towerDestination = 1;
                    }
                    else if (isWordEqual(currentCommand, stringToWord("B"))) {
                        towerDestination = 2;
                    }
                    else if (isWordEqual(currentCommand, stringToWord("C"))) {
                        towerDestination = 3;
                    }
                    else {
                        towerDestination = 0;
                    }

                    if (commandWord(currentCommand) == 1) {
                        towerOrigin--;
                        towerDestination--;

                        if (towerOrigin >= 0 && towerOrigin <= 2 && towerDestination >= 0 && towerDestination <= 2) {\
                            if (towerOrigin != towerDestination) {
                                if (!IsStackEmpty(Tower[towerOrigin])) {
                                    if (IsStackEmpty(Tower[towerDestination]) || Info(Top(Tower[towerOrigin])) < Info(Top(Tower[towerDestination]))) {
                                        Pop(&Tower[towerOrigin], &P);
                                        Push(&Tower[towerDestination], P);
                                        step++;

                                        printf("\nMemindahkan cakram ke Tower %c\n", towerDestination + 65);

                                        printf("\n-----------------------------------------------------------\n");
                                    } 
                                    else {
                                        printf("\nCakram tidak dapat dipindahkan ke Tower %c karena berukuran lebih besar.\n", towerDestination + 65);
                                    }
                                } 
                                else {
                                    printf("\nTower tidak memiliki cakram.\n");
                                }
                            }
                            else {
                                printf("\nTower asal dan tujuan tidak boleh sama.\n");
                            }
                        } 
                        else {
                            printf("\nTower tidak valid\n");                        }
                        
                    } 
                    else {
                        invalidCommand(&currentCommand);
                    }
                } 
                else {
                    invalidCommand(&currentCommand);
                }
            }

            for (i = 0; i < 3; i++) {
                printf("\nTower %d: ", i + 1);
                ViewStack(Tower[i]);
            }

            printf("\n\n");
            PrintTower(Tower, disk);
            printf("\n\n");
            printf("Jumlah langkah: %d\n", step);
            printf("\nSelamat, Anda berhasil menyelesaikan Tower of Hanoi!\n");

            (*score) = disk + ((maxScore * 5) / step);
            printf("Skor Anda: %d\n", (*score));

            while (!IsStackEmpty(Tower[0])) {
                Pop(&Tower[0], &P);
                DeAllocate(P);
            }

            while (!IsStackEmpty(Tower[1])) {
                Pop(&Tower[1], &P);
                DeAllocate(P);
            }

        } else {
            printf("Jumlah cakram tidak valid\n");
        }
    }
    else {
        invalidCommand(&currentCommand);
    }
}

void printpetak(List snake, List food, List meteor, List obstacle){
    int i =0;
    int j = 0;
    addressldp p;

    for(i=0; i<5; i++){
        if(i == 0){
            printf("-------------------------------\n");
        }
        for(j = 0; j < 5; j++){
            if(j == 0){
                printf("|");
            }
            if(Searchlistdp(snake, j, i) != Nilldp){
                p = Searchlistdp(snake, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
                //p = Nextldp(p);    
            } else if(Searchlistdp(food, j, i) != Nilldp){
                p = Searchlistdp(food, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
            } else if(Searchlistdp(meteor, j, i) != Nilldp){
                p = Searchlistdp(meteor, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
            } else if(Searchlistdp(obstacle, j, i) != Nilldp){
                p = Searchlistdp(obstacle, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s |", Infoldp(p)); 
            } else {
                printf("     |");
            }
        }
        printf("\n");
        printf("-------------------------------\n");
    }

}

int randoms()
{
    int a;
    srand(time(NULL));
    a = (rand() % (5)) + 0;
    return a;
}

void initsnake(List * snake){
    addressldp p;
    addressldp temp;
    int x = 0;
    int i = 0;
    int a;
    int b;

    a = randoms();
    b = randoms();
    
    InsVLastlistdp(snake, "H", a, b);
    p = Firstldp(*snake);
    while(i < 2){
        if(Posisix(p)-1 >= 0){
            InsVLastlistdp(snake, wordToString(intToWord(x+1)), (Posisix(p)-1) % 5, Posisiy(p));
        } else {
            InsVLastlistdp(snake, wordToString(intToWord(x+1)), (Posisix(p)-1 + 5), Posisiy(p));
        }
        temp = p;
        p = Nextldp(p);
        i++;
        x++;
    }
}

void dropfood(List*snake, List* food, List * posPanas, List * obstacle){
    int x;
    int y;

    x = randoms();
    y = randoms();

    if(!IsEmptylistdp(*obstacle)){
        if(!IsEmptylistdp(*posPanas)){
            while(Searchlistdp((*snake), x, y) != Nilldp || Searchlistdp((*posPanas), x, y) != Nilldp || Searchlistdp((*obstacle), x, y) != Nilldp){
                x = randoms();
                y = randoms();
            }
        } else {
            while(Searchlistdp((*snake), x, y) != Nilldp  || Searchlistdp((*obstacle), x, y) != Nilldp){
                x = randoms();
                y = randoms();
            }
        }
    } else {
        while(Searchlistdp((*snake), x, y) != Nilldp){
            x = randoms();
            y = randoms();
        }
    }
    //printf("food : %d %d\n", x, y);
    InsVLastlistdp(food, "O", x, y);
}

void dropmeteor(List* food, List* obstacle, List * meteor){
    int r;
    int s;

    r = randoms();
    s = randoms();

    while(Searchlistdp((*food), r, s) != Nilldp || Searchlistdp((*obstacle), r, s) != Nilldp){
        r = randoms();
        s = randoms();
    }
    //printf("meteor : %d %d\n", x, y);
    InsVLastlistdp(meteor, "M", r, s);
}

void dropobs(List * snake, List * food, List * obstacle){
    int a;
    int b;

    a = randoms();
    b = randoms();
    while(Searchlistdp((*snake), a, b) != Nilldp || Searchlistdp((*food), a, b) != Nilldp){
        a = randoms();
        b = randoms();
    }
    //printf("%d %d\n", a, b);
    InsVLastlistdp(obstacle, "###", a, b);    
}

void makan(List * snake, List * food, List * obstacle, boolean * menang){
    elmntype tempInfoldp;
    int tempx, tempy;

    if((Posisix(Firstldp(*food)) == Posisix(Firstldp(*snake))) && (Posisiy(Firstldp(*food)) == Posisiy(Firstldp(*snake)))) {
        DelVLastlistdp(food, &tempInfoldp, &tempx, &tempy);

        if(Posisix(Lastldp(*snake)) != 0){
            if(Searchlistdp((*snake), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake))) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake)));
            } else if(Posisiy(Lastldp(*snake)) != 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 +5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1+5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5);
            } else if(Posisiy(Lastldp(*snake)) != 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1);
            } else if(Posisiy(Lastldp(*snake)) == 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1-5);
            } else if(Searchlistdp((*snake), (Posisix(Lastldp(*snake))+1)%5, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obstacle), (Posisix(Lastldp(*snake))+1)%5, Posisiy(Lastldp(*snake))) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), (Posisix(Lastldp(*snake)) + 1)%5, Posisiy(Lastldp(*snake)));
            }
        } else if(Posisix(Lastldp(*snake)) == 0){
            if(Searchlistdp((*snake), Posisix(Lastldp(*snake))-1 + 5, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)) -1 + 5, Posisiy(Lastldp(*snake))) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake))-1 + 5, Posisiy(Lastldp(*snake)));
            } else if(Posisiy(Lastldp(*snake)) != 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5);
            } else if(Posisiy(Lastldp(*snake)) != 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake)) + 1);
            } else if(Posisiy(Lastldp(*snake)) == 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp && Searchlistdp((*obstacle), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake)) + 1 - 5);
            } else if(Searchlistdp((*snake), (Posisix(Lastldp(*snake))+1)%5, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obstacle), (Posisix(Lastldp(*snake))+1) % 5, Posisiy(Lastldp(*snake))) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), (Posisix(Lastldp(*snake)) + 1) % 5, Posisiy(Lastldp(*snake)));
            }
        } else {
            printf("Ekor snake tidak dapat di-spawn ke arah manapun :<\n");
            *menang = true;
        }
    }
}

void hit(List * snake, List * meteor, location * temp){
    addressldp p;
    int tempx, tempy;

    if(Searchlistdp(*snake, Posisix(Firstldp(*meteor)), Posisiy(Firstldp(*meteor))) == Nilldp){
        if((*temp).x != -1){
            p = Searchlistdp(*snake, (*temp).x, (*temp).y);

            while(p != Nilldp){
                Infoldp(p) = wordToString(intToWord(wordToInt(stringToWord(Infoldp(p))) - 1));
                p = Nextldp(p);
            }
        }    
    }
}

int lengthsnake(List snake){
    int count = 0;
    while (Firstldp(snake) != Nilldp) {
        count++;
        Firstldp(snake) = Nextldp(Firstldp(snake));
    }
    return count;
}

void belok(char x, List *s, List * posPanas, List * obstacle, boolean * gagal, boolean * menang){
    addressldp p;
    addressldp temp;
    int i = 0;
    int tempx, tempy;

    p = Lastldp(*s);
    printf("\n");

    if(Searchlistdp((*s), (Posisix(Firstldp(*s))-1+5) % 5, Posisiy(Firstldp(*s))) != Nilldp && Searchlistdp((*s), (Posisix(Firstldp(*s))+1) % 5, Posisiy(Firstldp(*s))) != Nilldp && Searchlistdp((*s), (Posisix(Firstldp(*s))-1+5) % 5, Posisiy(Firstldp(*s))) != Nilldp && Searchlistdp((*s), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))-1+5) % 5) != Nilldp && Searchlistdp((*s), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1) % 5) != Nilldp) {
        printf("Kamu sudah tidak dapat bergerak ke arah manapun:(\n");
        *menang = true;
    }
    else {
        if((x) == 'w'){
            if(Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            // } else if ((Posisiy(Firstldp(*s)) == 0)) {
            //     printf("Anda menabrak dinding :<\n");
            //     *gagal = true;
            //     *menang = true;
            } else if(Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            } else if (Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            } else if (Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            } else if (Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            } else if (Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5 ) != Nilldp) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            } else {
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != Firstldp(*s)){
                    Posisi(p) = Posisi(Prevldp(p));
                    p = Prevldp(p);
                }
                if(Posisiy(Firstldp(*s)) != 0){
                    Posisiy(Firstldp(*s)) -= 1;
                    *gagal = false;
                } else {
                    Posisiy(Firstldp(*s)) = Posisiy(Firstldp(*s)) - 1 + 5;
                    *gagal = false;
                }    
            }
        }
        else if ((x) == 's') {
            if (Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            } else if (Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            }
            // else if ((Posisiy(Firstldp(*s)) == 4)) {
            //     printf("Anda menabrak dinding :<\n");
            //     *gagal = true;
            //     *menang = true;
            // }
            else if (Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            } else if (Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            } else if(Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp){
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            } else if(Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*s), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp){
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            }
            else {        
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != Firstldp(*s)){
                    Posisi(p) = Posisi(Prevldp(p));
                    p = Prevldp(p);
                }
                if(Posisiy(Firstldp(*s)) != 4){    
                    Posisiy(Firstldp(*s)) += 1;
                    *gagal = false;
                } else {
                    Posisiy(Firstldp(*s)) = (Posisiy(Firstldp(*s)) + 1) % 5;
                    *gagal = false;
                }    
            }
        }
        else if ((x) == 'a') {
            if (Posisix(Firstldp(*s)) != 0 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)) -1 , Posisiy(Firstldp(*s))) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            } else if (Posisix(Firstldp(*s)) == 0 && Searchlistdp((*posPanas), (Posisix(Firstldp(*s)) -1) + 5 , Posisiy(Firstldp(*s))) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            }
            // else if ((Posisix(Firstldp(*s)) == 0)) {
            //     printf("Anda menabrak dinding :<\n");
            //     *gagal = true;
            //     *menang = true;
            // }
            else if (Posisix(Firstldp(*s)) != 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)) -1 , Posisiy(Firstldp(*s))) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            } else if (Posisix(Firstldp(*s)) == 0 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)) -1 + 5, Posisiy(Firstldp(*s))) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            } else if(Posisix(Firstldp(*s)) != 0 && Searchlistdp((*s), Posisix(Firstldp(*s))-1, Posisiy(Firstldp(*s))) != Nilldp){
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            } else if(Posisix(Firstldp(*s)) == 0 && Searchlistdp((*s), Posisix(Firstldp(*s))-1 + 5, Posisiy(Firstldp(*s))) != Nilldp){
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            }
            else {
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != Firstldp(*s)){
                    Posisi(p) = Posisi(Prevldp(p));
                    p = Prevldp(p);
                }
                if(Posisix(Firstldp(*s)) != 0){ 
                    Posisix(Firstldp(*s)) -= 1;
                    *gagal = false;
                } else {
                    Posisix(Firstldp(*s)) = Posisix(Firstldp(*s)) - 1 + 5;
                    *gagal = false;
                }
            }
        }
        else if ((x) == 'd') {
            if (Posisix(Firstldp(*s)) != 4 && Searchlistdp((*posPanas), Posisix(Firstldp(*s)) + 1, Posisiy(Firstldp(*s))) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            } else if (Posisix(Firstldp(*s)) == 4 && Searchlistdp((*posPanas), (Posisix(Firstldp(*s)) + 1) % 5, Posisiy(Firstldp(*s))) != Nilldp){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                *gagal = true;
            }
            // else if ((Posisix(Firstldp(*s)) == 4)) {
            //     printf("Anda menabrak dinding :<\n");
            //     *gagal = true;
            //     *menang = true;
            // }
            else if (Posisix(Firstldp(*s)) != 4 && Searchlistdp((*obstacle), Posisix(Firstldp(*s)) + 1, Posisiy(Firstldp(*s))) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            }else if (Posisix(Firstldp(*s)) == 4 && Searchlistdp((*obstacle), (Posisix(Firstldp(*s)) + 1) %5, Posisiy(Firstldp(*s))) != Nilldp) {
                printf("Anda menabrak obstacle :<\n");
                *gagal = true;
                *menang = true;
            } else if(Posisix(Firstldp(*s)) != 4 && Searchlistdp((*s), Posisix(Firstldp(*s))+1, Posisiy(Firstldp(*s))) != Nilldp){
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            } else if(Posisix(Firstldp(*s)) == 4 && Searchlistdp((*s), (Posisix(Firstldp(*s))+1)%5, Posisiy(Firstldp(*s))) != Nilldp){
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                *gagal = true;
            }
            else {
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                while(p != Firstldp(*s)){
                    Posisi(p) = Posisi(Prevldp(p));
                    p = Prevldp(p);
                }
                if(Posisix(Firstldp(*s)) != 4){    
                    Posisix(Firstldp(*s)) += 1;
                    *gagal = false;
                } else {
                    Posisix(Firstldp(*s)) = (Posisix(Firstldp(*s)) + 1) %5;
                    *gagal = false;
                }    
            }
        }
        else {
            printf("Arah tidak dikenali") ;
        }
    }
}

void snakeOnMeteor(int * score){

    List snake;
    List food;
    List meteor;
    List posPanas;
    List obstacle;
    
    char command;
    boolean validasicommand = false;
    boolean menang = false;
    boolean donef = false;
    boolean gagal = false;
    boolean kenakepala = false;
    int test = 0;
    int turn = 1;
    //location posPanas;

    CreateEmptylistdp(&food);
    CreateEmptylistdp(&snake);
    CreateEmptylistdp(&meteor);
    CreateEmptylistdp(&posPanas);
    CreateEmptylistdp(&obstacle);
    initsnake(&snake);

    printf("\n                 Selamat datang di snake on meteor!\n");
    printf(" .+:*+.+:*+.+:*+. P A N D U A N  S I N G K A T  G A M E .+*:+.+*:+.+*:+. \n");
    printf("o   : makanan yang harus dicapai agar snake bertambah panjang\n");
    printf("H   : Head dari snake yang akan diikuti oleh badannya (1, 2, dst.)\n");
    printf("M   : meteor yang akan muncul secara acak dan menyerang snake\n");
    printf("### : obstacle yang harus dihindari, apabila menabraknya snake akan mati\n\n");

    printf("\nMengenerate peta, snake dan makanan\n");
    printf("\nBerhasil digenerate!\n");

    printf("\n----------------------------------\n\n");

    dropfood(&snake, &food, &posPanas, &obstacle);
    donef = true;
    dropobs(&snake, &food, &obstacle);
    printpetak(snake, food, meteor, obstacle);
    while (!menang) {
        if(!donef){ // dropfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
            dropfood(&snake, &food, &posPanas, &obstacle);
            
            donef = true;
        }
        printf("\nTURN %d\n", turn);
        printf("Silahkan masukkan command anda: ") ;
        
        STARTCOMMAND();
        if(commandWord(currentCommand) == 1 ){  
            if (currentCommand.Length != 1 || (currentCommand.TabWord[0] != 'a' && currentCommand.TabWord[0] != 'w' && currentCommand.TabWord[0] != 'd' && currentCommand.TabWord[0] != 's')) {
                printf("\n");
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n\n") ;
            }
            else {
                command = currentCommand.TabWord[0];
                validasicommand = true;
                belok(command, &snake, &posPanas, &obstacle, &gagal, &menang);
                
                if (!menang) {
                    if(gagal == true ){
                        printf("Silahkan masukkan command lainnya\n");
                    } else {
                        elmntype tempInfoldp;
                        int tempx, tempy;

                        if(!IsEmptylistdp(meteor) && !gagal){
                            DelVLastlistdp(&meteor, &tempInfoldp, &tempx, &tempy);
                        }
                        if((Posisix(Firstldp(food)) == Posisix(Firstldp(snake))) && (Posisiy(Firstldp(food)) == Posisiy(Firstldp(snake))) && !gagal) {
                            makan(&snake, &food, &obstacle, &menang);
                            donef = false;
                           
                        }
                        if(!donef){ // dropfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
                            dropfood(&snake, &food, &posPanas, &obstacle);
                            
                            donef = true;
                        }
                        
                        dropmeteor(&food, &obstacle, &meteor);
                        
                        if(Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor))) != Nilldp){
                            //kondisional search posisinya meteor sama kaya posisinya snakenya apa engga
                            if(Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor))) == Firstldp(snake)){
                                elmntype temphead;
                                int headx;
                                int heady;
                                DelVFirstlistdp(&snake, &temphead, &headx, &heady);
                                menang = true;
                                kenakepala = true;
                                printpetak(snake, food, meteor, obstacle);
                                printf("Kepala snake terkena meteor :<\n");
                            } else {
                                elmntype tempbadan;
                                location postemp;
                                addressldp p;

                                postemp.x = -1;
                                postemp.y = -1;
                                p = Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                                if(Nextldp(p) != Nilldp){
                                    postemp = Posisi(Nextldp(p));
                                }
                                DelPlistdp(&snake, tempbadan, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                                printpetak(snake, food, meteor, obstacle);
                                hit(&snake, &meteor, &postemp);
                                printf("Anda terkena meteor\n");
                                printf("Berikut merupakan peta permainan sekarang:\n");
                                printpetak(snake, food, meteor, obstacle);
                                printf("Silahkan lanjutkan permainan\n");
                                
                                InsVLastlistdp(&posPanas, wordToString(intToWord(turn)), Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                            }
                        } else {
                
                            printpetak(snake, food, meteor, obstacle);
                            printf("Anda beruntung tidak terkena meteor! ");
                            printf("Silahkan lanjutkan permainan\n");
                        }    
                        
                        turn++;
                        if(!IsEmptylistdp(posPanas)){
                            if(wordToInt(stringToWord(Infoldp(Firstldp(posPanas)))) + 2 == turn ){
                                elmntype temppanas;
                                int px, py;
                                DelVFirstlistdp(&posPanas, &temppanas, &px, &py);
                            }
                        }
                    }
                }
            }
        } else {
            printf("\n");                                                   
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        } 
    }
    int length, poin;
    length = lengthsnake(snake);
    poin = length*2;
    
    printf("Game berakhir!\n");  
    printf("Skor: %d", poin);
    *score = poin;
}

void wordList(ArrayDin* listOfWord) {
    int jumlah, i;

    startWFile("data/DaftarKataHangman.txt");

    jumlah = wordToInt(currentWord);

    for (i = 0 ; i < jumlah ; i++) {
         advNewlineFile();
         InsertLast(listOfWord, currentWord);
     }
}

Word chooseWord(ArrayDin listOfWord) {
    int i, random;

    random = rand() % listOfWord.Neff;

    return Get(listOfWord, random);
}

boolean isAlreadyGuessed(ArrayDin listOfGuess, Word guess) {
    int i;

    for (i = 0 ; i < listOfGuess.Neff ; i++) {
        if (isWordEqual(lowerWord(Get(listOfGuess, i)), lowerWord(guess))) {
            return true;
        }
    }

    return false;
}

void printGuess(ArrayDin listOfGuess) {
    int i;

    for (i = 0 ; i < listOfGuess.Neff ; i++) {
        printf("%c", Get(listOfGuess, i).TabWord[0]);
    }
}

boolean win(Word word, ArrayDin listOfGuess) {
    int i, j, count = 0;

    for (i = 0 ; i < word.Length ; i++) {
        for (j = 0 ; j < listOfGuess.Neff ; j++) {
            if (isWordEqual(upperWord(charToWord(word.TabWord[i])), upperWord(charToWord(Get(listOfGuess, j).TabWord[0])))) {
                count++;
            }
        }
    }

    if (count == word.Length) {
        return true;
    } else {
        return false;
    }
}

void addDictionary(ArrayDin* listOfWord) {
    FILE *file;
    boolean found = false;
    int i = 0;

    printf("\nMasukkan kata baru yang ingin ditambahkan: ");
    STARTGAMENAME();

    while (i < Length(*listOfWord) && !found) {
        if (isWordEqual(lowerWord(currentCommand), lowerWord(Get(*listOfWord, i)))) {
            found = true;
        }
        else {
            i++;
        }
    }

    if (found) {
        printf("Kata sudah ada di dalam daftar kata.\n");
    }
    else {
        InsertLast(listOfWord, upperWord(currentCommand));
        
        file = fopen("data/DaftarKataHangman.txt", "w");
        fprintf(file, "%d\n", Length(*listOfWord));
        for (i = 0 ; i < Length(*listOfWord) ; i++) {
            fprintf(file, "%s\n", wordToString(Get(*listOfWord, i)));
        }
        fclose(file);
        printf("Kata berhasil ditambahkan.\n");
    }
}

void welcomeHangman() // baru bisa di jalanin kalo NMax di mesinkata diganti jadi 100
/* print welcoming page bnmo */
{
/* ALGORITMA */
    int j, delay;
    startWFile("data/hangman.txt");

    while(!finish) {
        printf("%s\n", currentWord.TabWord);
        for(j = 0; j < 100000000; j++) { // buat delay prosesnya
                delay = j;
            }
        advNewlineFile();
    }
}

void hangman(int* totalscore) {
    ArrayDin listOfWord, listOfGuess;
    Word wordToGuess, guess;
    int i, j, chance, score, lengthGuess, lengthWord;
    boolean found, valid, flag;

    flag = false;

    listOfWord = MakeArrayDin();
    wordList(&listOfWord);
    welcomeHangman();
    printf("Selamat datang di game Hangman!\n");

    while (!flag) {
        printf("\nSilakan pilih mode berikut:\n1. Menambah dictionary\n2. Bermain\n");
        printf("\nMasukkan pilihan: ");
        STARTCOMMAND();

        if (commandWord(currentCommand) == 1) {
            if (isWordEqual(lowerWord(currentCommand), lowerWord(charToWord('1')))) {
                addDictionary(&listOfWord);
            }
            else if (isWordEqual(lowerWord(currentCommand), lowerWord(charToWord('2')))) {
                flag = true;
                chance = 10;
                score = 0;
                (*totalscore) = 0;

                listOfWord = MakeArrayDin();
                listOfGuess = MakeArrayDin();

                wordList(&listOfWord);

                wordToGuess = chooseWord(listOfWord);
                lengthWord = wordToGuess.Length;
                lengthGuess = 0;

                do {
                    printf("\nTebakan sebelumnya : -\n");
                    printf("Kata:");
                    for (i = 0 ; i < wordToGuess.Length ; i++) {
                        printf(" _");
                    }
                    printf("\n");
                    printf("Kesempatan: %d", chance);
                    printf("\nMasukkan tebakan: ");
                    STARTCOMMAND();

                    if (commandWord(currentCommand) == 1 && currentCommand.Length == 1) {
                        if (('a' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'z') || ('A' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'Z')) {
                            guess = charToWord(currentCommand.TabWord[0]);

                            while (!win(wordToGuess, listOfGuess) && chance > 0) {
                                
                                    if (isAlreadyGuessed(listOfGuess, guess)) {
                                        printf("Tebakan sudah pernah dilakukan!\n");
                                    } else {
                                        InsertLast(&listOfGuess, lowerWord(guess));
                                        
                                        found = false;

                                        for (i = 0 ; i < wordToGuess.Length ; i++) {
                                            if (isWordEqual(upperWord(charToWord(wordToGuess.TabWord[i])), upperWord(charToWord(guess.TabWord[0])))) {
                                                found = true;
                                            }
                                        }

                                        if(!found) {
                                            chance--;
                                        }
                                    }

                                valid = false;

                                while (!valid && !win(wordToGuess, listOfGuess) && chance > 0) {
                                    printf("\nTebakan sebelumnya : ");
                                    printGuess(listOfGuess);
                                    printf("\n");
                                    printf("Kata:");
                                    for (i = 0 ; i < wordToGuess.Length ; i++) {
                                        found = false;
                                        for (j = 0 ; j < listOfGuess.Neff ; j++) {
                                            if (isWordEqual(upperWord(charToWord(wordToGuess.TabWord[i])), upperWord(charToWord(Get(listOfGuess, j).TabWord[0])))) {
                                                found = true;
                                            }
                                        }

                                        if (found) {
                                            printf(" %c", wordToGuess.TabWord[i]);
                                        } else {
                                            printf(" _");
                                        }
                                    }
                                    printf("\n");
                                    printf("Kesempatan: %d\n", chance);
                                    printf("Masukkan tebakan: ");

                                    STARTCOMMAND();

                                    if (commandWord(currentCommand) == 1 && currentCommand.Length == 1) {
                                        if (('a' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'z') || ('A' <= currentCommand.TabWord[0] && currentCommand.TabWord[0] <= 'Z')) {
                                            guess = charToWord(currentCommand.TabWord[0]);
                                            valid = true;
                                        }
                                        else {
                                            printf("Masukkan salah! Masukan harus berupa alfabet.\n");
                                        }
                                    } else {
                                        printf("Masukkan salah! Masukan tidak boleh lebih dari satu karakter.\n");
                                    }
                                }
                            }

                            if (win(wordToGuess, listOfGuess)) {
                                score = lengthWord;
                                (*totalscore) += score;
                                printf("\nBerhasil menebak kata %s! Kamu mendapatkan %d poin!\n", wordToString(wordToGuess), score);
                            } else {
                                printf("\nKamu gagal menebak kata %s!\n", wordToString(wordToGuess));
                            }
                        }
                        else {
                            printf("Masukkan salah! Masukan harus berupa alfabet.\n");
                        }
                    } else {
                        printf("Masukkan salah! Masukan tidak boleh lebih dari satu karakter.\n");
                    }

                    if (win(wordToGuess, listOfGuess) && chance > 0) {
                            listOfWord = MakeArrayDin();
                            listOfGuess = MakeArrayDin();

                            wordList(&listOfWord);

                            wordToGuess = chooseWord(listOfWord);
                            lengthWord = wordToGuess.Length;
                            lengthGuess = 0;
                    }
                } while (chance > 0);
            }
            else {
                printf("Pilihan tidak valid.\n");
            }
        }
        else {
            printf("Masukkan salah. Silakan masukkan kembali.\n");
        }
    }

    printf("\nKesempatan habis! Total poin yang kamu kumpulkan adalah %d ~(^.^)~ !\n", (*totalscore));
}

// gcc main.c source/command/console.c source/ADT/queue/queue.c source/ADT/queuedinerdash/queue.c source/ADT/stack/stack.c source/ADT/map/map.c source/ADT/mesinkarakter/mesinkarakter.c source/ADT/mesinkata/mesinkata.c source/ADT/array/arraydin.c source/ADT/array/arraymap.c source/ADT/listdp/listdp.c -o trial