#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

/* LIST FUNGSI PROSEDUR COMMAND */

// CREATE GAME

void CreateGame (ArrayDin* listGame) {
    boolean found;
    int i;

    found = false;
    i = 0;

    printf("Masukkan nama game yang ingin ditambahkan: ");
    STARTGAMENAME();

    while (i < Length(*listGame) && !found) {
        if (isWordEqual(currentCommand, (*listGame).A[i])) {
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
        printf("Game berhasil ditambahkan.\n");
    }
}

// DELETE GAME

void deleteGame (ArrayDin* listGame, Queue Q) 
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
                DeleteAt(listGame, (nomor-1));
                printf("Game berhasil dihapus.\n");
            }
        }
    }
    else {
        invalidCommand(&currentCommand);
    }
}

// HELP

void help() {
    printf("================================================================\n");
    printf("  +:*+.+:*+.+:*+.+:*+.  H E L P  M E N U .+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("                daftar dan cara kerja command:\n");
    printf("1. LIST GAME     : menampilkan daftar game yang disediakan\n");
    printf("2. QUEUE GAME    : mendaftarkan game ke dalam antrian game pribadi\n");
    printf("3. PLAY GAME     : memainkan sebuah game\n");
    printf("4. SKIP GAME <n> : melewatkan game sebanyak yang diinginkan\n");
    printf("5. CREATE GAME   : menambahkan game baru pada daftar game\n");
    printf("6. DELETE GAME   : menghapus sebuah game dari daftar game\n");
    printf("7. QUIT          : keluar dari program game ^^\n");
    printf("8. SAVE <filename.txt> : menyimpan state game pemain saat ini\n");
    printf("================================================================\n");
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

void load(Word filename, ArrayDin *array) {
    /* LOAD merupakan salah satu command yang dimasukkan pertama kali oleh pemain ke BNMO. 
    Memiliki satu argumen yaitu filename yang merepresentasikan suatu save file yang ingin dibuka. 
    Setelah menekan Enter, akan dibaca save file <filename> yang berisi list game yang dapat dimainkan */

    char* maindir;
    int count, i;

    maindir = "data/";
    i = 0;

    startWFile(wordToString(concatWord(stringToWord(maindir), filename)));

    count = wordToInt(currentWord);

    for (i = 0; i < count; i++) {
        advNewlineFile();
        InsertLast(array, currentWord);
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

void randomScore(Word game) {
    /* I.S. array terdefinisi */
    /* F.S. Menampilkan score random */
    /* Proses: Menampilkan score random */
    
    /* KAMUS LOKAL */
        int i, j, delay;

    /* ALGORITMA */
        printf("LOADNG %s", wordToString(game));

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
        
        printf("Score: %d\n", rand() % 100);
}

void playGame (Queue* queueGame) 
{
    Word play ;
    ListQueueGame (*queueGame) ; 

    printf ("\n") ;

    if (!IsQEmpty (*queueGame)) {
        Del(queueGame, &play) ; 

        if (isWordEqual(play, stringToWord("DINER DASH"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            dinerdash() ;
        }
        else if (isWordEqual(play, stringToWord("RNG"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            rng() ;
        }
        else if (isWordEqual(play, stringToWord("TOWER OF HANOI"))) {
            printf ("Loading %s . . .\n\n", wordToString(play)) ;
            towerOfHanoi();
        }
        else if (isWordEqual(play, stringToWord("DINOSAUR IN EARTH")) || isWordEqual(play, stringToWord("RISEWOMAN")) || isWordEqual(play, stringToWord("EIFFEL TOWER"))) {
            printf ("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", wordToString(play)) ;
        }
        
        else {
            randomScore(play);
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
    printf("Anda keluar dari game BNMO\nBye bye ...\n");
    exit(0);
}

// SAVE <filename.txt>

void save(Word filename, ArrayDin* listGame) {
    FILE *fpointer;
    char* maindir;
    int i;

    maindir = "data/";

    fpointer = fopen(wordToString(concatWord(stringToWord(maindir), filename)), "w");

    if (fpointer == NULL) {
        printf("Tidak ada nama file yang tercantum. Silakan coba lagi.\n");
    }
    else {
        fprintf(fpointer, "%d\n", Length(*listGame));
        for (i = 0; i < Length(*listGame); i++)
        {
            fprintf(fpointer, "%s\n", wordToString(Get(*listGame, i)));
        }
        fclose(fpointer);
    }

    printf("Save file berhasil disimpan\n");
}

// SKIP GAME <n>

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
            playGame(Q);
        }
    }
}

// START GAME

void startGame(ArrayDin * arr)
/* membuka dan membaca file konfigurasi awal */
/* I.S. sembarang (tidak dapat menggunakan game)
   F.S. game sudah siap dimainkan
        List Game yang dapat dimainkan sudah tersedia yaitu dengan konfigurasi awal
        command - command lain dapat dijalankan */
{
/* KAMUS LOKAL */
    int jumlah, i; // jumlah game yang tersedia, untuk looping banyak membaca 
    
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
            printf("M%d\t|\t%d\n", C.Elements[i].Key, C.Elements[i].Value);
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
            printf("M%d\t|\t%d\n", C.Elements[i].Key, C.Elements[i].Value);
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

void sortMap(Map *Map){
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

void dinerdash(){
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
            sortMap(&Cook);
            int i = 0;
            for(i; i < Cook.Count; i++)
            {
                if(Cook.Elements[i].Value > 0)
                {
                    Cook.Elements[i].Value--;
                }
            }
            while(Cook.Elements[0].Value == 0 && Cook.Count > 0)
            {
                keytype k = Cook.Elements[0].Key;
                valuetype v = Order.buffer[k].expTime + 1;
                Insert(&Serve, k, v);
                Delete(&Cook, k);
                printf("\nMakanan M%d telah selesai dimasak\n", k);
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
                printf("\nMakanan M%d telah expired\n", k);
            }
        }

        // Jika Command = COOK
        if(command[0] == 'C' && command[1] == 'O' && command[2] == 'O' && command[3] == 'K')
        {
            // Insert Order to Cook
            int idx = idxToInt(index);
            Insert(&Cook, idx, Order.buffer[idx].cookTime);
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
                    if(idx == Serve.Elements[i].Key)
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

void rng(){
    int tebakan, x, i;
    i = 0;
    x = randomx();

    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak angka X.\n");
    printf("Tebakan: ");
    scanf("%d", &tebakan);

    do 
    {
        ++i; /*Memberikan 8 kesempatan menebak*/
        if (tebakan==x)
        {
            printf("Ya, X adalah %d\n", x);
            break;
        }
        else if (tebakan>x)
        {
            printf("Lebih kecil\n");
            printf("Tebakan: ");
            scanf("%d", &tebakan);
        }
        else
        {
            printf("Lebih besar\n");
            printf("Tebakan: ");
            scanf("%d", &tebakan);
        }
    } while(i!=7);

    if (i==7)
    {
        printf("Kesempatan Anda habis. X yang tepat adalah %d\n", x);
    }
}

// CREATE TOWER OF HANOI

void displayTower(Stack A, Stack B, Stack C) {
    printf("Tower A: ");
    ViewStack(A);

    printf("Tower B: ");
    ViewStack(B);

    printf("Tower C: ");
    ViewStack(C);
}

boolean checkWin(Stack A, Stack B, Stack C) {
    Address P ;
    int i;
    boolean win;

    P = Top(C);
    win = true;
    i = 1;

    while (P != Nil && win) {
        if (Info(P) != i) {
            win = false;
        }
        P = Next(P);
        i++;
    }

    return win;
}

void towerOfHanoi()
{
    Stack A, B, C;
    int i, disc, score;
    Word towerOrigin, towerDestination;
    InfoType x;

    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);

    i = 0;

    STARTCOMMAND();

    if (commandWord(currentCommand) == 1) {
        disc = wordToInt(currentCommand);

        for (i = disc; i >= 1; i--) {
            x = i;
            Push(&A, x);
        }

        printf("TOWER OF HANOI\n\n");

        while ((i <= disc * 2) && !checkWin(A, B, C)) {
            displayTower(A, B, C);

            printf("Pindahkan disk dari tower: ");
            
            STARTCOMMAND();

            if (commandWord(currentCommand) == 1) {
                towerOrigin = currentCommand;

                printf("Pindahkan disk menuju tower: ");

                STARTCOMMAND();

                if (commandWord(currentCommand) == 1) {
                    towerDestination = currentCommand;

                    if (isWordEqual(towerOrigin, stringToWord("A"))) {
                        if (isWordEqual(towerDestination, stringToWord("B"))) {
                            Pop(&A, &x);
                            Push(&B, x);
                        } else if (isWordEqual(towerDestination, stringToWord("C"))) {
                            Pop(&A, &x);
                            Push(&C, x);
                        } else {
                            printf("Tower tujuan tidak valid\n");
                        }
                    }
                    else if (isWordEqual(towerOrigin, stringToWord("B"))) {
                        if (isWordEqual(towerDestination, stringToWord("A"))) {
                            Pop(&B, &x);
                            Push(&A, x);
                        } else if (isWordEqual(towerDestination, stringToWord("C"))) {
                            Pop(&B, &x);
                            Push(&C, x);
                        } else {
                            printf("Tower tujuan tidak valid\n");
                        }
                    }
                    else if (isWordEqual(towerOrigin, stringToWord("C"))) {
                        if (isWordEqual(towerDestination, stringToWord("A"))) {
                            Pop(&C, &x);
                            Push(&A, x);
                        } else if (isWordEqual(towerDestination, stringToWord("B"))) {
                            Pop(&C, &x);
                            Push(&B, x);
                        } else {
                            printf("Tower tujuan tidak valid\n");
                        }
                    }
                    else {
                        printf("Tower asal tidak valid\n");
                    }
                }
                else {
                    invalidCommand(&currentCommand);
                }
            }
            else {
                invalidCommand(&currentCommand);
            }
        }

    }
}
