#include "../ADT/listdp/listdp.h"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../ADT/mesinkata/mesinkata.h"

void printpetak(List snake, List food, List meteor);
void initsnake(List * snake);
void dropfood(List * snake, List * food, List * posPanas);
void dropmeteor(List * food, List * meteor);
void belok(char x, List *s, List * posPanas, boolean * gagal);
void hit(List * snake, List * meteor);