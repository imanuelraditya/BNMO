#include "../ADT/listdp/listdp.h"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../ADT/mesinkata/mesinkata.h"

void printpetak(List snake, List food, List meteor, List obstacle);
/* mengeluarkan tampilan permainan snake on meteor */

void initsnake(List * snake);
/* inisiasi awal snake yaitu terdiri dari H, 1, dan 2, beserta dengan randomize letak awal */

void dropfood(List * snake, List * food, List * posPanas, List * obstacle);
/* meletakkan makanan pada game secara acak */

void dropmeteor(List * food, List * obstacle, List * meteor);
/* meletakkan meteor pada game secara acak */

void makan(List * snake, List * food, List * obstacle, boolean * menang);
/* bertambah panjangnya ekor snake setelah mengalami proses memakan sebuah food */

void belok(char x, List *s, List * posPanas, List * obstacle, boolean * gagal, boolean * menang);
/* pembelokan head yang diikuti badan - badan snake */

void hit(List * snake, List * meteor, location * temp);
/* snake terkena meteor dan badan akan terputus */

void dropobs(List * snake, List * food, List * obstacle);
/* meletakkan obstacle secara acak pada game pada awal permainan */

int lengthsnake(List snake);
/* menghitung panjang snake */

void snakeOnMeteor(int * score);
/* permainan Snake On Meteor */